#include "raylib.h"
#include "../game/game.h"
void update_hero_pos(Game *g)
{
    Hero *h = &g->hero;
    Map *m = &g->maps[g->curr_map];
    Bullet *b = &g->hero.bullet;
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
    {
        if (h->pos.x > SCREEN_BORDER)
            h->pos.x -= h->speed;
        if (barrier_collision(m, &h->pos))
            h->pos.x += h->speed;
        (b->active == 0) ? b->direction = KEY_LEFT: b->direction;

    }
    else if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    {
        if (h->pos.x + h->pos.width < g->screenWidth - SCREEN_BORDER)
            h->pos.x += h->speed;
        if (barrier_collision(m, &h->pos))
            h->pos.x -= h->speed;
        (b->active == 0) ? b->direction = KEY_RIGHT : b->direction;
    }
    else if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
    {
        if (h->pos.y > SCREEN_BORDER)
            h->pos.y -= h->speed;
        if (barrier_collision(m, &h->pos))
            h->pos.y += h->speed;
        (b->active == 0) ? b->direction = KEY_UP : b->direction;
    }
    else if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
    {
        if (h->pos.y + h->pos.height < g->screenHeight - SCREEN_BORDER)
            h->pos.y += h->speed;
        if (barrier_collision(m, &h->pos))
            h->pos.y -= h->speed;
        (b->active == 0) ? b->direction = KEY_DOWN : b->direction;

    }
}