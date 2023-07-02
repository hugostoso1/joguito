#include "../raylib.h"
#include <stdlib.h>
#include "../game/game.h"

void draw_map(Game *g)
{
    Map *map = &g->maps[g->curr_map];
    for (int i = 0; i < map->num_barriers; i++)
    {
        DrawRectangleRec(map->barriers[i], GOLD);
    }

    if (map->door_locked)
        DrawRectangleRec(map->door, RED);
    else
        DrawRectangleRec(map->door, GREEN);

    if (map->prev_map != -1)
    {
        DrawRectangleRec(map->prev_door, GREEN);
    }

    for (int i = 0; i < map->num_enemies; i++)
    {
        if (!map->enemies[i].draw_enemy)
            continue;
        DrawRectangleRec(map->enemies[i].pos, map->enemies[i].color);
    }

    if (map->draw_special_item)
        DrawRectangleRec(map->special_item, PURPLE);
}

void map0_setup(Game *g)
{
    g->maps[0].num_barriers = 1;
    g->maps[0].barriers[0] = (Rectangle){g->screenWidth / 2, g->screenHeight/10, 20, 0.8 * g->screenHeight};
    g->maps[0].color = BLACK;
    g->maps[0].door = (Rectangle){g->screenWidth - (SCREEN_BORDER + 5), g->screenHeight / 3, SCREEN_BORDER, 50};
    g->maps[0].num_enemies = 4;
    g->maps[0].door_locked = 1;

    for (int i = 0; i < g->maps[0].num_enemies; i++)
    {
        g->maps[0].enemies[i].pos = (Rectangle){2 * g->screenWidth / 3, 2 * g->screenHeight / 3, STD_SIZE_X, STD_SIZE_Y};
        g->maps[0].enemies[i].color = BLUE;
        g->maps[0].enemies[i].speed = 1;
        g->maps[0].enemies[i].direction = KEY_RIGHT + (rand() % 4);
        g->maps[0].enemies[i].draw_enemy = 1;
        g->maps[0].enemies[i].has_key = 0;
        g->maps[0].enemies[i].enemyBullet.default_pos = (Rectangle){5000,5000,45,15};
        g->maps[0].enemies[i].enemyBullet.active = 0;
        g->maps[0].enemies[i].enemyBullet.color = RED;
        g->maps[0].enemies[i].enemyBullet.speed = 15;
        g->maps[0].enemies[i].enemyBullet.direction = KEY_LEFT;
        g->maps[0].enemies[i].enemyBullet2.default_pos = (Rectangle){5100,5100,45,15};
        g->maps[0].enemies[i].enemyBullet2.active = 0;
        g->maps[0].enemies[i].enemyBullet2.color = RED;
        g->maps[0].enemies[i].enemyBullet2.speed = 10;
        g->maps[0].enemies[i].enemyBullet2.direction = KEY_LEFT;
    }
    g->maps[0].enemies[rand()%5].has_key = 1;
    g->maps[0].special_item = (Rectangle){2 * g->screenWidth / 3, 20, 15, 15};
    g->maps[0].draw_special_item = 1;
    g->maps[0].prev_map = -1;
    g->maps[0].next_map = 1;
}

