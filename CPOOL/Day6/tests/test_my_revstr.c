/*
** EPITECH PROJECT, 2023
** test_my_revstr()
** File description:
** Tests for my_revstr
*/

#include <criterion/criterion.h>

Test (my_revstr, reverse_a_string)
{
    char src[] = "Sharokh";
    my_revstr(src);
    cr_assert_str_eq(src, "hkorahS");
}
