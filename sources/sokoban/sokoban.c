/*
** EPITECH PROJECT, 2022
** sokoban.c
** File description:
** sokoban.c
*/

#include "sokoban.h"

int sokoban(char *str)
{
    WINDOW *wind;
    sokoabn_t *soko = set_soko();
    char **map = set_map(str, soko);
    char **cpy = set_map(str, soko);
    int key = 0;

    wind = initscr();
    noecho();
    keypad(wind, TRUE);
    while (1) {
        print_map(map);
        check_resize(soko);
        refresh();
        key = getch();
        key = check_key(key, map, cpy, soko);
        if (key == 0 || key == 1)
            return returning(map, cpy, key, soko);
        clear();
    }
    return returning(map, cpy, 1, soko);
}

void free_map(char **map)
{
    for (int i = 0; map[i] != NULL; i += 1)
        free(map[i]);
    free(map);
    return;
}

int returning(char **map, char **cpy, int flag, sokoabn_t *soko)
{
    clear();
    print_map(map);
    refresh();
    endwin();
    free_map(map);
    free_map(cpy);
    free(soko);
    return flag;
}

sokoabn_t *set_soko(void)
{
    sokoabn_t *new = malloc(sizeof(*new));

    new->nb_lines = 0;
    new->x = 0;
    new->y = 0;
    new->x_save = 0;
    new->y_save = 0;
    new->status = 0;
    new->len_max = 0;
    return new;
}

void find_player(sokoabn_t *soko, char **map, int nb, int a)
{
    if (map[nb][a] == 'P') {
        soko->x = a;
        soko->y = nb;
        soko->x_save = a;
        soko->y_save = nb;
    }
    return;
}
