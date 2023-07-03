#include "../raylib.h"
#include "./game.h"
#include <stdlib.h>

int hasEnemies(Game *g) {
    Map *map = &g->maps[g->curr_map];
    for (int i = 0; i < map->num_enemies; i++) {
        if (map->enemies[i].draw_enemy)
            return 1;
    }
    return 0; //n tem
}

void InitGame(Game *g)
{
    g->curr_map = 0;
    g->num_maps = 10;
    g->hero.pos = (Rectangle){150, 300, STD_SIZE_X, STD_SIZE_Y};
    g->hero.color = WHITE;
    g->hero.speed = 15;
    g->hero.special = 0;

    g->hero.bullet.default_pos = (Rectangle){5500,5500,45,10};
    g->hero.bullet.direction = KEY_RIGHT;
    g->hero.bullet.color = PURPLE;
    g->hero.bullet.speed = 20;
    g->hero.bullet.active = 0;
    g->hero.bullet2.default_pos = (Rectangle){5500,5500,45,10};
    g->hero.bullet2.direction = KEY_RIGHT;
    g->hero.bullet2.color = PURPLE;
    g->hero.bullet2.speed = 20;
    g->hero.bullet2.active = 0;
    g->gameover = 0;
    
    g->score = 0;
    map0_setup(g);
    map1_setup(g);
    map2_setup(g);
    map3_setup(g);
    map4_setup(g);
    map5_setup(g);
    map6_setup(g);
    map7_setup(g);
    map8_setup(g);
}

void UpdateGame(Game *g)
{
    update_hero_pos(g);
    shoot(&g->hero, &g->hero.pos, g);
   
    Map *map = &g->maps[g->curr_map];
    for (int i=0; i < map->num_enemies; i++)
    {
        update_enemy_pos(g, &map->enemies[i]);

        if (CheckCollisionRecs(g->hero.bullet.pos, map->enemies[i].pos))
        {
            map->enemies[i].draw_enemy = 0;    
            map->enemies[i].pos = (Rectangle){4500,4000,1,1};
            map->enemies[i].enemyBullet.pos = map->enemies[i].enemyBullet.default_pos;
            map->enemies[i].enemyBullet.active = 0;
            map->enemies[i].enemyBullet2.pos = map->enemies[i].enemyBullet2.default_pos;
            map->enemies[i].enemyBullet2.active = 0;
            g->hero.bullet.active = 0;
            g->hero.bullet.pos = g->hero.bullet.default_pos;
            if (map->enemies[i].has_key)
            {
                map->door_locked = 0;
            }
        }

        if (CheckCollisionRecs(g->hero.bullet2.pos, map->enemies[i].pos))
        {
            map->enemies[i].draw_enemy = 0;    
            map->enemies[i].pos = (Rectangle){4500,4000,1,1};
            map->enemies[i].enemyBullet.pos = map->enemies[i].enemyBullet.default_pos;
            map->enemies[i].enemyBullet.active = 0;
            map->enemies[i].enemyBullet2.pos = map->enemies[i].enemyBullet2.default_pos;
            map->enemies[i].enemyBullet2.active = 0;   
            g->hero.bullet2.active = 0;
            g->hero.bullet2.pos = g->hero.bullet2.default_pos;
            if (map->enemies[i].has_key)
            {
                map->door_locked = 0;
            }
        }

        bulletCollison(&map->enemies[i].enemyBullet, &g->hero.bullet);
        bulletCollison(&map->enemies[i].enemyBullet2, &g->hero.bullet);
        bulletCollison(&map->enemies[i].enemyBullet2, &g->hero.bullet2); 
        bulletCollison(&map->enemies[i].enemyBullet, &g->hero.bullet2);       

        if (map->enemies[i].enemyBullet.active && CheckCollisionRecs(map->enemies[i].enemyBullet.pos, g->hero.pos)){
            map->enemies[i].enemyBullet.pos = map->enemies[i].enemyBullet.default_pos;
            if(!g->hero.special) {
                if(g->curr_map == 8)
                g->gameover = 1;
                resetMap(g);
                continue;
            }
        }

        if (map->enemies[i].enemyBullet2.active && CheckCollisionRecs(map->enemies[i].enemyBullet2.pos, g->hero.pos) && (g->mode == 'H')){
            map->enemies[i].enemyBullet2.pos = map->enemies[i].enemyBullet2.default_pos;
            if(!g->hero.special) {
                if(g->curr_map == 8)
                g->gameover = 1;
                resetMap(g);
                continue;
            }
        }

        if (!CheckCollisionRecs(g->hero.pos, map->enemies[i].pos)){
            continue;

        }
        
        if (g->hero.special)
        {
            map->enemies[i].draw_enemy = 0;
            if (map->enemies[i].has_key)
            {
                map->door_locked = 0;
            }
            continue;
        }
        if(g->curr_map != 8){
            if(!hasEnemies(g))
            continue;
            resetMap(g);
        }
    }

    if (CheckCollisionRecs(g->hero.pos, map->special_item) && map->draw_special_item)
    {
        g->hero.pos.width += 10;
        g->hero.pos.height += 10;
        g->hero.special = 1;
        map->draw_special_item = 0;
    }

    if (CheckCollisionRecs(g->hero.pos, map->door) && !map->door_locked)
    {
        g->curr_map = map->next_map;
        float x = (g->maps[g->curr_map].prev_door.x >= g->screenWidth/2) ? g->maps[g->curr_map].prev_door.x - STD_SIZE_X: g->maps[g->curr_map].prev_door.x + STD_SIZE_X;
        float y = (g->maps[g->curr_map].prev_door.y >= g->screenHeight/2) ? g->maps[g->curr_map].prev_door.y - STD_SIZE_Y: g->maps[g->curr_map].prev_door.y + STD_SIZE_Y;
        g->hero.pos = (Rectangle){x, y, STD_SIZE_X, STD_SIZE_Y};
        g->hero.special = 0;
    }

    if (map->prev_map != -1 && CheckCollisionRecs(g->hero.pos, map->prev_door))
    {
        g->curr_map = map->prev_map;
        float x = (g->maps[g->curr_map].door.x >= g->screenWidth/2) ? g->maps[g->curr_map].door.x - STD_SIZE_X: g->maps[g->curr_map].door.x + STD_SIZE_X;
        float y = (g->maps[g->curr_map].door.y >= g->screenHeight/2) ? g->maps[g->curr_map].door.y - STD_SIZE_Y: g->maps[g->curr_map].door.y + STD_SIZE_Y;
        g->hero.pos = (Rectangle){x, y, STD_SIZE_X, STD_SIZE_Y};
        g->hero.special = 0;
    }

    // BOSS
    if(g->curr_map == 8) {
        if(g->boss.draw){
            update_boss_pos(g,&g->boss);
        }

        if(CheckCollisionRecs(g->hero.pos, g->boss.pos)) {
            g->gameover = 1;
        }

        if (CheckCollisionRecs(g->hero.bullet.pos, g->boss.pos))
        {
            g->boss.life--;
            if(g->boss.life == 0) {
                for(int i=0; i< g->maps[8].num_enemies; i++){
                    g->maps[8].enemies[i].pos = g->boss.pos;
                    g->maps[8].enemies[i].draw_enemy = 1;
                }
                g->boss.draw = 0;
                g->boss.dead = 1;
                g->boss.bossBullet.pos = g->boss.bossBullet.default_pos;
                g->boss.bossBullet2.pos = g->boss.bossBullet2.default_pos;
                g->boss.pos = g->boss.bossBullet.default_pos;
            }   
            g->hero.bullet.active = 0;
            g->hero.bullet.pos = g->hero.bullet.default_pos;
        }

        if (CheckCollisionRecs(g->hero.bullet2.pos, g->boss.pos))
        {
            g->boss.life--;
            if(g->boss.life == 0) {
                for(int i=0; i< g->maps[8].num_enemies; i++){
                    g->maps[8].enemies[i].pos = g->boss.pos;
                    g->maps[8].enemies[i].draw_enemy = 1;
                }
                g->boss.draw = 0;
                g->boss.dead = 1;
                g->boss.bossBullet.pos = g->boss.bossBullet.default_pos;
                g->boss.bossBullet2.pos = g->boss.bossBullet2.default_pos;
                g->boss.pos = g->boss.bossBullet.default_pos;
                
            }     
            g->hero.bullet2.active = 0;
            g->hero.bullet2.pos = g->hero.bullet2.default_pos;
        }

        bulletCollison(&g->boss.bossBullet, &g->hero.bullet);
        bulletCollison(&g->boss.bossBullet2, &g->hero.bullet);
        bulletCollison(&g->boss.bossBullet2, &g->hero.bullet2);
        bulletCollison(&g->boss.bossBullet, &g->hero.bullet2);

        if(CheckCollisionRecs(g->boss.bossBullet.pos, g->hero.pos)){
            if(g->boss.bossBullet.active){
                g->gameover = 1;
            }
        }  
        if(CheckCollisionRecs(g->boss.bossBullet2.pos, g->hero.pos)){
            if(g->boss.bossBullet2.active){
                g->gameover = 1;
            }
        }  
        if(hasEnemies(g) == 0 && g->boss.dead == 1){
            g->victory = 1;
            g->gameover = 1;
        }
    }

}

