#include <graphics.h>
#include <conio.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>    // Pour rand(), srand()
#include <stdbool.h>   // NOUVEAU (C) : Pour utiliser le type bool, true, false
#include <windows.h>   // NOUVEAU (C) : Pour GetAsyncKeyState
#include <ctype.h>     // NOUVEAU (C) : Pour tolower()

/* DIFFERENCE : Pas de "using namespace std;" en C */

/* DIFFERENCE : En C, on utilise souvent "typedef" pour éviter 
   d'écrire "struct Point" à chaque fois qu'on déclare une variable. */
typedef struct { 
    int x; 
    int y; 
} Point;

// Variables globales
int x = 300, y = 300, fx = 100, fy = 100;
int dirX = 20, dirY = 0;
int score = 0, gameSpeed = 100;

/* DIFFERENCE : Pas de <vector> en C. On utilise un tableau de taille fixe 
   et un entier pour mémoriser la taille actuelle du serpent. */
#define MAX_SNAKE 1000
Point snake[MAX_SNAKE];
int snake_length = 0;

// 0 = En jeu, 1 = Game Over
int gameState = 0; 

// Fonction utilitaire pour réinitialiser les variables du jeu
void reinitialiserJeu() {
    x = 300; y = 300;
    dirX = 20; dirY = 0;
    score = 0; gameSpeed = 100;
    
    // Equivalent de snake.clear()
    snake_length = 0;
    
    // Equivalent de snake.push_back({x, y})
    snake[snake_length].x = x;
    snake[snake_length].y = y;
    snake_length++;
    
    fx = (rand() % 30) * 20 + 10;
    fy = (rand() % 30) * 20 + 10;
    gameState = 0; // On repasse en mode "En jeu"
}

void gererEntrees() {
    if (gameState == 0) {
        if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('Z')) { dirX = 0; dirY = -20; }
        if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S')) { dirX = 0; dirY = 20; }
        if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('Q')) { dirX = -20; dirY = 0; }
        if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D')) { dirX = 20; dirY = 0; }
    }
    else if (gameState == 1) {
        if (GetAsyncKeyState('R')) {
            reinitialiserJeu();
        }
    }
}

void mettreAJourLogique() {
    if (gameState == 1) return;

    x += dirX; y += dirY;

    if (x < 0 || x >= 600 || y < 0 || y >= 600) {
        gameState = 1; 
        return;
    }

    if (x < fx + 10 && x + 20 > fx - 10 && y < fy + 10 && y + 20 > fy - 10) {
        score += 10;
        if(gameSpeed > 30) gameSpeed -= 5;
        fx = (rand() % 30) * 20 + 10;
        fy = (rand() % 30) * 20 + 10;
        
        // Equivalent de snake.push_back({x, y})
        if (snake_length < MAX_SNAKE) {
            snake[snake_length].x = x;
            snake[snake_length].y = y;
            snake_length++;
        }
    }

    /* Equivalent de snake.insert(snake.begin(), {x, y})
       En C, on doit décaler manuellement tous les éléments vers la droite */
    for (int i = snake_length; i > 0; i--) {
        snake[i] = snake[i - 1];
    }
    snake[0].x = x;
    snake[0].y = y;
    if (snake_length < MAX_SNAKE) {
        snake_length++;
    }

    /* Equivalent de snake.pop_back() */
    if (snake_length > 0) {
        snake_length--;
    }
}

void dessiner(int page) {
    setactivepage(1 - page);
    setbkcolor(CYAN);
    cleardevice();

    if (gameState == 0) {
        setcolor(RED); setfillstyle(SOLID_FILL, RED);
        fillellipse(fx, fy, 10, 10);
        setcolor(WHITE); setfillstyle(SOLID_FILL, WHITE);
        fillellipse(fx - 3, fy - 3, 3, 3);
        
        setfillstyle(SOLID_FILL, YELLOW); setcolor(BLACK);
        
        // DIFFERENCE : On utilise snake_length au lieu de snake.size()
        for(int i = 0; i < snake_length; i++) {
            bar(snake[i].x, snake[i].y, snake[i].x + 20, snake[i].y + 20);
            rectangle(snake[i].x, snake[i].y, snake[i].x + 20, snake[i].y + 20);

            if (i == 0) {
                int dX = 0, dY = 0;
                if (dirX == 20)  { dX = 4; dY = 0; }  
                if (dirX == -20) { dX = -4; dY = 0; } 
                if (dirY == -20) { dX = 0; dY = -4; } 
                if (dirY == 20)  { dX = 0; dY = 4; }  

                setfillstyle(SOLID_FILL, WHITE);
                fillellipse(snake[i].x + 6 + dX, snake[i].y + 10 + dY, 3, 3);
                fillellipse(snake[i].x + 14 + dX, snake[i].y + 10 + dY, 3, 3);
                
                setfillstyle(SOLID_FILL, BLACK);
                fillellipse(snake[i].x + 6 + dX, snake[i].y + 10 + dY, 1, 1);
                fillellipse(snake[i].x + 14 + dX, snake[i].y + 10 + dY, 1, 1);
            }
        }

        char scoreStr[50];
        sprintf(scoreStr, "Score: %d", score);
        setcolor(BLACK);
        outtextxy(10, 10, scoreStr);

    } else if (gameState == 1) {
        setcolor(BLACK);
        setfillstyle(SOLID_FILL, COLOR(150, 0, 0)); 
        bar(100, 200, 500, 400);
        rectangle(100, 200, 500, 400);

        setbkcolor(COLOR(150, 0, 0));
        setcolor(WHITE);

        char finalScore[50];
        sprintf(finalScore, "SCORE FINAL : %d", score);

        outtextxy(255, 240, "GAME OVER");
        outtextxy(235, 290, finalScore);
        
        setcolor(YELLOW);
        outtextxy(200, 340, "Appuyez sur 'R' pour rejouer");
    }

    setvisualpage(1 - page);
}

int main() {
    initwindow(600, 600, "Snake Game");
    int page = 0;
    srand(time(NULL));
    
    // Equivalent de snake.push_back({x, y});
    snake[snake_length].x = x;
    snake[snake_length].y = y;
    snake_length++;

    bool running = true;
    while (running) {
        if (kbhit() && tolower(getch()) == 'x') running = false;

        gererEntrees();
        mettreAJourLogique();
        dessiner(page);

        page = 1 - page;
        delay(gameSpeed);
    }

    closegraph();
    return 0;
}