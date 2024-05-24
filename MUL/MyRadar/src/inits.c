/*
** EPITECH PROJECT, 2023
** inits.c
** File description:
** inits
*/

#include "main.h"

static void init_parser(game_t *game, char *path)
{
    game->parse = malloc(sizeof(parse_t));
    game->parse->path = my_strdup(path);
    create_buffer(game);
    get_row(game);
    buffer_to_array(game);
    count_object_number(game);
}

static void init_objects(game_t *game)
{
    create_object_array(game);
    init_objects_tower(game);
    init_objects_plane(game);
    fill_tower_objects(game);
    fill_plane_objects(game);
    fill_sfml_tower(game);
    fill_sfml_plane(game);
}

static void init_clocks(game_t *game)
{
    game->game_clock = sfClock_create();
    game->delta_clock = sfClock_create();
    game->spawn_clock = sfClock_create();
}

static void init_text(game_t *game)
{
    game->text = malloc(sizeof(text_t));
    game->text->success_counter = 0;
    game->text->collision_counter = 0;
    game->text->show_sprite = true;
    game->text->show_hitbox_radius = true;
    game->text->sprite_cooldown = sfClock_create();
    game->text->hitbox_radius_cooldown = sfClock_create();
    game->text->game_font = sfFont_createFromFile(
        "assets/fonts/game_font.ttf"
    );
}

static void init_background(game_t *game)
{
    game->background = malloc(sizeof(background_t));
    game->background->texture = sfTexture_createFromFile(
        "assets/image/map.jpg", NULL
    );
    game->background->sprite = sfSprite_create();
    sfSprite_setTexture(
        game->background->sprite,
        game->background->texture,
        sfTrue
    );
}

void init_game(game_t *game, char *path)
{
    sfMusic *background_music = sfMusic_createFromFile(
        "assets/sounds/background_music.ogg");

    init_parser(game, path);
    init_objects(game);
    sfMusic_play(background_music);
    init_background(game);
    init_clocks(game);
    init_text(game);
}
