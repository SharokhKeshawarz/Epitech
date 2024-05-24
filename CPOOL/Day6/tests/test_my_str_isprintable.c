/*
** EPITECH PROJECT, 2023
** test_my_str_isprintable()
** File description:
** Tests for my_str_isprintable()
*/

#include <criterion/criterion.h>

Test (my_str_isprintable, check_if_string_is_printable)
{
    char src[] = "helLo242@";
    int result = my_str_isprintable(src);
    cr_assert_eq(result, 1);
}

Test (my_str_isprintable, check_if_string_is_printable_v2)
{
    char src[] = "\t\t";
    int result = my_str_isprintable(src);
    cr_assert_eq(result, 0);
}

Test (my_str_isprintable, check_if_string_is_printable_v3)
{
    char src[] = "";
    int result = my_str_isprintable(src);
    cr_assert_eq(result, 1);
}
