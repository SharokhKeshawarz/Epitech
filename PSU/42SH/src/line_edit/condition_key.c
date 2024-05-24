/*
** EPITECH PROJECT, 2024
** condition key
** File description:
** What did you press ? What am I suppose to do if you pressed that ?
*/

#include "../../include/pmy.h"
#include "../../include/my.h"

static void switch_char_next(line_edit_t *edition,
    char c, char *seq, general_t *general)
{
    switch (c) {
        case 25:
            ctrl_y(edition);
            break;
        case 127:
            suppr(edition);
            break;
        case 0x1b:
            edition->cursor_pos = arrow_pressed(seq, edition, general);
            break;
        default:
            handle_character_input(c, edition, general);
            break;
    }
}

static void switch_char(line_edit_t *edition,
    char c, char *seq, general_t *general)
{
    switch (c) {
        case 1:
            edition->cursor_pos = edition->prompt;
            break;
        case 8:
            ctrl_h(edition);
            break;
        case 11:
            ctrl_k(edition);
            break;
        case 23:
            ctrl_w(edition);
            break;
        default:
            switch_char_next(edition, c, seq, general);
            break;
    }
    save_actual_line(general, edition);
}

int main_condition(line_edit_t *edition, general_t *general)
{
    char seq[3];
    char c;

    if (read(STDIN_FILENO, &c, 1) == 1) {
        if (c == '\n')
            return 1;
        if (c == 4)
            return 84;
        switch_char(edition, c, seq, general);
        update_display(edition, general);
    }
    return 0;
}