void DrawGame(Game *g)
{
    BeginDrawing();

    ClearBackground(RAYWHITE);
    DrawRectangle(0, 0, g->screenWidth, g->screenHeight, BLACK);
    draw_borders(g);
    draw_map(g);

    DrawRectangleRec(g->hero.pos, g->hero.color);
    
    if(g->hero.bullet.active)
    DrawRectangleRec(g->hero.bullet.pos, g->hero.bullet.color);

    if(g->hero.bullet2.active)
    DrawRectangleRec(g->hero.bullet2.pos, g->hero.bullet2.color);
    
    for(int i = 0; i<g->maps[g->curr_map].num_enemies; i++){
        if(g->maps[g->curr_map].enemies[i].enemyBullet.active){
            DrawRectangleRec(g->maps[g->curr_map].enemies[i].enemyBullet.pos, g->maps[g->curr_map].enemies[i].enemyBullet.color);
        }
        if(g->maps[g->curr_map].enemies[i].enemyBullet2.active){
            DrawRectangleRec(g->maps[g->curr_map].enemies[i].enemyBullet2.pos, g->maps[g->curr_map].enemies[i].enemyBullet2.color);
        }
    }

    if(g->boss.draw && (g->curr_map == 8)) {
        DrawRectangleRec(g->boss.pos, g->boss.color);
    }
    
    if(g->boss.bossBullet.active){
        DrawRectangleRec(g->boss.bossBullet.pos, g->boss.bossBullet.color);
    }
    if(g->boss.bossBullet.active){
        DrawRectangleRec(g->boss.bossBullet2.pos, g->boss.bossBullet2.color);
    }

    EndDrawing();
}

void UpdateDrawFrame(Game *g)
{
    UpdateGame(g);
    DrawGame(g);
}