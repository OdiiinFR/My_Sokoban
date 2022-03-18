/*
** EPITECH PROJECT, 2022
** moove
** File description:
** moove
*/

#include "sokoban.h"

int check_key(int key, char **map, char **cpy, sokoabn_t *soko)
{
    if (key == KEY_UP)
        return key_up(map, soko, cpy);
    if (key == KEY_RIGHT)
        return key_rgt(map, soko, cpy);
    if (key == KEY_DOWN)
        return key_dwn(map, soko, cpy);
    if (key == KEY_LEFT)
        return key_lft(map, soko, cpy);
    if (key == 32)
        return key_spc(map, cpy, soko);
    if (key == 27)
        return 1;
    return -1;
}

int key_up(char **map, sokoabn_t *soko, char **cpy)
{
    if ((soko->y == 0) || soko->x < my_strlen(map[soko->y - 1] - 2) ||
        map[soko->y - 1][soko->x] == 35)
        return -1;
    if (map[soko->y - 1][soko->x] == ' ' ||
        map[soko->y - 1][soko->x] == 'O') {
        map[soko->y][soko->x] = ' ';
        map[soko->y - 1][soko->x] = 'P';
        soko->y -= 1;
        return check_win(map, cpy);
    }
    if (map[soko->y - 1][soko->x] == 'X') {
        if (map[soko->y - 2][soko->x] == ' ' ||
            map[soko->y - 2][soko->x] == 'O') {
            map[soko->y][soko->x] = ' ';
            map[soko->y - 1][soko->x] = 'P';
            map[soko->y - 2][soko->x] = 'X';
            soko->y -= 1;
        }
    }
    return check_win(map, cpy);
}

int key_rgt(char **map, sokoabn_t *soko, char **cpy)
{
    if ((soko->x + 2) > my_strlen(map[soko->y]) ||
        map[soko->y][soko->x + 1] == 35)
        return -1;
    if (map[soko->y][soko->x + 1] == ' ' ||
        map[soko->y][soko->x + 1] == 'O') {
        map[soko->y][soko->x] = ' ';
        map[soko->y][soko->x + 1] = 'P';
        soko->x += 1;
        return check_win(map, cpy);
    }
    if (map[soko->y][soko->x + 1] == 'X') {
        if (map[soko->y][soko->x + 2] == ' ' ||
            map[soko->y][soko->x + 2] == 'O') {
            map[soko->y][soko->x] = ' ';
            map[soko->y][soko->x + 1] = 'P';
            map[soko->y][soko->x + 2] = 'X';
            soko->x += 1;
        }
    }
    return check_win(map, cpy);
}

int key_lft(char **map, sokoabn_t *soko, char **cpy)
{
    if ((soko->x - 1) < 0 || map[soko->y][soko->x - 1] == 35)
        return -1;
    if (map[soko->y][soko->x - 1] == ' ' ||
        map[soko->y][soko->x - 1] == 'O') {
        map[soko->y][soko->x] = ' ';
        map[soko->y][soko->x - 1] = 'P';
        soko->x -= 1;
        return check_win(map, cpy);
    }
    if (map[soko->y][soko->x - 1] == 'X') {
        if (map[soko->y][soko->x - 2] == ' ' ||
            map[soko->y][soko->x - 2] == 'O') {
            map[soko->y][soko->x] = ' ';
            map[soko->y][soko->x - 1] = 'P';
            map[soko->y][soko->x - 2] = 'X';
            soko->x -= 1;
        }
    }
    return check_win(map, cpy);
}

int key_dwn(char **map, sokoabn_t *soko, char **cpy)
{
    if ((soko->y + 1) > (soko->nb_lines - 1) ||
        map[soko->y + 1][soko->x] == 35)
        return -1;
    if (map[soko->y + 1][soko->x] == ' ' ||
        map[soko->y + 1][soko->x] == 'O') {
        map[soko->y][soko->x] = ' ';
        map[soko->y + 1][soko->x] = 'P';
        soko->y += 1;
        return check_win(map, cpy);
    }
    if (map[soko->y + 1][soko->x] == 'X') {
        if (map[soko->y + 2][soko->x] == ' ' ||
            map[soko->y + 2][soko->x] == 'O') {
            map[soko->y][soko->x] = ' ';
            map[soko->y + 1][soko->x] = 'P';
            map[soko->y + 2][soko->x] = 'X';
            soko->y += 1;
        }
    }
    return check_win(map, cpy);
}