void map1_setup(Game *g)
{
    g->maps[1].num_barriers = 2;
    g->maps[1].barriers[0] = (Rectangle){3 * g->screenWidth / 4, 0, 15, 0.6 * g->screenHeight};
    g->maps[1].barriers[1] = (Rectangle){g->screenWidth / 4, 0.4 * g->screenHeight, 15, g->screenHeight};
    g->maps[1].color = BLACK;
    g->maps[1].door = (Rectangle){g->screenWidth - (SCREEN_BORDER + 5), g->screenHeight / 3, SCREEN_BORDER, 50};
    g->maps[1].prev_door = (Rectangle){SCREEN_BORDER, g->screenHeight / 3, 5, 50};
    g->maps[1].num_enemies = 8;
    g->maps[1].door_locked = 1;
    for (int i = 0; i < g->maps[1].num_enemies; i++)
    {
        g->maps[1].enemies[i].pos = (Rectangle){2 * g->screenWidth / 3, 2 * g->screenHeight / 3, STD_SIZE_X, STD_SIZE_Y};
        g->maps[1].enemies[i].color = BLUE;
        g->maps[1].enemies[i].speed = 10;
        g->maps[1].enemies[i].direction = KEY_RIGHT + (rand() % 4);
        g->maps[1].enemies[i].draw_enemy = 1;
        g->maps[1].enemies[i].has_key = 0;
        g->maps[1].enemies[i].enemyBullet.default_pos = (Rectangle){5000,5000,45,15};
        g->maps[1].enemies[i].enemyBullet.active = 0;
        g->maps[1].enemies[i].enemyBullet.color = RED;
        g->maps[1].enemies[i].enemyBullet.speed = 1;
        g->maps[1].enemies[i].enemyBullet.direction = KEY_LEFT;
        g->maps[1].enemies[i].enemyBullet2.default_pos = (Rectangle){5100,5100,45,15};
        g->maps[1].enemies[i].enemyBullet2.active = 0;
        g->maps[1].enemies[i].enemyBullet2.color = RED;
        g->maps[1].enemies[i].enemyBullet2.speed = 2;
        g->maps[1].enemies[i].enemyBullet2.direction = KEY_LEFT;
    }
    g->maps[1].enemies[rand()%9].has_key = 1;
    g->maps[1].special_item = (Rectangle){4 * g->screenWidth / 5, 20, 15, 15};
    g->maps[1].draw_special_item = 1;
    g->maps[1].prev_map = 0;
    g->maps[1].next_map = 2;
}

void map2_setup(Game *g)
{
    g->maps[2].num_barriers = 3;
    g->maps[2].barriers[0] = (Rectangle){g->screenWidth / 4, 0, 2, 0.6 * g->screenHeight};
    g->maps[2].barriers[1] = (Rectangle){2 * g->screenWidth / 4, 0, 2, 0.6 * g->screenHeight};
    g->maps[2].barriers[2] = (Rectangle){3 * g->screenWidth / 4, 0, 2, 0.6 * g->screenHeight};
    g->maps[2].color = BLACK;
    g->maps[2].door = (Rectangle){g->screenWidth - (SCREEN_BORDER + 5), g->screenHeight / 3, SCREEN_BORDER, 50};
    g->maps[2].prev_door = (Rectangle){SCREEN_BORDER, g->screenHeight / 3, 5, 50};
    g->maps[2].num_enemies = 4;
    g->maps[2].door_locked = 1;
    for (int i = 0; i < g->maps[2].num_enemies; i++)
    {
        g->maps[2].enemies[i].pos = (Rectangle){2 * g->screenWidth / 3, 2 * g->screenHeight / 3, STD_SIZE_X, STD_SIZE_Y};
        g->maps[2].enemies[i].color = BLUE;
        g->maps[2].enemies[i].speed = 6;
        g->maps[2].enemies[i].direction = KEY_RIGHT + (rand() % 4);
        g->maps[2].enemies[i].draw_enemy = 1;
        g->maps[2].enemies[i].has_key = 0;
        g->maps[2].enemies[i].enemyBullet.default_pos = (Rectangle){5000,5000,45,15};
        g->maps[2].enemies[i].enemyBullet.active = 0;
        g->maps[2].enemies[i].enemyBullet.color = RED;
        g->maps[2].enemies[i].enemyBullet.speed = 7;
        g->maps[2].enemies[i].enemyBullet.direction = KEY_LEFT;
        g->maps[2].enemies[i].enemyBullet2.default_pos = (Rectangle){5100,5100,45,15};
        g->maps[2].enemies[i].enemyBullet2.active = 0;
        g->maps[2].enemies[i].enemyBullet2.color = RED;
        g->maps[2].enemies[i].enemyBullet2.speed = 7;
        g->maps[2].enemies[i].enemyBullet2.direction = KEY_LEFT;
    }
    g->maps[2].enemies[rand()%3].has_key = 1;
    g->maps[2].special_item = (Rectangle){4 * g->screenWidth / 5, 20, 15, 15};
    g->maps[2].draw_special_item = 1;
    g->maps[2].prev_map = 1;
    g->maps[2].next_map = 3;
}

