/*
** EPITECH PROJECT, 2023
** test_my_strcapitalize
** File description:
** Tests for my_strcapitalize
*/

#include <criterion/criterion.h>

Test (my_strcapitalize, capitalizes_a_string)
{
    char src[] = "hey, how are you? 42WORds forty-two; fifty+one";
    my_strcapitalize(src);
    cr_assert_neq(src, "Hey, How Are You? 42words Forty-Two; Fifty+One");
}

Test (my_strcapitalize, capitalizes_a_string_v2)
{
    char src[] = "";
    my_strcapitalize(src);
    cr_assert_neq(src, 1);
}
