/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "main.h"

void check_plane_delay(game_t *game, float dts)
{
    sfTime spawnDeltaTime = sfClock_getElapsedTime(game->spawn_clock);
    float spawnDeltaTimeSeconds = sfTime_asSeconds(spawnDeltaTime);

    for (int i = 0; i < game->parse->plane_number; i++) {
        if (spawnDeltaTimeSeconds >= game->plane_objects[i]->takeoff_time)
            game->plane_objects[i]->spawn = 1;
        if (game->plane_objects[i]->spawn == 1)
            set_plane_position(game, i, dts);
    }
}

static void show_finished(game_t *game)
{
    sfText *finished_text = sfText_create();
    char display_text[20];

    my_strcpy(display_text, "Game Finished");
    sfText_setString(finished_text, display_text);
    sfText_setFont(finished_text, game->text->game_font);
    sfText_setCharacterSize(finished_text, 50);
    sfText_setColor(finished_text, sfBlack);
    sfText_setPosition(finished_text,
        (sfVector2f){1920 / 2 - 400,
        1080 / 2
    }
    );
    if (game->parse->plane_number <= 0)
        sfRenderWindow_drawText(game->window, finished_text, NULL);
    sfText_destroy(finished_text);
}

static int help(char **argv)
{
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        my_printf("Air traffic simulation panel\n");
        my_printf("USAGE\n");
        my_printf("\t./my_radar [OPTIONS] path_to_script\n");
        my_printf("\tpath_to_script\tThe path to the script file.\n");
        my_printf("OPTIONS\n");
        my_printf("\t-h\t\tprint the usage and quit\n");
        my_printf("USER ITERACTIONS\n");
        my_printf("\t'L' key\t\tenable/disable hitboxes and areas.\n");
        my_printf("\t'S' key\t\tenable/disable sprites\n");
        return 0;
    }
    return 1;
}

int main(int argc, char **argv)
{
    game_t *game = malloc(sizeof(game_t));
    sfTime delta_time;
    float dts;

    if (help(argv) == 0)
        return 0;
    create_window(game, 1920, 1080, "My Radar");
    init_game(game, argv[1]);
    while (sfRenderWindow_isOpen(game->window)) {
        delta_time = sfClock_restart(game->delta_clock);
        dts = sfTime_asSeconds(delta_time);
        handle_events(game);
        check_plane_delay(game, dts);
        sfRenderWindow_clear(game->window, sfBlack);
        draw_all(game);
        show_finished(game);
        sfRenderWindow_display(game->window);
    }
    destroy(game);
    return 0;
}
