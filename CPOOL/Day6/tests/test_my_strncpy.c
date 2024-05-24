/*
** EPITECH PROJECT, 2023
** test_my_strncpy()
** File description:
** Test for strncpy()
*/

#include <criterion/criterion.h>

Test (my_strncpy, copy_character_in_string_v1)
{
    char dest[6] = {0};
    my_strncpy(dest, "HelloWorld", 5);
    cr_assert_str_eq(dest , "Hello");
}

Test (my_strncpy, copy_character_in_string_v2)
{
    char dest[2] = {0};
    my_strncpy(dest, "", 1);
    cr_assert_str_eq(dest , "");
}

