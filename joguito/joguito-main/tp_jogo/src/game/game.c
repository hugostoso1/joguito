#include "../raylib.h"
#include "./game.h"

void InitGame(Game *g)
{

    g->curr_map = 0;
    g->num_maps = 10;
    g->hero.pos = (Rectangle){150, 300, STD_SIZE_X, STD_SIZE_Y};
    g->hero.color = BLACK;
    g->hero.speed = 10;
    g->hero.special = 0;
    g->hero.bullet.default_pos = (Rectangle){5500,5500,45,10};
    g->hero.bullet.direction = KEY_RIGHT;
    g->hero.bullet.color = PURPLE;
    g->hero.bullet.speed = 15;
    g->hero.bullet.active = 0;
    g->hero.bullet2.default_pos = (Rectangle){5500,5500,45,10};
    g->hero.bullet2.direction = KEY_RIGHT;
    g->hero.bullet2.color = PURPLE;
    g->hero.bullet2.speed = 15;
    g->hero.bullet2.active = 0;
    g->gameover = 0;
    g->score = 0;
    map0_setup(g);
    map1_setup(g);
    map2_setup(g);
    map3_setup(g);
}

void UpdateGame(Game *g)
{
    update_hero_pos(g);

    shoot(&g->hero, &g->hero.pos, g);
   
    Map *map = &g->maps[g->curr_map];
    for (int i=0; i < map->num_enemies; i++)
    {
        if (!map->enemies[i].draw_enemy){
            map->enemies[i].enemyBullet.pos = map->enemies[i].enemyBullet.default_pos;
            map->enemies[i].enemyBullet.active = 0;
            map->enemies[i].enemyBullet2.pos = map->enemies[i].enemyBullet2.default_pos;
            map->enemies[i].enemyBullet2.active = 0;
            continue;
        }

        update_enemy_pos(g, &map->enemies[i]);
        

        if (CheckCollisionRecs(g->hero.bullet.pos, map->enemies[i].pos))
        {
            map->enemies[i].draw_enemy = 0;            
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
            g->hero.bullet2.active = 0;
            g->hero.bullet2.pos = g->hero.bullet2.default_pos;
            if (map->enemies[i].has_key)
            {
                map->door_locked = 0;
            }
        }

        if (CheckCollisionRecs(map->enemies[i].enemyBullet.pos, g->hero.pos)){
            if(!g->hero.special) {
                map->enemies[i].enemyBullet.pos = map->enemies[i].enemyBullet.default_pos;
                resetMap(g);
            }
        }

        if (CheckCollisionRecs(map->enemies[i].enemyBullet2.pos, g->hero.pos) && (g->mode == 'H')){
            if(!g->hero.special) {
                map->enemies[i].enemyBullet2.pos = map->enemies[i].enemyBullet2.default_pos;
                resetMap(g);
            }
        }

        if (!CheckCollisionRecs(g->hero.pos, map->enemies[i].pos))
            continue;
        

        if (g->hero.special)
        {
            map->enemies[i].draw_enemy = 0;
            if (map->enemies[i].has_key)
            {
                map->door_locked = 0;
            }
            continue;
        }

        resetMap(g);
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
        g->hero.pos = (Rectangle){50, 200, STD_SIZE_X, STD_SIZE_Y};
        g->hero.special = 0;
    }

    if (map->prev_map != -1 && CheckCollisionRecs(g->hero.pos, map->prev_door))
    {
        g->curr_map = map->prev_map;
        g->hero.pos = (Rectangle){g->screenWidth - 50, g->screenHeight / 3, STD_SIZE_X, STD_SIZE_Y};
        g->hero.special = 0;
    }
}

void DrawGame(Game *g)
{
    BeginDrawing();

    ClearBackground(RAYWHITE);
    DrawRectangle(0, 0, g->screenWidth, g->screenHeight, GRAY);
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

    EndDrawing();
}

void UpdateDrawFrame(Game *g)
{
    UpdateGame(g);
    DrawGame(g);
}
