/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** put 1 by 1 char of a string
*/

#include "sokoban.h"

int my_putchar(char c)
{
    write(1, &c, 1);
    return 0;
}

int my_putstr(char const *str)
{
    int ctr = 0;

    while (str[ctr] != '\0') {
        my_putchar(str[ctr]);
        ctr = ctr + 1;
    }
    return (0);
}

int my_strlen(char const *str)
{
    int ctr = 0;

    while (str[ctr] != '\0')
        ctr = ctr + 1;
    return (ctr);
}

int strcompare(char *str1, char *str2)
{
    int ctr = 0;

    if (my_strlen(str1) != my_strlen(str2))
        return 84;
    while (str1[ctr] != '\0') {
        if (str1[ctr] != str2[ctr])
            return 84;
        ctr += 1;
    }
    return 0;
}

int strncompare(char *str1, char *str2, int n)
{
    int ctr = 0;

    if (my_strlen(str1) < n || my_strlen(str2) < n)
        return 84;
    while (ctr < n) {
        if (str1[ctr] != str2[ctr])
            return 84;
        ctr += 1;
    }
    return 0;
}
