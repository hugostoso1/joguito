#include "../raylib.h"
#include <stdlib.h>
#include "../game/game.h"

void draw_map(Game *g)
{
    Map *map = &g->maps[g->curr_map];
    for (int i = 0; i < map->num_barriers; i++)
    {
        DrawRectangleRec(map->barriers[i], BLACK);
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
        DrawRectangleRec(map->enemies[i].pos, PINK);
    }

    if (map->draw_special_item)
        DrawRectangleRec(map->special_item, PURPLE);
}

void map0_setup(Game *g)
{
    g->maps[0].num_barriers = 1;
    g->maps[0].barriers[0] = (Rectangle){g->screenWidth / 2, 0, 2, 0.8 * g->screenHeight};
    g->maps[0].color = GRAY;
    g->maps[0].door = (Rectangle){g->screenWidth - (SCREEN_BORDER + 5), g->screenHeight / 3, SCREEN_BORDER, 50};
    g->maps[0].num_enemies = 2;
    g->maps[0].door_locked = 1;

    for (int i = 0; i < g->maps[0].num_enemies; i++)
    {
        g->maps[0].enemies[i].pos = (Rectangle){2 * g->screenWidth / 3, 2 * g->screenHeight / 3, STD_SIZE_X, STD_SIZE_Y};
        g->maps[0].enemies[i].color = BLACK;
        g->maps[0].enemies[i].speed = 1;
        g->maps[0].enemies[i].direction = KEY_RIGHT + (rand() % 4);
        g->maps[0].enemies[i].draw_enemy = 1;
        g->maps[0].enemies[i].has_key = 0;
        g->maps[0].enemies[i].enemyBullet.default_pos = (Rectangle){5000,5000,45,15};
        g->maps[0].enemies[i].enemyBullet.active = 0;
        g->maps[0].enemies[i].enemyBullet.color = RED;
        g->maps[0].enemies[i].enemyBullet.speed = 10;
        g->maps[0].enemies[i].enemyBullet.direction = KEY_LEFT;
        g->maps[0].enemies[i].enemyBullet2.default_pos = (Rectangle){5100,5100,45,15};
        g->maps[0].enemies[i].enemyBullet2.active = 0;
        g->maps[0].enemies[i].enemyBullet2.color = RED;
        g->maps[0].enemies[i].enemyBullet2.speed = 7;
        g->maps[0].enemies[i].enemyBullet2.direction = KEY_LEFT;
    }
    g->maps[0].enemies[0].has_key = 1;
    g->maps[0].special_item = (Rectangle){2 * g->screenWidth / 3, 20, 15, 15};
    g->maps[0].draw_special_item = 1;
    g->maps[0].prev_map = -1;
    g->maps[0].next_map = 1;
}

