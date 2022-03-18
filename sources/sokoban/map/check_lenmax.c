/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-mysokoban-anthony.faure
** File description:
** check_lenmax
*/

#include "sokoban.h"

void check_lenmax(int len, sokoabn_t *soko)
{
    if (len >= soko->len_max)
        soko->len_max = len;
    return;
}
