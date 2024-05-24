/*
** EPITECH PROJECT, 2023
** swap_endian_color()
** File description:
** Swaps endian color
*/

int swap_endian_color(int color)
{
    union {
        int color;
        unsigned char argb[4];
    } ARGB;
    int swapped;
    int temp = 1;

    ARGB.color = color;
    if (*((unsigned char *)&temp) == 1) {
        swapped = (ARGB.argb[3] << 24) |
                    (ARGB.argb[2] << 16) |
                    (ARGB.argb[1] << 8) |
                    ARGB.argb[0];
        return swapped;
    }
    return ARGB.color;
}
