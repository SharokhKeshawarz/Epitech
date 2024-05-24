/*
** EPITECH PROJECT, 2023
** main.h
** File description:
** main
*/

#ifndef LIBS_H
    #define LIBS_H
    #include <stdlib.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdbool.h>
    #include <sys/stat.h>
    #include <time.h>
    #include <math.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Network.h>
    #include "my.h"
    #include "my_printf.h"
    // WINDOW
    #define FPS 60
    // TOWERS
    #define TOWER_VALUES 3
    #define TOWER_POSX 0
    #define TOWER_POSY 1
    #define TOWER_RADIUS 2
    #define TOWER_SCALE 0.1f
    // PLANES
    #define PLANE_VALUES 6
    #define PLANE_TAKEOFF_POSX 0
    #define PLANE_TAKEOFF_POSY 1
    #define PLANE_LANDING_POSX 2
    #define PLANE_LANDING_POSY 3
    #define PLANE_SPEED 4
    #define PLANE_TAKEOFF_TIME 5
    #define PLANE_SCALE 0.05f
    #define HITBOX_SIZE 20.0f * 20.0f
    #define HITBOX_THICK 1.0f

typedef struct {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f scale;
    sfVector2u texture_size;
    sfVector2f hitbox_position;
    sfRectangleShape *hitbox_shape;
    int takeoff_x;
    int takeoff_y;
    int landing_x;
    int landing_y;
    float speed;
    int takeoff_time;
    int spawn;
} plane_t;

typedef struct {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f scale;
    sfCircleShape *circle;
    int pos_x;
    int pos_y;
    int radius_value;
} tower_t;


typedef struct {
    char *path;
    char *buffer;
    char **buffer_array;
    int row;
    int tower_number;
    int plane_number;
    int tower_values[TOWER_VALUES];
    int plane_values[PLANE_VALUES];
} parse_t;

typedef struct {
    sfSprite *sprite;
    sfTexture *texture;
} background_t;

typedef struct {
    int success_counter;
    int collision_counter;
    int show_sprite;
    int show_hitbox_radius;
    sfClock *sprite_cooldown;
    sfClock *hitbox_radius_cooldown;
    sfFont *game_font;
} text_t;

typedef struct {
    sfRenderWindow *window;
    sfEvent event;
    sfClock *game_clock;
    sfClock *delta_clock;
    sfClock *spawn_clock;
    parse_t *parse;
    tower_t **tower_objects;
    plane_t **plane_objects;
    text_t *text;
    background_t *background;
} game_t;

// file_parsing.c |
void create_buffer(game_t *game);
void get_row(game_t *game);
static void get_last_row(game_t *game, int counter, int i, int j);
void buffer_to_array(game_t *game);
void count_object_number(game_t *game);

// objects_array.c |
void init_objects_tower(game_t *game);
void init_objects_plane(game_t *game);
void create_object_array(game_t *game);
void fill_tower_objects(game_t *game);
static void fill_plane_objects_2(game_t *game, int plane_index, int values[]);
void fill_plane_objects(game_t *game);

// utils.c |
void create_window(game_t *game, int width, int height, char *title);
void show_timer(game_t *game);
void show_success_landing(game_t *game);
void show_crash_landing(game_t *game);
void destroy(game_t *game);

// sfml_tower_objects.c |
static void init_tower_sprite(tower_t *tower);
static float calculate_centerx(tower_t *tower);
static float calculate_centery(tower_t *tower);
static void init_circle(tower_t *tower, sfUint8 opacity);
void fill_sfml_tower(game_t *game);

// sfml_plane_objects.c |
void init_plane_sprite(plane_t *plane);
static float calculate_plane_hitbox_x(plane_t *plane);
static float calculate_plane_hitbox_y(plane_t *plane);
void set_plane_hitbox_position(plane_t *plane);
void create_plane_hitbox(plane_t *plane);
void fill_sfml_plane(game_t *game);

// events.c |
static void handle_escape_key(game_t *game);
static void handle_sprite_key(game_t *game);
static void handle_hitbox_radius_key(game_t *game);
void handle_events(game_t *game);

// inits.c |
static void init_parser(game_t *game, char *path);
static void init_objects(game_t *game);
static void init_clocks(game_t *game);
static void init_text(game_t *game);
static void init_background(game_t *game);
void init_game(game_t *game, char *path);

// draw.c |
static void draw_towers(game_t *game);
static void draw_planes(game_t *game);
void draw_all(game_t *game);

// logic.c
void set_plane_position(game_t *game, int i, float dt);

// main.c
void check_plane_delay(game_t *game, float dts);
int main(int argc, char **argv);

#endif
