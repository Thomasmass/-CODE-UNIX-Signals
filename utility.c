/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** utility
*/

#include "navy.h"

int my_initmin(char const *str, int i, int minus)
{
    if (str[i + 1] < '+' || str[i + 1] == ','
    || str[i + 1] == '.' || str[i + 1] == '/' || str[i + 1] > '9') {
        minus = 1;
    }
    return minus;
}

int breaking_bad(char const *str, int i)
{
    if (str[i + 1] < '0' || str[i + 1] > '9') {
        return 1;
    }
    return 0;
}

int my_minus(char const *str, int i, int minus)
{
    if (str[i] == '-') {
        minus *= -1;
        minus = my_initmin(str, i, minus);
    }
    if (str[i] == '+') {
        minus *= 1;
        minus = my_initmin(str, i, minus);
    }
    return minus;
}

int my_getnbr(char const *str)
{
    int minus = 1;
    int nb = 0;
    int braker = 0;

    for (int i = 0; str[i] != '\0' && str[i] != '\n' && braker == 0; i++) {
        minus = my_minus(str, i, minus);
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10 + (str[i] - '0');
            braker = breaking_bad(str, i);
        }
        if (nb > 2147483647) {
            return (0);
        }
    }
    return (minus * nb);
}
