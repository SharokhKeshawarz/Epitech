/*
** EPITECH PROJECT, 2024
** my_toupper.c
** File description:
** my_toupper
*/

#include "../../include/my.h"

char my_toupper(char character)
{
    if (character >= 'a' && character <= 'z') {
        character -= 32;
        return character;
    }
    return character;
}
