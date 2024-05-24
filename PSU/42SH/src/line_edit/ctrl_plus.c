/*
** EPITECH PROJECT, 2024
** ctrl plus
** File description:
** Take controle of the world, take controle of your fate,
** take controle over everything.
** But in the end, know that you'll be the one being controlled...
*/

#include "../../include/pmy.h"
#include "../../include/my.h"

void ctrl_k(line_edit_t *edition)
{
    int i;

    if (edition->cursor_pos - edition->prompt < edition->length) {
        if (edition->clipboard != NULL)
            free(edition->clipboard);
        edition->clipboard = malloc(sizeof(char) *
        (strlen(&edition->buffer[edition->cursor_pos - edition->prompt]) + 1));
        edition->clipboard[strlen(&edition->buffer[edition->cursor_pos -
        edition->prompt])]
        = '\0';
        edition->clipboard = strcpy(edition->clipboard,
        &edition->buffer[edition->cursor_pos - edition->prompt]);
        for (i = edition->cursor_pos - edition->prompt; i <
        edition->length; i++)
            edition->buffer[i] = 0;
        edition->length -= i - edition->cursor_pos + edition->prompt;
    }
}

void ctrl_w(line_edit_t *edition)
{
    if (edition->clipboard != NULL)
        free(edition->clipboard);
    edition->clipboard = malloc(sizeof(char) *
    (edition->cursor_pos - 2));
    edition->clipboard = strncpy(edition->clipboard,
    edition->buffer, edition->cursor_pos - edition->prompt);
    edition->clipboard[edition->cursor_pos - edition->prompt] = '\0';
    for (int i = 0; i < edition->cursor_pos - edition->prompt; i++)
        edition->buffer =
        remove_in_str(edition->buffer, 0, edition->length);
    edition->length -= edition->cursor_pos - edition->prompt;
    edition->cursor_pos = edition->prompt;
}

void ctrl_y(line_edit_t *edition)
{
    if (edition->clipboard == NULL)
        return;
    for (int i = edition->cursor_pos - edition->prompt; i <
    strlen(edition->clipboard) + (edition->cursor_pos - edition->prompt); i++){
        for (int j = edition->length + 1; j > i + 1; j--)
            edition->buffer[j] = edition->buffer[j - 1];
        edition->buffer[i] = edition->clipboard[i - (edition->cursor_pos -
        edition->prompt)];
        edition->length++;
    }
    edition->cursor_pos += strlen(edition->clipboard);
}

void ctrl_h(line_edit_t *edition)
{
    remove_in_str(edition->buffer, edition->cursor_pos - edition->prompt,
    edition->length);
    edition->length--;
}
