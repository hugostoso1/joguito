#include "../raylib.h"
#include <stdlib.h>
#include "../game/game.h"

void update_boss_pos(Game *g,Boss *boss) {
    float x = boss->pos.x;
    float y = boss->pos.y;
    int delta = 10 - boss->life;
    float height = (delta != 0) ? 80 - (5 * delta) : 80;
    float width = (delta != 0) ? 80 - (5 * delta) : 80;
    if (boss->direction == KEY_LEFT)
    {
        if (x > SCREEN_BORDER) {
            x -= boss->speed;
            boss->pos = (Rectangle) {x,y,width,height};
        }
        else
        {
            boss->direction = KEY_RIGHT + (rand() % 4);
        }
        if (barrier_collision(&g->maps[g->curr_map], &boss->pos))
        {
            x += boss->speed;
            boss->pos = (Rectangle) {x,y,width,height};
            boss->direction = KEY_RIGHT + (rand() % 4);
        }
    }
    else if (boss->direction == KEY_RIGHT)
    {
        if (x + boss->pos.width < g->screenWidth - SCREEN_BORDER) {
            x += boss->speed;
            boss->pos = (Rectangle) {x,y,width,height};
        }
        else
            boss->direction = KEY_RIGHT + (rand() % 4);

        if (barrier_collision(&g->maps[g->curr_map], &boss->pos))
        {
            x -= boss->speed;
            boss->pos = (Rectangle) {x,y,width,height};
            boss->direction = KEY_RIGHT + (rand() % 4);
        }
    }
    else if (boss->direction == KEY_UP)
    {
        if (y > SCREEN_BORDER) {
            y -= boss->speed;
            boss->pos = (Rectangle) {x,y,width,height};
        }
        else
            boss->direction = KEY_RIGHT + (rand() % 4);

        if (barrier_collision(&g->maps[g->curr_map], &boss->pos))
        {
            y += boss->speed;
            boss->pos = (Rectangle) {x,y,width,height};
            boss->direction = KEY_RIGHT + (rand() % 4);
        }
    }
    else if (boss->direction == KEY_DOWN)
    {
        if (y + boss->pos.height < g->screenHeight - SCREEN_BORDER) {
            y += boss->speed;
            boss->pos = (Rectangle) {x,y,width,height};
        }
        else
            boss->direction = KEY_RIGHT + (rand() % 4);

        if (barrier_collision(&g->maps[g->curr_map], &boss->pos))
        {
            y -= boss->speed;
            boss->pos = (Rectangle) {x,y,width,height};
            boss->direction = KEY_RIGHT + (rand() % 4);
        }
    }
    if (rand() % 100 == 1) // 1% de chance do inimigo mudar de direcao
        boss->direction = KEY_RIGHT + (rand() % 4);
}