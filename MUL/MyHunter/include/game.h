/*
** EPITECH PROJECT, 2023
** game()
** File description:
** game
*/

#ifndef GAME_H
    #define GAME_H
    #define ENTITIES_NUMBER 1000
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <math.h>

typedef struct {
    float x;
    float y;
} position_component;

typedef struct {
    float x;
    float y;
} size_component;

typedef struct {
    float angle;
} rotation_component;

typedef struct {
    float x;
    float y;
} scale_component;

typedef struct {
    sfTexture *texture;
} texture_component;

typedef struct {
    sfSprite *sprite;
} sprite_component;

typedef struct {
    int frame_count;
    float frame_duration;
    float elapsed_time;
    sfIntRect rect;
} animation_component;

typedef struct {
    int id;
    sprite_component sprite;
    position_component position;
    size_component size;
    scale_component scale;
    texture_component texture;
    animation_component animate;
} entity_t;

typedef struct {
    int entity_count;
    int lives;
    float elapsed_time;
    float bird_speed;
    int score;
    sfRenderWindow *window;
    sfClock *clock;
    entity_t *entities;
    sfSound *sound;
    sfSound *sound2;
    sfSprite *background;
    sfSprite *custom_cursor;
    sfText *scoreText;
    sfText *livesText;
    sfFont *font;
} game_t;


void init_ecs(game_t *game);
void add_position_component(game_t *game, int id, float x, float y);
void add_size_component(game_t *game, int id, float x, float y);
void add_texture_component(game_t *game, int id, const char *path);
void add_sprite_component(game_t *game, int id);
void add_scale_component(game_t *game, int id, float x, float y);
void add_animation_component(
    game_t *game, int id, int frame_count, float frame_duration
);
void update_animation_2(game_t *game, int i);
void update_animation(game_t *game, float delta_time);
int create_entity(game_t *game);
void render_ecs(game_t *game);
void initialize_game(game_t *game);
void cleanup_game(game_t *game);
void handle_events(game_t *game, sfEvent event);
void update_texts(game_t *game);
void handle_entity_movement(game_t *game, entity_t *entity, float delta_time);
void handle_entity_spawn(game_t *game);
void render_game(game_t *game);
void my_putstr(char const *str);

#endif