void map1_setup(Game *g)
{
    g->maps[1].num_barriers = 2;
    g->maps[1].barriers[0] = (Rectangle){3 * g->screenWidth / 4, 0, 2, 0.6 * g->screenHeight};
    g->maps[1].barriers[1] = (Rectangle){g->screenWidth / 4, 0.4 * g->screenHeight, 2, g->screenHeight};
    g->maps[1].color = GRAY;
    g->maps[1].door = (Rectangle){g->screenWidth - (SCREEN_BORDER + 5), g->screenHeight / 3, SCREEN_BORDER, 50};
    g->maps[1].prev_door = (Rectangle){SCREEN_BORDER, g->screenHeight / 3, 5, 50};
    g->maps[1].num_enemies = 3;
    g->maps[1].door_locked = 1;
    

    for (int i = 0; i < g->maps[1].num_enemies; i++)
    {
        g->maps[1].enemies[i].pos = (Rectangle){2 * g->screenWidth / 3, 2 * g->screenHeight / 3, STD_SIZE_X, STD_SIZE_Y};
        g->maps[1].enemies[i].color = BLACK;
        g->maps[1].enemies[i].speed = 6;
        g->maps[1].enemies[i].direction = KEY_RIGHT + (rand() % 4);
        g->maps[1].enemies[i].draw_enemy = 1;
        g->maps[1].enemies[i].has_key = 0;
        g->maps[1].enemies[i].enemyBullet.default_pos = (Rectangle){5000,5000,45,15};
        g->maps[1].enemies[i].enemyBullet.active = 0;
        g->maps[1].enemies[i].enemyBullet.color = RED;
        g->maps[1].enemies[i].enemyBullet.speed = 7;
        g->maps[1].enemies[i].enemyBullet.direction = KEY_LEFT;
        g->maps[1].enemies[i].enemyBullet2.default_pos = (Rectangle){5100,5100,45,15};
        g->maps[1].enemies[i].enemyBullet2.active = 0;
        g->maps[1].enemies[i].enemyBullet2.color = RED;
        g->maps[1].enemies[i].enemyBullet2.speed = 7;
        g->maps[1].enemies[i].enemyBullet2.direction = KEY_LEFT;
    }
    g->maps[1].enemies[0].has_key = 1;
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
    g->maps[2].color = GRAY;
    g->maps[2].door = (Rectangle){g->screenWidth - (SCREEN_BORDER + 5), g->screenHeight / 3, SCREEN_BORDER, 50};
    g->maps[2].prev_door = (Rectangle){SCREEN_BORDER, g->screenHeight / 3, 5, 50};
    g->maps[2].num_enemies = 4;
    g->maps[2].door_locked = 1;

    for (int i = 0; i < g->maps[2].num_enemies; i++)
    {
        g->maps[2].enemies[i].pos = (Rectangle){2 * g->screenWidth / 3, 2 * g->screenHeight / 3, STD_SIZE_X, STD_SIZE_Y};
        g->maps[2].enemies[i].color = BLACK;
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
    g->maps[2].enemies[0].has_key = 1;
    g->maps[2].special_item = (Rectangle){4 * g->screenWidth / 5, 20, 15, 15};
    g->maps[2].draw_special_item = 1;
    g->maps[2].prev_map = 1;
    g->maps[2].next_map = 3;
}

void map3_setup(Game *g){
    g->maps[3].num_barriers = 5;
    g->maps[3].barriers[0] = (Rectangle) {g->screenWidth/6, 0, 2, 0.3 * g->screenHeight};
    g->maps[3].barriers[1] = (Rectangle) {2*g->screenWidth/6, 0.7 * g->screenHeight, 2, g->screenHeight};
    g->maps[3].barriers[2] = (Rectangle) {3*g->screenWidth/6, 0, 2, 0.3 * g->screenHeight};
    g->maps[3].barriers[3] = (Rectangle) {4*g->screenWidth/6, 0.7 * g->screenHeight, 2, g->screenHeight};
    g->maps[3].barriers[4] = (Rectangle) {5*g->screenWidth/6, 0, 2, 0.3 * g->screenHeight};
    g->maps[3].color = GRAY;
    g->maps[3].door = (Rectangle) {g->screenWidth-(SCREEN_BORDER+5), g->screenHeight/6, SCREEN_BORDER, 50};
    g->maps[3].prev_door = (Rectangle) {SCREEN_BORDER, g->screenHeight/2, 5, 50};
    g->maps[3].num_enemies = 3;
    g->maps[3].door_locked = 1;


    for(int i=0; i< g->maps[3].num_enemies; i++){
        g->maps[3].enemies[i].pos = (Rectangle) { 2*g->screenWidth/3, 2*g->screenHeight/3, STD_SIZE_X, STD_SIZE_Y};
        g->maps[3].enemies[i].color = BLACK;
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
    g->maps[3].enemies[0].has_key = 1;
    g->maps[3].special_item = (Rectangle) {4*g->screenWidth/5, 20, 15, 15};
    g->maps[3].draw_special_item = 1;
    g->maps[3].prev_map = 2;
    g->maps[3].next_map = 8;
}

void map8_setup(Game *g){
    g->maps[8].num_barriers = 4;
    g->maps[8].barriers[0] = (Rectangle) {g->screenWidth/6, 0, 2, 0.3 * g->screenHeight};
    g->maps[8].barriers[1] = (Rectangle) {2*g->screenWidth/6, 0.7 * g->screenHeight, 2, g->screenHeight};
    g->maps[8].barriers[2] = (Rectangle) {3*g->screenWidth/6, 0, 2, 0.3 * g->screenHeight};
    g->maps[8].barriers[8] = (Rectangle) {4*g->screenWidth/6, 0.7 * g->screenHeight, 2, g->screenHeight};
    g->maps[8].color = GRAY;
    g->maps[8].door = (Rectangle) {g->screenWidth-(SCREEN_BORDER+5), g->screenHeight/6, SCREEN_BORDER, 50};
    g->maps[8].prev_door = (Rectangle) {SCREEN_BORDER, g->screenHeight/2, 5, 50};
    g->maps[8].num_enemies = 3;
    g->maps[8].door_locked = 1;


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

            }
}