void map3_setup(Game *g){
    g->maps[3].num_barriers = 5;
    g->maps[3].barriers[0] = (Rectangle) {g->screenWidth/6, 0, 10, 0.3 * g->screenHeight};
    g->maps[3].barriers[1] = (Rectangle) {2*g->screenWidth/6, 0.7 * g->screenHeight, 10, g->screenHeight};
    g->maps[3].barriers[2] = (Rectangle) {3*g->screenWidth/6, 0, 10, 0.3 * g->screenHeight};
    g->maps[3].barriers[3] = (Rectangle) {4*g->screenWidth/6, 0.7 * g->screenHeight, 10, g->screenHeight};
    g->maps[3].barriers[4] = (Rectangle) {5*g->screenWidth/6, 0, 10, 0.3 * g->screenHeight};
    g->maps[3].color = BLACK;
    g->maps[3].door = (Rectangle) {g->screenWidth-(SCREEN_BORDER+5), g->screenHeight/6, SCREEN_BORDER, 50};
    g->maps[3].prev_door = (Rectangle) {SCREEN_BORDER, g->screenHeight/2, 5, 50};
    g->maps[3].num_enemies = 3;
    g->maps[3].door_locked = 1;
    for(int i=0; i< g->maps[3].num_enemies; i++){
        g->maps[3].enemies[i].pos = (Rectangle) { 2*g->screenWidth/3, 2*g->screenHeight/3, STD_SIZE_X, STD_SIZE_Y};
        g->maps[3].enemies[i].color = BLUE;
        g->maps[3].enemies[i].speed = 7;
        g->maps[3].enemies[i].direction = KEY_RIGHT + (rand() % 4);
        g->maps[3].enemies[i].draw_enemy = 1;
        g->maps[3].enemies[i].has_key = 0;
        g->maps[3].enemies[i].enemyBullet.default_pos = (Rectangle){5000,5000,45,15};
        g->maps[3].enemies[i].enemyBullet.active = 0;
        g->maps[3].enemies[i].enemyBullet.color = RED;
        g->maps[3].enemies[i].enemyBullet.speed = 7;
        g->maps[3].enemies[i].enemyBullet.direction = KEY_LEFT;
        g->maps[3].enemies[i].enemyBullet2.default_pos = (Rectangle){5100,5100,45,15};
        g->maps[3].enemies[i].enemyBullet2.active = 0;
        g->maps[3].enemies[i].enemyBullet2.color = RED;
        g->maps[3].enemies[i].enemyBullet2.speed = 7;
        g->maps[3].enemies[i].enemyBullet2.direction = KEY_LEFT;
    }
    g->maps[3].enemies[rand()%2].has_key = 1;
    g->maps[3].special_item = (Rectangle) {4*g->screenWidth/5, 20, 15, 15};
    g->maps[3].draw_special_item = 1;
    g->maps[3].prev_map = 2;
    g->maps[3].next_map = 4;
}

