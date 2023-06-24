#include "raylib.h"
#include "../game/game.h"

void shoot(Bullet *b, Rectangle *position, Game *g) {
    if(IsKeyPressed(KEY_SPACE) &&  b->active == 0){
        if(b->direction == KEY_UP || b->direction == KEY_DOWN) {
            b->pos = (Rectangle){position->x,position->y,15,45};
        }
        if(b->direction == KEY_LEFT || b->direction == KEY_RIGHT) {
            b->pos = (Rectangle){position->x,position->y,45,15};
        }
        b->active = 1;
    }else {
        update_bullet_pos(b,g);
    }
}

void update_bullet_pos(Bullet *b, Game *g){
    if(b->direction == KEY_LEFT) {
            b->pos.x -= b->speed;
        if (!(b->pos.x > SCREEN_BORDER)) {
            b->active = 0;
            b->pos = b->default_pos;
        }
        if(barrier_collision(&g->maps[g->curr_map],&b->pos)){
            b->active = 0;
            b->pos = b->default_pos;
        }
    }
    if(b->direction == KEY_RIGHT) {
        b->pos.x += b->speed;
        if (!(b->pos.x + b->pos.width < g->screenWidth - SCREEN_BORDER)){
            b->active = 0;
            b->pos = b->default_pos;
        }
        if(barrier_collision(&g->maps[g->curr_map],&b->pos)){
            b->active = 0;
            b->pos = b->default_pos;
        }
    }
    if(b->direction == KEY_UP) {
        b->pos.y -= b->speed;
        if (!(b->pos.y > SCREEN_BORDER)) {
            b->active = 0;
            b->pos = b->default_pos;
        }
        if(barrier_collision(&g->maps[g->curr_map],&b->pos)){
            b->active = 0;
            b->pos = b->default_pos;
        }
    }
    if(b->direction == KEY_DOWN) {
        b->pos.y += b->speed;
        if (!(b->pos.y +b->pos.height < g->screenHeight - SCREEN_BORDER)){
            b->active = 0;
            b->pos = b->default_pos;
        }
        if(barrier_collision(&g->maps[g->curr_map],&b->pos)){
            b->active = 0;
            b->pos = b->default_pos;
        }
    }
}

void shootEnemy(Bullet *b, Rectangle *position, Game *g) {
    if(b->active == 0){
        b->active = 1;
    }else {
        update_enemyBullet_pos(b,g);
    }
}

void update_enemyBullet_pos(Bullet *b, Game *g){
    if(b->direction == KEY_LEFT) {
            b->pos.x -= b->speed;
        if (!(b->pos.x > SCREEN_BORDER)) {
            b->active = 0;
            b->pos = b->default_pos;
        }
        if(barrier_collision(&g->maps[g->curr_map],&b->pos)){
            b->active = 0;
            b->pos = b->default_pos;
        }
    }
    if(b->direction == KEY_RIGHT) {
        b->pos.x += b->speed;
        if (!(b->pos.x + b->pos.width < g->screenWidth - SCREEN_BORDER)){
            b->active = 0;
            b->pos = b->default_pos;
        }
        if(barrier_collision(&g->maps[g->curr_map],&b->pos)){
            b->active = 0;
            b->pos = b->default_pos;
        }
    }
    if(b->direction == KEY_UP) {
        b->pos.y -= b->speed;
        if (!(b->pos.y > SCREEN_BORDER)) {
            b->active = 0;
            b->pos = b->default_pos;
        }
        if(barrier_collision(&g->maps[g->curr_map],&b->pos)){
            b->active = 0;
            b->pos = b->default_pos;
        }
    }
    if(b->direction == KEY_DOWN) {
        b->pos.y += b->speed;
        if (!(b->pos.y +b->pos.height < g->screenHeight - SCREEN_BORDER)){
            b->active = 0;
            b->pos = b->default_pos;
        }
        if(barrier_collision(&g->maps[g->curr_map],&b->pos)){
            b->active = 0;
            b->pos = b->default_pos;
        }
    }

}
