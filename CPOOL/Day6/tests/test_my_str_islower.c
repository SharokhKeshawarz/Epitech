/*
** EPITECH PROJECT, 2023
** test_my_islower()
** File description:
** Tests for my_islower()
*/

#include <criterion/criterion.h>

char dest[] = "sharokh";
char dest2[] = "SharOkh";
char dest3[] = "";

Test(my_islower_1, is_str_all_lower_v1)
{
    cr_assert(my_str_islower(dest) == 1);
}

Test(my_islower_2, is_str_all_lower_v2)
{
    cr_assert(my_str_islower(dest2) == 0);
}

Test(my_islower_3, is_str_all_lower_v3)
{
    cr_assert(my_str_islower(dest3) == 1);
}
