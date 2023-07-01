#include "../raylib.h"
#include <stdlib.h>
#include "../game/game.h"

void update_enemy_pos(Game *g, Enemy *e)
{
    Map *m = &g->maps[g->curr_map];

    update_bullet(&e->enemyBullet, &e->enemyBullet2, g);

    if(!e->enemyBullet.active && rand() % 5 == 1){
        int x = g->hero.pos.x - e->pos.x;
        int y = g->hero.pos.y - e->pos.y;
    
        if(x>=-10 && x<=10){
            e->enemyBullet.direction = (y>0) ? KEY_DOWN : KEY_UP;   
            e->enemyBullet.pos = (Rectangle){e->pos.x, e->pos.y, 15, 45};
            e->enemyBullet.active = 1;
        }
        if(y>=-10 && y<=10){
            e->enemyBullet.direction = (x>0) ? KEY_RIGHT : KEY_LEFT;  
            e->enemyBullet.pos = (Rectangle){e->pos.x, e->pos.y, 45, 15};
            e->enemyBullet.active = 1;
        }
    }
    else if(!e->enemyBullet2.active  &&  rand() % 50 == 1 && (g->mode == 'H')){

        int xx = g->hero.pos.x - e->pos.x;
        int yy = g->hero.pos.y - e->pos.y;
    
        if(xx>=-10 && xx<=10){
            e->enemyBullet2.direction = (yy>0) ? KEY_DOWN : KEY_UP;   
            e->enemyBullet2.pos = (Rectangle){e->pos.x, e->pos.y, 15, 45};
            e->enemyBullet2.active = 1;
        }
        if(yy>=-10 && yy<=10){
            e->enemyBullet2.direction = (xx>0) ? KEY_RIGHT : KEY_LEFT;  
            e->enemyBullet2.pos = (Rectangle){e->pos.x, e->pos.y, 45, 15};
            e->enemyBullet2.active = 1;
        }
    }
    
    if(e->draw_enemy == 0){
        e->enemyBullet.pos = e->enemyBullet.default_pos;
        e->enemyBullet.active = 0;
        e->enemyBullet2.pos = e->enemyBullet2.default_pos;
        e->enemyBullet2.active = 0;
    }

    if (e->direction == KEY_LEFT)
    {
        if (e->pos.x > SCREEN_BORDER)
            e->pos.x -= e->speed;
        else
        {
            e->direction = KEY_RIGHT + (rand() % 4);
        }
        if (barrier_collision(m, &e->pos))
        {
            e->pos.x += e->speed;
            e->direction = KEY_RIGHT + (rand() % 4);
        }
    }
    else if (e->direction == KEY_RIGHT)
    {
        if (e->pos.x + e->pos.width < g->screenWidth - SCREEN_BORDER)
            e->pos.x += e->speed;
        else
            e->direction = KEY_RIGHT + (rand() % 4);

        if (barrier_collision(m, &e->pos))
        {
            e->pos.x -= e->speed;
            e->direction = KEY_RIGHT + (rand() % 4);
        }
    }
    else if (e->direction == KEY_UP)
    {
        if (e->pos.y > SCREEN_BORDER)
            e->pos.y -= e->speed;
        else
            e->direction = KEY_RIGHT + (rand() % 4);

        if (barrier_collision(m, &e->pos))
        {
            e->pos.y += e->speed;
            e->direction = KEY_RIGHT + (rand() % 4);
        }
    }
    else if (e->direction == KEY_DOWN)
    {
        if (e->pos.y + e->pos.height < g->screenHeight - SCREEN_BORDER)
            e->pos.y += e->speed;
        else
            e->direction = KEY_RIGHT + (rand() % 4);

        if (barrier_collision(m, &e->pos))
        {
            e->pos.y -= e->speed;
            e->direction = KEY_RIGHT + (rand() % 4);
        }
    }
    if (rand() % 100 == 1) // 1% de chance do inimigo mudar de direcao
        e->direction = KEY_RIGHT + (rand() % 4);
}