void map4_setup(Game *g){
    g->maps[4].num_barriers = 3;
    g->maps[4].barriers[0] = (Rectangle) {200, g->screenHeight/2 - 10, g->screenWidth/6, 20};
    g->maps[4].barriers[1] = (Rectangle) {375 + g->screenWidth/6, g->screenHeight/2 - 10, g->screenWidth/6, 20};
    g->maps[4].barriers[2] = (Rectangle) {375 + (2*g->screenWidth/6), g->screenHeight/2 - 10, g->screenWidth/6, 20};
    g->maps[4].color = BLACK;
    g->maps[4].door = (Rectangle) {g->screenWidth-(SCREEN_BORDER+5), 0.15 * g->screenHeight, SCREEN_BORDER, 50};
    g->maps[4].prev_door = (Rectangle) {SCREEN_BORDER, 0.85 * g->screenHeight, 5, 50};
    g->maps[4].num_enemies = 5;
    g->maps[4].door_locked = 1;
    for(int i=0; i< g->maps[4].num_enemies; i++){
        g->maps[4].enemies[i].pos = (Rectangle) { 0.4*g->screenWidth, 0.15*g->screenHeight, STD_SIZE_X, STD_SIZE_Y};
        g->maps[4].enemies[i].color = BLUE;
        g->maps[4].enemies[i].speed = 5;
        g->maps[4].enemies[i].direction = KEY_RIGHT + (rand() % 4);
        g->maps[4].enemies[i].draw_enemy = 1;
        g->maps[4].enemies[i].has_key = 0;
        g->maps[4].enemies[i].enemyBullet.default_pos = (Rectangle){5000,5000,45,15};
        g->maps[4].enemies[i].enemyBullet.active = 0;
        g->maps[4].enemies[i].enemyBullet.color = RED;
        g->maps[4].enemies[i].enemyBullet.speed = 7;
        g->maps[4].enemies[i].enemyBullet.direction = KEY_LEFT;
        g->maps[4].enemies[i].enemyBullet2.default_pos = (Rectangle){5100,5100,45,15};
        g->maps[4].enemies[i].enemyBullet2.active = 0;
        g->maps[4].enemies[i].enemyBullet2.color = RED;
        g->maps[4].enemies[i].enemyBullet2.speed = 7;
        g->maps[4].enemies[i].enemyBullet2.direction = KEY_LEFT;
    }
    g->maps[4].enemies[rand()%6].has_key = 1;
    g->maps[4].special_item = (Rectangle) {g->screenWidth/2, 0.42*g->screenHeight, 15, 15};
    g->maps[4].draw_special_item = 1;
    g->maps[4].prev_map = 3;
    g->maps[4].next_map = 5;
}

void map5_setup(Game *g){
    g->maps[5].num_barriers = 4;
    g->maps[5].barriers[0] = (Rectangle) {g->screenWidth/5, 0.57 * g->screenHeight, 30, 0.47 * g->screenHeight};
    g->maps[5].barriers[1] = (Rectangle) {2*g->screenWidth, 100, 30, 0.47 * g->screenHeight};
    g->maps[5].barriers[2] = (Rectangle) {3*g->screenWidth/5, 0.57 * g->screenHeight, 30, 0.47 * g->screenHeight};
    g->maps[5].barriers[3] = (Rectangle) {2*g->screenWidth, 100, 30, 0.47 * g->screenHeight};
    g->maps[5].color = BLACK;
    g->maps[5].door = (Rectangle) {g->screenWidth-(SCREEN_BORDER+5), g->screenHeight/2 - SCREEN_BORDER/2, SCREEN_BORDER, 50};
    g->maps[5].prev_door = (Rectangle) {SCREEN_BORDER, g->screenHeight/2 - SCREEN_BORDER/2, 5, 50};
    g->maps[5].num_enemies = 4;
    g->maps[5].door_locked = 1;
    for(int i=0; i< g->maps[5].num_enemies; i++){
        g->maps[5].enemies[i].pos = (Rectangle) { 0.4*g->screenWidth, 0.15*g->screenHeight, STD_SIZE_X, STD_SIZE_Y};
        g->maps[5].enemies[i].color = BLUE;
        g->maps[5].enemies[i].speed = 6;
        g->maps[5].enemies[i].direction = KEY_RIGHT + (rand() % 4);
        g->maps[5].enemies[i].draw_enemy = 1;
        g->maps[5].enemies[i].has_key = 0;
        g->maps[5].enemies[i].enemyBullet.default_pos = (Rectangle){5000,5000,45,15};
        g->maps[5].enemies[i].enemyBullet.active = 0;
        g->maps[5].enemies[i].enemyBullet.color = RED;
        g->maps[5].enemies[i].enemyBullet.speed = 8;
        g->maps[5].enemies[i].enemyBullet.direction = KEY_LEFT;
        g->maps[5].enemies[i].enemyBullet2.default_pos = (Rectangle){5100,5100,45,15};
        g->maps[5].enemies[i].enemyBullet2.active = 0;
        g->maps[5].enemies[i].enemyBullet2.color = RED;
        g->maps[5].enemies[i].enemyBullet2.speed = 9;
        g->maps[5].enemies[i].enemyBullet2.direction = KEY_LEFT;
    }
    g->maps[5].enemies[0].has_key = 1;
    g->maps[5].special_item = (Rectangle) {g->screenWidth/2,g->screenHeight/2, 15, 15};
    g->maps[5].draw_special_item = 1;
    g->maps[5].prev_map = 4;
    g->maps[5].next_map = 6;
}

