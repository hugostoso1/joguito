#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include "./game/game.h"

int main(void)
{
    Game game;
    game.screenWidth = 800;
    game.screenHeight = 480;

    InitWindow(game.screenWidth, game.screenHeight, "Aedsinho's quest");
    SetTargetFPS(60);
    InitGame(&game);

    char nickname[50];
    int countNick = 0;
    while (!IsKeyDown(KEY_ENTER) && !WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLUE);
        DrawText("ESCREVA UM NICKNAME", GetScreenWidth() / 2 - MeasureText("ESCREVA UM NICKNAME", 20) / 2, GetScreenHeight() / 2 - 50, 20, WHITE);
        if(countNick) {
            DrawText(nickname, GetScreenWidth() / 2 - MeasureText(nickname, 20) / 2, GetScreenHeight()- 150, 20, WHITE);
        }
        EndDrawing();
        int key = GetCharPressed();
        while (key > 0){
            if ((key >= 32) && (key <= 125) && (countNick < 50)){
                    nickname[countNick] = (char)key;
                    nickname[countNick+1] = '\0';
                    countNick++;
                }

                key = GetCharPressed();
            }

        if (IsKeyPressed(KEY_BACKSPACE)){
            countNick--;
            if (countNick < 0) countNick = 0;
            nickname[countNick] = '\0';
        }
    }

    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        UpdateDrawFrame(&game);
        if (game.gameover)
            break;
    }
    while (!IsKeyDown(KEY_ENTER) && !WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("GAME OVER", GetScreenWidth() / 2 - MeasureText("GAME OVER", 20) / 2, GetScreenHeight() / 2 - 50, 20, BLACK);
        EndDrawing();
    }
    return 0;
}
