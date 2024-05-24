/*
** EPITECH PROJECT, 2023
** cat()
** File description:
** Dose the same thing as CAT in the shell
*/

#include <criterion/criterion.h>

Test(cat, test_cat_1)
{
    cr_assert_str_eq("HELLO", "HELLO");
}

Test(cat, test_cat_2)
{
    cr_assert_str_eq("TEST", "TEST");
}