void map6_setup(Game *g){
    g->maps[6].num_barriers = 2;
    g->maps[6].barriers[0] = (Rectangle) {g->screenWidth/5, g->screenHeight/2 - 50, 100, 100};
    g->maps[6].barriers[1] = (Rectangle) {2*(g->screenWidth/5 + 100), g->screenHeight/2 - 50, 100, 100};
    g->maps[6].color = BLACK;
    g->maps[6].door = (Rectangle) {g->screenWidth/2-25, g->screenHeight - SCREEN_BORDER, 50, SCREEN_BORDER};
    g->maps[6].prev_door = (Rectangle) {g->screenWidth/2 - 25, SCREEN_BORDER, 50, SCREEN_BORDER};
    g->maps[6].num_enemies = 5;
    g->maps[6].door_locked = 1;
    for(int i=0; i< g->maps[6].num_enemies; i++){
        int range = 0;
        int collision = 0;
        do{
          g->maps[6].enemies[i].pos = (Rectangle) {SCREEN_BORDER + (rand() % (g->screenWidth-STD_SIZE_X)), SCREEN_BORDER + (rand() % (g->screenWidth-STD_SIZE_Y)), STD_SIZE_X, STD_SIZE_Y};
          int x = g->hero.pos.x - g->maps[6].enemies[i].pos.x;
          int y = g->hero.pos.y - g->maps[6].enemies[i].pos.y;
          x = (x >= -15 && x <= 15) ?  1 :  0;
          y = (y >= -15 && y <= 15) ?  1 :  0;
          range = (x && y) ? 1 : 0;
          collision = barrier_collision(&g->maps[6], &g->maps[6].enemies[i].pos);
        } while(range || collision);
        g->maps[6].enemies[i].color = BLUE;
        g->maps[6].enemies[i].speed = 6;
        g->maps[6].enemies[i].direction = KEY_RIGHT + (rand() % 4);
        g->maps[6].enemies[i].draw_enemy = 1;
        g->maps[6].enemies[i].has_key = 0;
        g->maps[6].enemies[i].enemyBullet.default_pos = (Rectangle){5000,5000,45,15};
        g->maps[6].enemies[i].enemyBullet.active = 0;
        g->maps[6].enemies[i].enemyBullet.color = RED;
        g->maps[6].enemies[i].enemyBullet.speed = 7;
        g->maps[6].enemies[i].enemyBullet.direction = KEY_LEFT;
        g->maps[6].enemies[i].enemyBullet2.default_pos = (Rectangle){5100,5100,45,15};
        g->maps[6].enemies[i].enemyBullet2.active = 7;
        g->maps[6].enemies[i].enemyBullet2.color = RED;
        g->maps[6].enemies[i].enemyBullet2.speed = 9;
        g->maps[6].enemies[i].enemyBullet2.direction = KEY_LEFT;
    }
    g->maps[6].enemies[0].has_key = 1;
    g->maps[6].special_item = (Rectangle) {g->screenWidth/2,g->screenHeight/2, 15, 15};
    g->maps[6].draw_special_item = 1;
    g->maps[6].prev_map = 5;
    g->maps[6].next_map = 7;
}

