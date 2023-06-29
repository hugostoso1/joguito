#include "../raylib.h"
#include <stdlib.h>
#include "../game/game.h"

void update_boss_pos(Game *g,Boss *boss) {
    if (boss->direction == KEY_LEFT)
    {
        if (boss->pos.x > SCREEN_BORDER)
            boss->pos.x -= boss->speed;
        else
        {
            boss->direction = KEY_RIGHT + (rand() % 4);
        }
        if (barrier_collision(&g->maps[g->curr_map], &boss->pos))
        {
            boss->pos.x += boss->speed;
            boss->direction = KEY_RIGHT + (rand() % 4);
        }
    }
    else if (boss->direction == KEY_RIGHT)
    {
        if (boss->pos.x + boss->pos.width < g->screenWidth - SCREEN_BORDER)
            boss->pos.x += boss->speed;
        else
            boss->direction = KEY_RIGHT + (rand() % 4);

        if (barrier_collision(&g->maps[g->curr_map], &boss->pos))
        {
            boss->pos.x -= boss->speed;
            boss->direction = KEY_RIGHT + (rand() % 4);
        }
    }
    else if (boss->direction == KEY_UP)
    {
        if (boss->pos.y > SCREEN_BORDER)
            boss->pos.y -= boss->speed;
        else
            boss->direction = KEY_RIGHT + (rand() % 4);

        if (barrier_collision(&g->maps[g->curr_map], &boss->pos))
        {
            boss->pos.y += boss->speed;
            boss->direction = KEY_RIGHT + (rand() % 4);
        }
    }
    else if (boss->direction == KEY_DOWN)
    {
        if (boss->pos.y + boss->pos.height < g->screenHeight - SCREEN_BORDER)
            boss->pos.y += boss->speed;
        else
            boss->direction = KEY_RIGHT + (rand() % 4);

        if (barrier_collision(&g->maps[g->curr_map], &boss->pos))
        {
            boss->pos.y -= boss->speed;
            boss->direction = KEY_RIGHT + (rand() % 4);
        }
    }
    if (rand() % 100 == 1) // 1% de chance do inimigo mudar de direcao
        boss->direction = KEY_RIGHT + (rand() % 4);
}