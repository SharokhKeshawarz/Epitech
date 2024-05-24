/*
** EPITECH PROJECT, 2023
** get_color()
** File description:
** Gets an rgb value to a variable
*/

int get_color(unsigned char red, unsigned char green, unsigned char blue)
{
    int temp = red;

    temp <<= 8;
    temp += green;
    temp <<= 8;
    temp += blue;
    return temp;
}
