#include "../raylib.h"
#include "../game/game.h"
#include <stdio.h>
#include <math.h>

void shoot(Hero *b, Rectangle *position, Game *g) {
    update_bullet(&b->bullet, &b->bullet2,g);

    if(IsKeyPressed(KEY_SPACE) &&  b->bullet.active == 0){
        if(b->bullet.direction == KEY_UP || b->bullet.direction == KEY_DOWN) {
            b->bullet.pos = (Rectangle){position->x,position->y,15,45}; //15, 45
        }
        if(b->bullet.direction == KEY_LEFT || b->bullet.direction == KEY_RIGHT) {
            b->bullet.pos = (Rectangle){position->x,position->y,45,15};
        }
        b->bullet.active = 1;
    }
    else if(IsKeyPressed(KEY_SPACE) &&  b->bullet2.active == 0 && (g->mode == 'N')){
        if(b->bullet2.direction == KEY_UP || b->bullet2.direction == KEY_DOWN) {
            b->bullet2.pos = (Rectangle){position->x,position->y,15,45};
        }
        if(b->bullet2.direction == KEY_LEFT || b->bullet2.direction == KEY_RIGHT) {
            b->bullet2.pos = (Rectangle){position->x,position->y,45,15};
        }
        b->bullet2.active = 1;
    }
}

void update_bullet(Bullet *b, Bullet *b2, Game *g) {
    if(b->active){
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
    if(b2->active){
        if(b2->direction == KEY_LEFT) {
                b2->pos.x -= b2->speed;
            if (!(b2->pos.x > SCREEN_BORDER)) {
                b2->active = 0;
                b2->pos = b2->default_pos;
            }
            if(barrier_collision(&g->maps[g->curr_map],&b2->pos)){
                b2->active = 0;
                b2->pos = b2->default_pos;
            }
        }
        if(b2->direction == KEY_RIGHT) {
            b2->pos.x += b2->speed;
            if (!(b2->pos.x + b2->pos.width < g->screenWidth - SCREEN_BORDER)){
                b2->active = 0;
                b2->pos = b2->default_pos;
            }
            if(barrier_collision(&g->maps[g->curr_map],&b2->pos)){
                b2->active = 0;
                b2->pos = b2->default_pos;
            }
        }
        if(b2->direction == KEY_UP) {
            b2->pos.y -= b2->speed;
            if (!(b2->pos.y > SCREEN_BORDER)) {
                b2->active = 0;
                b2->pos = b2->default_pos;
            }
            if(barrier_collision(&g->maps[g->curr_map],&b2->pos)){
                b2->active = 0;
                b2->pos = b2->default_pos;
            }
        }
        if(b2->direction == KEY_DOWN) {
            b2->pos.y += b2->speed;
            if (!(b2->pos.y +b2->pos.height < g->screenHeight - SCREEN_BORDER)){
                b2->active = 0;
                b2->pos = b2->default_pos;
            }
            if(barrier_collision(&g->maps[g->curr_map],&b2->pos)){
                b2->active = 0;
                b2->pos = b2->default_pos;
            }
        }
    }
}

void bulletCollison(Bullet *b1, Bullet *b2){
    if(CheckCollisionRecs(b1->pos, b2->pos)){
        b1->active = 0;
        b2->active = 0;
        b1->pos = b1->default_pos;
        b2->pos = b2->default_pos;
    }
}


