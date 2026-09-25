#include <graphics.h>
#include <conio.h>
#include <time.h>
#include <vector>
#include <stdio.h>

using namespace std;

struct Point { int x, y; };

// Variables globales
int x = 300, y = 300, fx = 100, fy = 100;
int dirX = 20, dirY = 0;
int score = 0, gameSpeed = 100;
int typeFruit;
vector<Point> snake;

// NOUVEAU : 0 = En jeu, 1 = Game Over
int gameState = 0; 

// Fonction utilitaire pour réinitialiser les variables du jeu
void reinitialiserJeu() {
    x = 300; y = 300;
    dirX = 20; dirY = 0;
    score = 0; gameSpeed = 100;
    snake.clear();
    snake.push_back({x, y});
    fx = (rand() % 30) * 20 + 10;
    fy = (rand() % 30) * 20 + 10;
    gameState = 0; // On repasse en mode "En jeu"
}

void gererEntrees() {
    // Si nous sommes en jeu, les commandes ZQSD fonctionnent
    if (gameState == 0) {
        if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('Z')) { dirX = 0; dirY = -20; }
        if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S')) { dirX = 0; dirY = 20; }
        if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('Q')) { dirX = -20; dirY = 0; }
        if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D')) { dirX = 20; dirY = 0; }
    }
    // Si c'est Game Over, on attend que le joueur appuie sur 'R' pour rejouer
    else if (gameState == 1) {
        if (GetAsyncKeyState('R')) {
            reinitialiserJeu();
        }
    }
}

void mettreAJourLogique() {
    // Si le jeu est en pause Game Over, on ne calcule plus les mouvements
    if (gameState == 1) return;

    x += dirX; y += dirY;

    // Collision murs -> Déclenche le Game Over
    if (x < 0 || x >= 600 || y < 0 || y >= 600) {
        gameState = 1; 
        return;
    }

    // Collision fruit
    if (x < fx + 10 && x + 20 > fx - 10 && y < fy + 10 && y + 20 > fy - 10) {
        if(typeFruit == 0) {
        score += 10;
        if(gameSpeed > 30) gameSpeed -= 5;


        } else if(typeFruit == 1) {
        score += 30;
        if(gameSpeed > 30) gameSpeed -= 5;

        }        
        snake.push_back({x,y});        
        fx = (rand() % 30) * 20 + 10;
        fy = (rand() % 30) * 20 + 10;
        if(rand() % 5 == 0) typeFruit = 1;
        else typeFruit = 0;
    }

    snake.insert(snake.begin(), {x, y});
    snake.pop_back();
}

void dessiner(int page) {
    setactivepage(1 - page);
    setbkcolor(CYAN);
    cleardevice();

    if (gameState == 0) {
        // --- AFFICHAGE EN JEU ---
        // Fruit brillant
        if(typeFruit == 0) {setcolor(RED); setfillstyle(SOLID_FILL, RED);}
        if(typeFruit == 1) {setcolor(YELLOW); setfillstyle(SOLID_FILL, YELLOW);}
        fillellipse(fx, fy, 10, 10);
        setcolor(WHITE); setfillstyle(SOLID_FILL, WHITE);
        fillellipse(fx - 3, fy - 3, 3, 3);
        

        // Serpent avec ses deux yeux dynamiques
        setfillstyle(SOLID_FILL, YELLOW); setcolor(BLACK);
        for(size_t i = 0; i < snake.size(); i++) {
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

        // Score classique en haut à gauche
        char scoreStr[50];
        sprintf(scoreStr, "Score: %d", score);
        setcolor(BLACK);
        outtextxy(10, 10, scoreStr);

    } else if (gameState == 1) {
        // --- AFFICHAGE ÉCRAN GAME OVER ---
        // Dessin d'un panneau central rouge foncé
        setcolor(BLACK);
        setfillstyle(SOLID_FILL, COLOR(150, 0, 0)); 
        bar(100, 200, 500, 400);
        rectangle(100, 200, 500, 400);

        // Configuration du texte
        setbkcolor(COLOR(150, 0, 0));
        setcolor(WHITE);

        // Textes de l'écran de fin
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
    
    // Initialisation du premier serpent
    snake.push_back({x, y});

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