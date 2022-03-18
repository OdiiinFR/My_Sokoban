/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-mysokoban-anthony.faure
** File description:
** conditions
*/

#include "sokoban.h"

int check_win(char **map, char **cpy)
{
    int win = 0;
    int nb = 0;

    for (int i = 0; cpy[i] != NULL; i += 1)
        nb += find_nb(map, cpy, &win, i);
    if (win == nb)
        return 0;
    win = 0;
    for (int i = 0; map[i] != NULL; i += 1) {
        for (int j = 0; map[i][j] != '\0'; j += 1)
            win += find_win(map, i, j);
    }
    if (win == nb)
        return 1;
    return -1;
}

int check_around(char **map, int x, int y)
{
    if (map[y][x + 1] == 35 && map[y - 1][x] == 35)
        return 1;
    if (map[y][x + 1] == 35 && map[y - 1][x] == 'X')
        return 1;
    if (map[y][x + 1] == 'X' && map[y - 1][x] == 35)
        return 1;
    if (map[y][x + 1] == 'X' && map[y - 1][x] == 'X')
        return 1;
    if (map[y][x - 1] == 35 && map[y - 1][x] == 35)
        return 1;
    if (map[y][x - 1] == 'X' && map[y - 1][x] == 'X')
        return 1;
    if (map[y][x - 1] == 'X' && map[y - 1][x] == 35)
        return 1;
    if (map[y][x - 1] == 35 && map[y - 1][x] == 'X')
        return 1;
    return check_around2(map, x, y);
}

int check_around2(char **map, int x, int y)
{
    if (map[y][x + 1] == 35 && map[y + 1][x] == 35)
        return 1;
    if (map[y][x + 1] == 'X' && map[y + 1][x] == 'X')
        return 1;
    if (map[y][x + 1] == 'X' && map[y + 1][x] == 35)
        return 1;
    if (map[y][x + 1] == 35 && map[y + 1][x] == 'X')
        return 1;
    if (map[y][x - 1] == 35 && map[y + 1][x] == 35)
        return 1;
    if (map[y][x - 1] == 'X' && map[y + 1][x] == 'X')
        return 1;
    if (map[y][x - 1] == 'X' && map[y + 1][x] == 35)
        return 1;
    if (map[y][x - 1] == 35 && map[y + 1][x] == 'X')
        return 1;
    return 0;
}

int find_nb(char **map, char **cpy, int *win, int i)
{
    int nb = 0;

    for (int j = 0; cpy[i][j] != '\0'; j += 1) {
        if (cpy[i][j] == 'O') {
            check_win_cond(map, win, i, j);
            nb += 1;
        }
    }
    return nb;
}

int find_win(char **map, int i, int j)
{
    int win = 0;

    if (map[i][j] == 'X')
        win += check_around(map, j, i);
    return win;
}
