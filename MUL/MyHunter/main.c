/*
** EPITECH PROJECT, 2023
** main()
** File description:
** main
*/

#include "include/game.h"

void args(int argc, char **argv)
{
    if (argc == 2) {
        if (argv[1][0] == '-' && argv[1][1] == 'h') {
            my_putstr("You have to aim at the ducks\n");
            my_putstr("You have to click to kill the ducks\n");
            my_putstr("Your goal is to achieve the higest score\n");
            return 0;
        }
    }
}

int main(int argc, char **argv)
{
    game_t game;
    sfEvent event;
    float frame_time;

    initialize_game(&game);
    while (sfRenderWindow_isOpen(game.window)) {
        frame_time = sfTime_asSeconds(sfClock_restart(game.clock));
        game.elapsed_time += frame_time;
        handle_events(&game, event);
        update_texts(&game);
        handle_entity_spawn(&game);
        if (game.lives == 0)
            return 0;
        for (int i = 0; i < game.entity_count; i++)
            handle_entity_movement(&game, &game.entities[i], frame_time);
        update_animation(&game, frame_time);
        render_game(&game);
    }
    cleanup_game(&game);
    return 0;
}
