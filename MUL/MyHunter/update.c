/*
** EPITECH PROJECT, 2023
** update()
** File description:
** update
*/

#include "include/game.h"

static void handle_events_2(game_t *game, sfEvent event, sfVector2i mousePos)
{
    sfFloatRect duckBounds;

    for (int i = 0; i < game->entity_count; i++) {
        duckBounds = sfSprite_getGlobalBounds(game->entities[i].sprite.sprite);
        if (sfFloatRect_contains(&duckBounds, mousePos.x, mousePos.y)) {
            game->entities[i] = game->entities[game->entity_count - 1];
            (game->score)++;
            (game->entity_count)--;
            sfSound_play(game->sound);
            break;
        } else
            sfSound_play(game->sound2);
    }
}

void handle_events(game_t *game, sfEvent event)
{
    sfVector2i mousePos;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (event.mouseButton.button == sfMouseLeft) {
            mousePos = sfMouse_getPosition(game->window);
            handle_events_2(game, event, mousePos);
        }
    }
    mousePos = sfMouse_getPositionRenderWindow(game->window);
    sfSprite_setPosition(
        game->custom_cursor, (sfVector2f){mousePos.x - 60, mousePos.y - 60}
    );
}

void update_texts(game_t *game)
{
    char scoreStr[20];
    char livesStr[20];

    my_strcpy(scoreStr, "Score: ");
    my_strcat(scoreStr, my_itoa(game->score));
    my_strcpy(livesStr, "Lives: ");
    my_strcat(livesStr, my_itoa(game->lives));
    sfText_setString(game->scoreText, scoreStr);
    sfText_setString(game->livesText, livesStr);
}

void handle_entity_movement(game_t *game, entity_t *entity, float delta_time)
{
    entity->position.x += game->bird_speed * delta_time;
    if (entity->position.x > sfRenderWindow_getSize(game->window).x) {
        entity->position.x = -entity->size.x;
        (game->lives)--;
    }
}

void handle_entity_spawn(game_t *game)
{
    float e_time = game->elapsed_time;
    int entity;
    float random_y;

    if (e_time > rand() % 3 + 1 && game->entity_count < ENTITIES_NUMBER) {
        entity = create_entity(game);
        add_sprite_component(game, entity);
        add_texture_component(game, entity, "assets/bird.png");
        random_y = rand() % (int)sfRenderWindow_getSize(game->window).y - 50;
        add_position_component(game, entity, 0.0f, random_y);
        add_size_component(game, entity, 330.0f, 110.0f);
        add_animation_component(game, entity, 3, 0.1);
        game->elapsed_time = 0.0f;
        game->bird_speed += 10.0f;
    }
}

void render_game(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->background, NULL);
    sfRenderWindow_drawText(game->window, game->scoreText, NULL);
    sfRenderWindow_drawText(game->window, game->livesText, NULL);
    render_ecs(game);
    sfRenderWindow_drawSprite(game->window, game->custom_cursor, NULL);
    sfRenderWindow_display(game->window);
}
