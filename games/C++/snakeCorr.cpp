/*RULES:
- Don't hit a wall and don't bite your own tail.
- Crashing into a wall or your tail will end the game immediately.
- 10 points will be added to the player's score for eating the fruit (#).
- The player's total score is calculated based on the number of fruits the snake consumed.
- The length of the snake will be increased after eating the fruits.
- Use w, a, s, d to move the snake.*/
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

// DEFINING NECESSARY VARIABLES
const int width = 80;
const int height = 20;
int x, y;
int fruitCordX, fruitCordY;
int playerScore;
int snakeTailX[100], snakeTailY[100];
int snakeTailLen;
enum snakesDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
snakesDirection sDir;
bool isGameOver;

// INITIALIZING THE GAME
void GameInit() {
    isGameOver = false;
    sDir = STOP;
    x = width / 2;
    y = height / 2;
    fruitCordX = rand() % width;
    fruitCordY = rand() % height;
    playerScore = 0;
    snakeTailLen = 0; // FIX: initialize tail length
}

// CREATING GAME BOARD CUM GAME RENDERING FUNCTION
void GameRender(string playerName) {
    system("cls");
    for (int i = 0; i < width + 2; i++) cout << "-";
    cout << endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= width; j++) {
            if (j == 0 || j == width) cout << "|";
            else if (i == y && j == x) cout << "O";
            else if (i == fruitCordY && j == fruitCordX) cout << "#";
            else {
                bool prTail = false;
                for (int k = 0; k < snakeTailLen; k++) {
                    if (snakeTailX[k] == j && snakeTailY[k] == i) {
                        cout << "o";
                        prTail = true;
                    }
                }
                if (!prTail) cout << " ";
            }
        }
        cout << endl;
    }
    // FIX: moved bottom border and score outside the row loop
    for (int i = 0; i < width + 2; i++) cout << "-";
    cout << endl;
    cout << playerName << "'s Score: " << playerScore << endl;
}

// UPDATING THE GAME STATE
void UpdateGame() {
    // FIX: properly shift tail segments forward before moving head
    int prevX = x;
    int prevY = y;
    for (int i = 0; i < snakeTailLen; i++) {
        int tempX = snakeTailX[i];
        int tempY = snakeTailY[i];
        snakeTailX[i] = prevX;
        snakeTailY[i] = prevY;
        prevX = tempX;
        prevY = tempY;
    }

    switch (sDir) {
        case LEFT:  x--; break;
        case RIGHT: x++; break;
        case UP:    y--; break;
        case DOWN:  y++; break;
    }

    if (x >= width || x < 0 || y >= height || y < 0) isGameOver = true;

    for (int i = 0; i < snakeTailLen; i++) {
        if (snakeTailX[i] == x && snakeTailY[i] == y)
            isGameOver = true;
    }

    if (x == fruitCordX && y == fruitCordY) {
        playerScore += 10;
        fruitCordX = rand() % width;
        fruitCordY = rand() % height;
        snakeTailLen++;
    }
}

// SETTING THE GAME DIFFICULTY
int SetDifficulty() {
    int dfc, choice;
    cout << "\nSET DIFFICULTY\n1: Easy\n2: Medium\n3: Hard"
            "\nNOTE: if not chosen or pressed any other "
            "key, the difficulty will be automatically set "
            "to medium\nChoose difficulty level: ";
    cin >> choice;
    // FIX: compare against int literals, not char literals
    switch (choice) {
        case 1: dfc = 150; break; // Easy  = slower
        case 2: dfc = 100; break; // Medium
        case 3: dfc = 50;  break; // Hard  = faster
        default: dfc = 100;
    }
    return dfc;
}

// HANDLING USER INPUT
void UserInput() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a': sDir = LEFT;  break; // FIX: 'a' for left
            case 'd': sDir = RIGHT; break;
            case 'w': sDir = UP;    break; // FIX: 'w' for up
            case 's': sDir = DOWN;  break;
            case 'x': isGameOver = true; break;
        }
    }
}

// CREATING MAIN FUNCTION
int main() {
    string playerName;
    cout << "Enter your name: ";
    cin >> playerName;
    int dfc = SetDifficulty();

    GameInit();
    while (!isGameOver) {
        GameRender(playerName);
        UserInput();
        UpdateGame();
        Sleep(dfc);
    }
    cout << "\nGame Over! Final score: " << playerScore << endl;
    return 0;
}