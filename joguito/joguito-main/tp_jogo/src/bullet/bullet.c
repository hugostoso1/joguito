#include "../raylib.h"
#include "../game/game.h"
#include <stdio.h>

void shoot(Hero *b, Rectangle *position, Game *g) {

    update_bullet_pos(b,g);

    if(IsKeyPressed(KEY_SPACE) &&  b->bullet.active == 0){
        if(b->bullet.direction == KEY_UP || b->bullet.direction == KEY_DOWN) {
            b->bullet.pos = (Rectangle){position->x,position->y,15,45};
        }
        if(b->bullet.direction == KEY_LEFT || b->bullet.direction == KEY_RIGHT) {
            b->bullet.pos = (Rectangle){position->x,position->y,45,15};
        }
        b->bullet.active = 1;
    }
    else if(IsKeyPressed(KEY_SPACE) &&  b->bullet2.active == 0){
        if(b->bullet2.direction == KEY_UP || b->bullet2.direction == KEY_DOWN) {
            b->bullet2.pos = (Rectangle){position->x,position->y,15,45};
        }
        if(b->bullet2.direction == KEY_LEFT || b->bullet2.direction == KEY_RIGHT) {
            b->bullet2.pos = (Rectangle){position->x,position->y,45,15};
        }
        b->bullet2.active = 1;
    }
}

void update_bullet_pos(Hero *h, Game *g){
    Bullet *b = &h->bullet;#include "../raylib.h"
#include "../game/game.h"
#include <stdio.h>

void shoot(Hero *b, Rectangle *position, Game *g) {

    update_bullet_pos(b,g);

    if(IsKeyPressed(KEY_SPACE) &&  b->bullet.active == 0){
        if(b->bullet.direction == KEY_UP || b->bullet.direction == KEY_DOWN) {
            b->bullet.pos = (Rectangle){position->x,position->y,15,45};
        }
        if(b->bullet.direction == KEY_LEFT || b->bullet.direction == KEY_RIGHT) {
            b->bullet.pos = (Rectangle){position->x,position->y,45,15};
        }
        b->bullet.active = 1;
    }
    else if(IsKeyPressed(KEY_SPACE) &&  b->bullet2.active == 0){
        if(b->bullet2.direction == KEY_UP || b->bullet2.direction == KEY_DOWN) {
            b->bullet2.pos = (Rectangle){position->x,position->y,15,45};
        }
        if(b->bullet2.direction == KEY_LEFT || b->bullet2.direction == KEY_RIGHT) {
            b->bullet2.pos = (Rectangle){position->x,position->y,45,15};
        }
        b->bullet2.active = 1;
    }
}

void update_bullet_pos(Hero *h, Game *g){
    Bullet *b = &h->bullet;
    Bullet *b2 = &h->bullet2;
    if(b->active)
    {
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

    if(b2->active)
    {
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

void update_enemyBullet_pos(Enemy *e, Game *g){
    Bullet *b = &e->enemyBullet1;
    Bullet *b2 = &e->enemyBullet2;
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


void shootEnemy(Bullet *b, Rectangle *position, Game *g) {
    if(b->active){
        update_enemyBullet_pos(g->maps->enemies,g);
    }
}


    Bullet *b2 = &h->bullet2;
    if(b->active)
    {
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

    if(b2->active)
    {
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

void update_enemyBullet_pos(Enemy *e, Game *g){
    Bullet *b = &e->enemyBullet;
    Bullet *b2 = &e->enemyBullet2;
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


void shootEnemy(Bullet *b, Rectangle *position, Game *g) {
    if(b->active){
        update_enemyBullet_pos(g->maps->enemies,g);
    }
}