void map8_setup(Game *g){
    g->maps[8].num_barriers = 4;
    g->maps[8].barriers[0] = (Rectangle) {g->screenWidth/5 , (g->screenHeight/2) - 10, g->screenHeight/4, 10};
    g->maps[8].barriers[1] = (Rectangle) {g->screenWidth/2 + g->screenWidth/5, (g->screenHeight/2) - 10, g->screenHeight/4, 10};
    g->maps[8].barriers[2] = (Rectangle) {g->screenWidth/2,g->screenHeight/8, 10, g->screenHeight/4};
    g->maps[8].barriers[3] = (Rectangle) {g->screenWidth/2,g->screenHeight/2 + g->screenHeight/8, 10, g->screenHeight/4};
    g->maps[8].color = GRAY;
    g->maps[8].num_enemies = 5;
    for(int i = 0; i < g->maps[8].num_enemies; i++) {
        g->maps[8].enemies[i].color = BLUE;
        g->maps[8].enemies[i].speed = 6;
        g->maps[8].enemies[i].direction = KEY_RIGHT + (rand() % 4);
        g->maps[8].enemies[i].draw_enemy = 0;
        g->maps[8].enemies[i].has_key = 0;
        g->maps[8].enemies[i].enemyBullet.default_pos = (Rectangle){5000,5000,45,15};
        g->maps[8].enemies[i].enemyBullet.active = 0;
        g->maps[8].enemies[i].enemyBullet.color = RED;
        g->maps[8].enemies[i].enemyBullet.speed = 7;
        g->maps[8].enemies[i].enemyBullet.direction = KEY_LEFT;
        g->maps[8].enemies[i].enemyBullet2.default_pos = (Rectangle){5100,5100,45,15};
        g->maps[8].enemies[i].enemyBullet2.active = 0;
        g->maps[8].enemies[i].enemyBullet2.color = RED;
        g->maps[8].enemies[i].enemyBullet2.speed = 7;
        g->maps[8].enemies[i].enemyBullet2.direction = KEY_LEFT;
    }
    g->boss.life = 10;
    g->boss.dead = 0;
    g->boss.pos = (Rectangle) {g->screenWidth/2 - 75, g->screenHeight/2 - 75, 80, 80};
    g->boss.color = GREEN;
    g->boss.speed = 5;
    g->boss.direction = KEY_RIGHT + (rand() % 4);
    g->boss.draw = 1;
    g->boss.bossBullet.active = 0;
    g->boss.bossBullet.color = GREEN;
    g->boss.bossBullet.default_pos = (Rectangle){5000,5000,45,15};
    g->boss.bossBullet.speed = 10;
    g->boss.bossBullet2.active = 0;
    g->boss.bossBullet2.color = GREEN;
    g->boss.bossBullet2.default_pos = (Rectangle){5000,5000,45,15};
    g->boss.bossBullet2.speed = 10;

}

void resetMap(Game *g){
    switch(g->curr_map){
        case 0:
            g->hero.pos = (Rectangle){150, 300, STD_SIZE_X, STD_SIZE_Y};
            map0_setup(g);
            break;
                
        case 1:
            g->hero.pos = (Rectangle){STD_SIZE_X, g->screenHeight / 3, STD_SIZE_X, STD_SIZE_Y};
            map1_setup(g);
            break;
                
        case 2:
            g->hero.pos = (Rectangle){STD_SIZE_X, g->screenHeight / 3, STD_SIZE_X, STD_SIZE_Y};
            map2_setup(g);
            break;

        case 3:
            g->hero.pos = (Rectangle){STD_SIZE_X, g->screenHeight / 3, STD_SIZE_X, STD_SIZE_Y};
            map3_setup(g);
            break;
        
        case 4:
            g->hero.pos = (Rectangle) {STD_SIZE_X + 5, 0.85 * g->screenHeight, STD_SIZE_X, STD_SIZE_Y};
            map4_setup(g);
            break;

        case 5:
            g->hero.pos = (Rectangle) {STD_SIZE_X + 5, g->screenHeight/2 - STD_SIZE_Y/2, 5, 50};
            map5_setup(g);
            break;

        case 6:
            g->hero.pos = (Rectangle) {g->screenWidth/2 - STD_SIZE_X/2, STD_SIZE_Y + 5, STD_SIZE_X, STD_SIZE_Y};
            map6_setup(g);
            break;
                
        case 8:
            g->gameover = 1;
            break;
      }
}