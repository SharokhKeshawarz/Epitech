/*
** EPITECH PROJECT, 2023
** test_my_strncmp()
** File description:
** Tests for my_strncmp()
*/

#include <criterion/criterion.h>

Test (my_strncmp, check_if_string_of_n_is_equal_to_other_string)
{
    char src[] = "helLo";
    char src2[] = "helLo";
    int result = my_strncmp(src, src2, 2);
    cr_assert_str_eq(result, 1);
}
