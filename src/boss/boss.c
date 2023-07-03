#include "../raylib.h"
#include <stdlib.h>
#include "../game/game.h"

void update_boss_pos(Game *g,Boss *boss) {
    float x = boss->pos.x;
    float y = boss->pos.y;
    int delta = 10 - boss->life;
    float height = (delta != 0) ? 80 - (5 * delta) : 80;
    float width = (delta != 0) ? 80 - (5 * delta) : 80;

  
    update_bullet(&boss->bossBullet, &boss->bossBullet2, g);
    

    if(!boss->bossBullet.active && rand() % 5 == 1){
        int x = g->hero.pos.x - boss->pos.x;
        int y = g->hero.pos.y - boss->pos.y;
    
        if(x>=-20 && x<=20){
            boss->bossBullet.direction = (y>0) ? KEY_DOWN : KEY_UP;   
            boss->bossBullet.pos = (Rectangle){boss->pos.x, boss->pos.y, 15, 45};
            boss->bossBullet.active = 1;
        }
        if(y>=-20 && y <=20){
            boss->bossBullet.direction = (x>0) ? KEY_RIGHT : KEY_LEFT;  
            boss->bossBullet.pos = (Rectangle){boss->pos.x, boss->pos.y, 45, 15};
            boss->bossBullet.active = 1;
        }
    }
    else if(!boss->bossBullet2.active  &&  rand() % 50 == 1){

        int xx = g->hero.pos.x - boss->pos.x;
        int yy = g->hero.pos.y - boss->pos.y;
    
        if(xx>=-20 && xx<=20){
            boss->bossBullet2.direction = (yy>0) ? KEY_DOWN : KEY_UP;   
            boss->bossBullet2.pos = (Rectangle){boss->pos.x, boss->pos.y, 15, 45};
            boss->bossBullet2.active = 1;
        }
        if(yy>=-20 && yy<=20){
            boss->bossBullet2.direction = (xx>0) ? KEY_RIGHT : KEY_LEFT;  
            boss->bossBullet2.pos = (Rectangle){boss->pos.x, boss->pos.y, 45, 15};
            boss->bossBullet2.active = 1;
        }
    }

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