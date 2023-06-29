#include "raylib.h"
#include <stdlib.h>
#include <sys/time.h> 
#include <stdio.h>
#include <unistd.h> 
#include <time.h>
#include "./game/game.h"

int main(void)
{
    Game game;
    game.screenWidth = 1500;
    game.screenHeight = 700;

    InitWindow(game.screenWidth, game.screenHeight, "Aedsinho's quest");
    SetTargetFPS(60);
    InitGame(&game);

    char nickname[50];
    int countNick = 0;
    int select = 1; // 1 normal, 0 hard
    while (!IsKeyPressed(KEY_ENTER) && !WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLUE);
        DrawText("ESCREVA UM NICKNAME", GetScreenWidth() / 2 - MeasureText("ESCREVA UM NICKNAME", 55) / 2, GetScreenHeight() / 2 - 50, 55, BLACK);
        if(countNick) {
            DrawText(nickname, GetScreenWidth() / 2 - MeasureText(nickname, 35) / 2, GetScreenHeight()- 150, 35, BLACK);
        }
        EndDrawing();
        int key = GetKeyPressed();
        while (key > 0){
            if ((key >= 32) && (key <= 125) && (countNick < 50)){
                    nickname[countNick] = (char)key;
                    nickname[countNick+1] = '\0';
                    countNick++;
                }
            key = GetKeyPressed();
        }

        if (IsKeyPressed(KEY_BACKSPACE)){
            countNick--;
            if (countNick < 0) countNick = 0;
            nickname[countNick] = '\0';
        }
    }
    
    
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLUE);
        DrawText("ESCOLHA UM MODO DE JOGO:", GetScreenWidth() / 2 - MeasureText("ESCOLHA UM MODO DE JOGO:", 55) / 2, GetScreenHeight() / 2 - 75, 55, BLACK);
        if(IsKeyDown(KEY_DOWN)) {
            select = 0;
        } else if (IsKeyDown(KEY_UP)) {
            select = 1;
        }

        if(select) {
            DrawText("NORMAL GAME", GetScreenWidth() / 2 - MeasureText("NORMAL GAME", 55) / 2, GetScreenHeight() - 230, 55, WHITE);
            DrawText("HARD GAME", GetScreenWidth() / 2 - MeasureText("HARD GAME", 40) / 2, GetScreenHeight() - 150, 40, BLACK);
        } else {
            DrawText("NORMAL GAME", GetScreenWidth() / 2 - MeasureText("NORMAL GAME", 40) / 2, GetScreenHeight() - 230, 40, BLACK);
            DrawText("HARD GAME", GetScreenWidth() / 2 - MeasureText("HARD GAME", 55) / 2, GetScreenHeight() - 150, 55, WHITE);
        }
        EndDrawing();
        if(IsKeyPressed(KEY_ENTER)) break;
    }

    game.mode = (select) ? 'N' : 'H';
    struct timeval start, end;
    gettimeofday(&start, NULL);
    

    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        UpdateDrawFrame(&game);
        if (game.gameover)
            break;
    }
    time;

    gettimeofday(&end, NULL);
 
    long seconds = (end.tv_sec - start.tv_sec);
    long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
 

    FILE *p = fopen("pontuacoes.txt", "a");
    fprintf(p, "%s--%ld\n", nickname, seconds);
    

    fclose(p);

    FILE *pp = fopen("pontuacoes.txt", "r");



    while (!IsKeyDown(KEY_ENTER) && !WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("GAME OVER", GetScreenWidth() / 2 - MeasureText("GAME OVER", 55) / 2, GetScreenHeight() / 2 - 50, 55, BLACK);
        EndDrawing();

    }
    return 0;
}
