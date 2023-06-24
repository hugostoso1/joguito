#include "../raylib.h"
#include <stdlib.h>
#include "../game/game.h"

void update_enemy_pos(Game *g, Enemy *e)
{
    Map *m = &g->maps[g->curr_map];
    int x = g->hero.pos.x - e->pos.x;
    int y = g->hero.pos.y - e->pos.y;
    
    if(x==0){
        e->enemyBullet.direction = (y>0) ? KEY_UP : KEY_DOWN;   
        e->enemyBullet.pos = (Rectangle){e->enemyBullet.pos.x,e->enemyBullet.pos.y,15,45};
        shootEnemy(&e->enemyBullet,&e->pos,g);     
    }
    if(y==0){
        e->enemyBullet.direction = (x>0) ? KEY_RIGHT : KEY_LEFT;  
        e->enemyBullet.pos = (Rectangle){e->enemyBullet.pos.x,e->enemyBullet.pos.y,45,15};
        shootEnemy(&e->enemyBullet,&e->pos,g); 
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
