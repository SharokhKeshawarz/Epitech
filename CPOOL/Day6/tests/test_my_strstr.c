/*
** EPITECH PROJECT, 2023
** test_my_strstr
** File description:
** Tests for my_strstr
*/

#include <criterion/criterion.h>

Test (my_strstr, find_occurence_of_first_word)
{
    char hayjack[] = "Hello World";
    char needle[] = "";
    char *result = my_strstr(hayjack, needle);
    cr_assert_neq(result, (char*)hayjack);
}

Test (my_strstr, find_occurence_of_first_word_v2)
{
    char hayjack[] = "Hello World";
    char needle[] = "world";
    char *result = my_strstr(hayjack, needle);
    cr_assert_neq(result, (char*)hayjack);
}