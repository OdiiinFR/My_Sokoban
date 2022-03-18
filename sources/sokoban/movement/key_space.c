/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-mysokoban-anthony.faure
** File description:
** key_space
*/

#include "sokoban.h"

int key_spc(char **map, char **cpy, sokoabn_t *soko)
{
    int j = 0;

    for (int i = 0; map[i] != NULL; i += 1) {
        for (j = 0; map[i][j] != '\0'; j += 1)
            map[i][j] = cpy[i][j];
    }
    soko->x = soko->x_save;
    soko->y = soko->y_save;
    return -1;
}

int checkup(char **map, sokoabn_t *soko)
{
    if ((soko->y - 1) < -1)
        return 0;
    if (map[soko->y - 1][soko->x] == 35)
        return 0;
    if (map[soko->y - 1][soko->x] == 'X' &&
        soko->x > my_strlen(map[soko->y - 2]))
        return 0;
    if (soko->x > my_strlen(map[soko->y - 1]))
        return 0;
    return 1;
}

int checkrgt(char **map, sokoabn_t *soko)
{
    if (map[soko->y][soko->x + 1] == 35)
        return 0;
    if ((soko->x + 1) > my_strlen(map[soko->y]))
        return 0;
    if (map[soko->y][soko->x + 1] == 'X' &&
        (soko->x + 2) > (my_strlen(map[soko->y]) - 2))
        return 0;
    return 1;
}

int checklft(char **map, sokoabn_t *soko)
{
    if ((soko->x - 1) < -1)
        return 0;
    if (map[soko->y][soko->x - 1] == 35)
        return 0;
    if (map[soko->y][soko->x - 1] == 'X' &&
        soko->x - 2 < 0)
        return 0;
    return 1;
}

int checkdwn(char **map, sokoabn_t *soko)
{
    if ((soko->y + 1) > (soko->nb_lines - 1))
        return 0;
    if (soko->x > my_strlen(map[soko->y + 1]))
        return 0;
    if (map[soko->y + 1][soko->x] == 35)
        return 0;
    if (map[soko->y + 1][soko->x] == 'X' &&
        soko->x > my_strlen(map[soko->y + 2]))
        return 0;
    return 1;
}
