/*
** EPITECH PROJECT, 2023
** my_is_prime.c
** File description:
** calculates prime number
*/

int my_is_prime(int n)
{
    if (n > 2147483647 || n < -2147483648)
        return 0;
    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return 0;
    else if (n == 3 || n == 2)
        return 1;
    for (int k = 5; k * k <= n; k += 6)
        if (n % (k + 2) == 0 || n % k == 0)
            return 0;
    return 1;
}
