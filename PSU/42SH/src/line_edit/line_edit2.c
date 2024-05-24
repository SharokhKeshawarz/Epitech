/*
** EPITECH PROJECT, 2024
** line_edit2
** File description:
** line_edit2
*/

#include "../../include/my.h"
#include "../../include/pmy.h"

char *free_line_edit(line_edit_t *edition, struct termios *orig_termios)
{
    disable_rawmode(orig_termios);
    free(edition->buf);
    free(edition->buffer);
    free(edition);
    write(STDOUT_FILENO, "\n", 1);
    return NULL;
}
