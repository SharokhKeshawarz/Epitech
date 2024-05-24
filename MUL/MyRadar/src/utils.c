/*
** EPITECH PROJECT, 2023
** utils.c
** File description:
** utils
*/

#include "main.h"

void create_window(game_t *game, int width, int height, char *title)
{
    game->window = sfRenderWindow_create(
        (sfVideoMode){width, height},
        title,
        sfDefaultStyle,
        sfContextDefault
    );
    sfRenderWindow_setFramerateLimit(game->window, FPS);
}

void show_timer(game_t *game)
{
    sfTime elapsed_time = sfClock_getElapsedTime(game->game_clock);
    float seconds = sfTime_asSeconds(elapsed_time);
    char timer_string[6];
    int minutes = (int)seconds / 60;
    int remaining_seconds = (int)seconds % 60;
    sfText *timer_text = sfText_create();

    timer_string[0] = '0' + (minutes / 10);
    timer_string[1] = '0' + (minutes % 10);
    timer_string[2] = ':';
    timer_string[3] = '0' + (remaining_seconds / 10);
    timer_string[4] = '0' + (remaining_seconds % 10);
    timer_string[5] = '\0';
    sfText_setString(timer_text, timer_string);
    sfText_setFont(timer_text, game->text->game_font);
    sfText_setCharacterSize(timer_text, 20);
    sfText_setPosition(timer_text,
        (sfVector2f){1920 - 115, 5}
    );
    sfRenderWindow_drawText(game->window, timer_text, NULL);
}

void show_success_landing(game_t *game)
{
    sfText *success_text = sfText_create();
    char success_str[8];
    char display_text[20];

    its(game->text->success_counter, success_str);
    my_strcpy(display_text, "Success: ");
    my_strcat(display_text, success_str);
    sfText_setString(success_text, display_text);
    sfText_setFont(success_text, game->text->game_font);
    sfText_setCharacterSize(success_text, 14);
    sfText_setColor(success_text, sfGreen);
    sfText_setPosition(success_text,
        (sfVector2f){1920 - 175, 40}
    );
    sfRenderWindow_drawText(game->window, success_text, NULL);
    sfText_destroy(success_text);
}

void show_crash_landing(game_t *game)
{
    sfText *crash_text = sfText_create();
    char crash_str[8];
    char display_text[20];

    its(game->text->collision_counter, crash_str);
    my_strcpy(display_text, "Crashed: ");
    my_strcat(display_text, crash_str);
    sfText_setString(crash_text, display_text);
    sfText_setFont(crash_text, game->text->game_font);
    sfText_setCharacterSize(crash_text, 14);
    sfText_setColor(crash_text, sfRed);
    sfText_setPosition(crash_text,
        (sfVector2f){1920 - 175, 80}
    );
    sfRenderWindow_drawText(game->window, crash_text, NULL);
    sfText_destroy(crash_text);
}

static void free_clocks(game_t *game)
{
    sfClock_destroy(game->game_clock);
    sfClock_destroy(game->delta_clock);
    sfClock_destroy(game->spawn_clock);
    sfClock_destroy(game->text->sprite_cooldown);
    sfClock_destroy(game->text->hitbox_radius_cooldown);
}

void destroy(game_t *game)
{
    free_clocks(game);
    sfFont_destroy(game->text->game_font);
    free(game->text);
    sfSprite_destroy(game->background->sprite);
    sfTexture_destroy(game->background->texture);
    free(game->background);
    for (int i = 0; i < game->parse->row; i++)
        free(game->parse->buffer_array[i]);
    free(game->parse->buffer_array);
    free(game->parse);
    for (int i = 0; i < game->parse->tower_number; i++) {
        sfSprite_destroy(game->tower_objects[i]->sprite);
        sfTexture_destroy(game->tower_objects[i]->texture);
        sfCircleShape_destroy(game->tower_objects[i]->circle);
        free(game->tower_objects[i]);
    }
    free(game->tower_objects);
    free(game->plane_objects);
    sfRenderWindow_destroy(game->window);
}
