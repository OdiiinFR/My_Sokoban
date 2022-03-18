/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-mysokoban-anthony.faure
** File description:
** player_pos
*/

#include "sokoban.h"

int info_player(int i, int j, char **map, int flag)
{
    for (j = 0; map[i][j] != '\0'; j += 1) {
        if (map[i][j] == 'P' && flag == 0)
            return j;
        if (map[i][j] == 'P' && flag == 1)
            return i;
    }
    return -1;
}

void check_win_cond(char **map, int *win, int i, int j)
{
    if (map[i][j] == 32)
        map[i][j] = 'O';
    if (map[i][j] == 'X')
        *win += 1;
    return;
}
