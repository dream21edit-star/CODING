let blockSize = 25;
let total_row = 17;
let total_col = 17;
let board;
let context;

let snakeX;
let snakeY;
let speedX;
let speedY;

let snakeBody = [];
let foodX;
let foodY;
let foodTimer = 0;

window.onload = function() {
    // SET BOARD HEIGHT AND WIDTH
    board = document.getElementById("board");
    board.height = total_row * blockSize;
    board.width = total_col * blockSize;
    context = board.getContext("2d");

    // Initialize game state
    resetGame();
    
    document.addEventListener("keyup", changeDirection);
    // SET SNAKE SPEED
    setInterval(update, 1000/10);
}

// Fonction pour réinitialiser le jeu automatiquement (comme en Python)
function resetGame() {
    snakeX = blockSize * 5;
    snakeY = blockSize * 5;
    speedX = 0;
    speedY = 0;
    snakeBody = [];
    foodTimer = 0;
    placeFood();
    
}

function update() {
    // BACKGROUND OF A GAME
    if(speedX !== 0 || speedY !==0) {
    foodTimer++;
    if(foodTimer >= 50) {
        placeFood();
        foodTimer = 0;
    }
    }
    context.fillStyle = "green";
    context.fillRect(0, 0, board.width, board.height);

    // SET FOOD COLOR AND POSITION
    context.fillStyle = "yellow";
    context.fillRect(foodX, foodY, blockSize, blockSize);

    if(snakeX == foodX && snakeY == foodY) {
        snakeBody.push([foodX, foodY]);
        foodTimer = 0;
        placeFood();
        
    }

    // BODY OF SNAKE WILL GROW
    for(let i = snakeBody.length-1; i>0; i--) {
        // (it will store previous part of snake to the current part)
        snakeBody[i] = snakeBody[i-1];
    }
    if(snakeBody.length) {
        snakeBody[0] = [snakeX, snakeY];
    }

    snakeX += speedX * blockSize; // UPDATING SNAKE POS
    snakeY += speedY * blockSize; // UPDATING SNAKE POS

    // OUT OF BOUND CONDITION -> Reset au lieu de Game Over
    if(snakeX < 0 || snakeX >= total_col*blockSize || snakeY < 0 || snakeY >= total_row*blockSize) {
        resetGame();
        
        return; // Stoppe l'exécution de cette frame
    }

    // SNAKE EATS OWN BODY -> Reset au lieu de Game Over
    for(let i=0; i<snakeBody.length; i++) {
        if(snakeX == snakeBody[i][0] && snakeY == snakeBody[i][1]) {
            resetGame();
            return;
        }
    }

    // DESSIN DU SERPENT
    context.fillStyle = "blue";
    context.fillRect(snakeX, snakeY, blockSize, blockSize);
    for(let i=0; i<snakeBody.length; i++) {
        context.fillRect(snakeBody[i][0], snakeBody[i][1], blockSize, blockSize);
    }
}

// MOVEMENTS OF THE SNAKE
function changeDirection(e) {
    if((e.code == "ArrowUp" || e.key == "Z" || e.key == "z") && speedY != 1) {
        speedX = 0;
        speedY = -1;
    }
    else if((e.code == "ArrowDown" || e.key == "S" || e.key == "s") && speedY != -1) { // Correction du bug de direction
        speedX = 0;
        speedY = 1;
    }
    else if((e.code == "ArrowLeft" || e.key == "Q" || e.key == "q") && speedX != 1) {
        speedX = -1;
        speedY = 0;
    }
    else if((e.code == "ArrowRight" || e.key == "D" || e.key == "d") && speedX != -1) { // Correction du bug de direction
        speedX = 1;
        speedY = 0;
    }
}

// RANDOMLY PLACE FOOD
function placeFood() {
    foodX = Math.floor(Math.random() * total_col) * blockSize;
    foodY = Math.floor(Math.random() * total_row) * blockSize;
}