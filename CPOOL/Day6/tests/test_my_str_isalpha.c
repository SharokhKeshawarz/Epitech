/*
** EPITECH PROJECT, 2023
** test_my_isalpha()
** File description:
** Tests for my_isalpha()
*/

#include <criterion/criterion.h>

Test (my_str_isalpha, check_if_string_is_alpha)
{
    char src[] = "helLo";
    int result = my_str_isalpha(src);
    cr_assert_eq(result, 1);
}

Test (my_str_isalpha, check_if_string_is_alpha_v2)
{
    char src[] = "he1lo";
    int result = my_str_isalpha(src);
    cr_assert_eq(result, 0);
}

Test (my_str_isalpha, check_if_string_is_alpha_v3)
{
    char src[] = "";
    int result = my_str_isalpha(src);
    cr_assert_eq(result, 1);
}