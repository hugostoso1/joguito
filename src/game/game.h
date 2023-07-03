#include <time.h>
#define STD_SIZE_X 30
#define STD_SIZE_Y 30
#define SCREEN_BORDER 4

typedef struct Bullet{
    Rectangle pos;
    Rectangle default_pos;
    Color color;
    int speed;
    int active;
    int direction;
}Bullet;

typedef struct Enemy
{
    Rectangle pos;
    Color color;
    int speed;
    int direction;
    int draw_enemy;
    int has_key;
    Bullet enemyBullet;
    Bullet enemyBullet2;
} Enemy;

typedef struct Boss 
{
    Rectangle pos;
    Color color;
    int speed;
    int direction;
    int draw;
    int dead;
    int life;
    Bullet bossBullet;
    Bullet bossBullet2;
} Boss;

typedef struct Hero
{
    Rectangle pos;
    Color color;
    int speed;
    int special;
    int kill;
    Bullet bullet;
    Bullet bullet2;
} Hero;

typedef struct Map
{
    Rectangle barriers[10];
    int num_barriers;
    Rectangle door;
    Rectangle prev_door;
    Color color;
    Enemy enemies[25];
    int num_enemies;
    Rectangle special_item;
    int draw_special_item;
    int door_locked;
    int next_map;
    int prev_map;
} Map;

typedef struct Game
{
    Map maps[10];
    int num_maps;
    int curr_map;
    Hero hero;
    int screenWidth;
    int screenHeight;
    int gameover;
    int victory;
    int score;
    char mode;
    Boss boss;
    clock_t time;
} Game;

//------------------------------------------------------------------------------------
// Module Functions Declaration (local)
//------------------------------------------------------------------------------------
void InitGame(Game *g);        // Initialize game
void UpdateGame(Game *g);      // Update game (one frame)
void DrawGame(Game *g);        // Draw game (one frame)
void UpdateDrawFrame(Game *g); // Update and Draw (one frame)
void draw_borders(Game *g);
int barrier_collision(Map *m, Rectangle *t);
void update_enemy_pos(Game *g, Enemy *e);
void update_boss_pos(Game *g, Boss *B);
void update_hero_pos(Game *g);
void shoot(Hero *b, Rectangle *position, Game *g);
void update_bullet(Bullet *b, Bullet *b2, Game*g);
void bulletCollison(Bullet *b1, Bullet *b2);
int hasEnemies(Game *g);
void draw_map(Game *g);
void resetMap(Game *g);
void map0_setup(Game *g);
void map1_setup(Game *g);
void map2_setup(Game *g);
void map3_setup(Game *g);
void map4_setup(Game *g);
void map5_setup(Game *g);
void map6_setup(Game *g);
void map7_setup(Game *g);
void map8_setup(Game *g);