/*
** EPITECH PROJECT, 2023
** esc()
** File description:
** esc
*/

#include "include/game.h"

static void init_window(game_t *game)
{
    game->window = sfRenderWindow_create(
        (sfVideoMode){800, 600, 32}, "Game", sfDefaultStyle, NULL
    );
    sfRenderWindow_setFramerateLimit(game->window, 60);
    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
}

static void init_clock(game_t *game)
{
    game->clock = sfClock_create();
}

static void init_entities(game_t *game)
{
    game->entities = malloc(ENTITIES_NUMBER * sizeof(entity_t));
}

static void init_sound(game_t *game)
{
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile(
        "assets/gunsound.ogg"
    );
    sfSoundBuffer *buffer2 = sfSoundBuffer_createFromFile(
        "assets/missedsound.ogg"
    );

    game->sound = sfSound_create();
    game->sound2 = sfSound_create();
    sfSound_setBuffer(game->sound, buffer);
    sfSound_setBuffer(game->sound2, buffer2);
}

static void init_background(game_t *game)
{
    sfTexture *backgroundTexture = sfTexture_createFromFile(
        "assets/background.png", NULL
    );

    game->background = sfSprite_create();
    sfSprite_setTexture(game->background, backgroundTexture, sfTrue);
}

static void init_custom_cursor(game_t *game)
{
    sfTexture *cursorTexture = sfTexture_createFromFile(
        "assets/cursor.png", NULL
    );

    game->custom_cursor = sfSprite_create();
    sfSprite_setTexture(game->custom_cursor, cursorTexture, sfTrue);
}

static void init_font(game_t *game)
{
    game->font = sfFont_createFromFile("assets/smile.otf");
}

static void init_score_text(game_t *game)
{
    game->scoreText = sfText_create();
    sfText_setFont(game->scoreText, game->font);
    sfText_setCharacterSize(game->scoreText, 24);
    sfText_setFillColor(game->scoreText, sfWhite);
}

static void init_lives_text(game_t *game)
{
    game->livesText = sfText_create();
    sfText_setFont(game->livesText, game->font);
    sfText_setCharacterSize(game->livesText, 24);
    sfText_setFillColor(game->livesText, sfWhite);
    sfText_setPosition(game->livesText, (sfVector2f){720, 0});
}

void initialize_game(game_t *game)
{
    init_ecs(game);
    init_window(game);
    init_clock(game);
    init_entities(game);
    init_sound(game);
    init_background(game);
    init_custom_cursor(game);
    init_font(game);
    init_score_text(game);
    init_lives_text(game);
}
