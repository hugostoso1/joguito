#include "raylib.h"
#include <stdlib.h>
#include <sys/time.h> 
#include <stdio.h>
#include <unistd.h> 
#include <time.h>
#include "./game/game.h"
#include <string.h>

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
    fprintf(p, "%s\n%ld\n", nickname, seconds);
    fclose(p);  //le o da rodada

    FILE *arquivo = fopen("pontuacoes.txt", "r");
    char linha[100];
    char *lines[100];  // Array para armazenar as strings

    // Abre o arquivo para leitura

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int i = 0;

    // Lê cada linha do arquivo
    while (fgets(linha, 100, arquivo) != NULL) {
        // Aloca memória para a string atual
        lines[i] = malloc(strlen(linha) + 1);
        if (lines[i] == NULL) {
            printf("Erro ao alocar memória.\n");
            return 1;
        }

        // Copia a linha lida para a string atual
        strcpy(lines[i], linha);
        i++;
    }

    int num_lines = i; // Número total de linhas lidas

    // Fecha o arquivo
    fclose(arquivo);


    //leitura das coisas nos arquivos

    int v[num_lines/2];
    int vet = 0;
    int l = 1;
    i = 0;

    while (1) {
        v[vet] = atoi(lines[l]);
        l++;
        l++;
        vet++;
        if (l > num_lines) {
            break;
        }
    }

   // bubbleSort(v, num_lines/2);
    if (num_lines > 8) {
    FILE *pimba = fopen("pontuacoes.txt", "w");
    if (pimba == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Escrever a última linha primeiro
    fprintf(pimba, "%s%d\n", lines[(num_lines - 2)], v[(num_lines/2 - 1)]);

    // Escrever as outras linhas e valores
    for (int j = 0; j < 8/2 - 1; j++) {
        fprintf(pimba, "%s%d\n", lines[j*2], v[j]);
    }}

    if(num_lines <= 8){
        FILE *pimba = fopen("pontuacoes.txt", "w");
    if (pimba == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Escrever a última linha primeiro
    fprintf(pimba, "%s%d\n", lines[(num_lines - 2)], v[(num_lines/2 - 1)]);

    // Escrever as outras linhas e valores
    for (int j = 0; j < num_lines/2 - 1; j++) {
        fprintf(pimba, "%s%d\n", lines[j*2], v[j]);

    }
    

    fclose(pimba);
}

    while (!IsKeyDown(KEY_ENTER) && !WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("GAME OVER", GetScreenWidth() / 2 - MeasureText("GAME OVER", 55) / 2, GetScreenHeight() / 2 - 50, 55, BLACK);
        EndDrawing();

    }
      for (i = 0; i < num_lines; i++) {
        free(lines[i]);  // Libera a memória alocada para cada string
    }

    return 0;
}