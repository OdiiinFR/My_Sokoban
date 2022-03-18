/*
** EPITECH PROJECT, 2022
** map
** File description:
** map
*/

#include "sokoban.h"

int count_lines(char *str)
{
    int fd = open(str, O_RDONLY);
    int ctr = 0;
    char *buff = malloc(sizeof(char) * 100000);

    for (int a = 0; a != 100000; a += 1)
        buff[a] = '\0';
    read(fd, buff, 100000);
    for (int i = 0; buff[i] != '\0'; i += 1) {
        if (buff[i] == '\n' && buff[i + 1] != '\0')
            ctr += 1;
    }
    ctr += 1;
    close(fd);
    free(buff);
    return ctr;
}

char **set_map(char *str, sokoabn_t *soko)
{
    soko->nb_lines = count_lines(str);
    int fd = open(str, O_RDONLY);
    size_t size = get_size(str);
    char *buff = malloc(sizeof(char) * (size + 1));
    char **map = malloc(sizeof(char *) * (soko->nb_lines + 1));

    read(fd, buff, size);
    buff[size] = '\0';
    for (int i = 0, j = 0, nb = 0, a = 0; buff[i] != '\0'; nb += 1) {
        for (j = 0; buff[i + j] != '\n' && buff[i + j] != '\0'; j += 1);
        map[nb] = malloc(sizeof(char) * (j + 2));
        check_lenmax((j + 1), soko);
        for (a = 0; a <= j && buff[i] != '\0'; i += 1, a += 1) {
            map[nb][a] = buff[i];
            find_player(soko, map, nb, a);
        }
        map[nb][a] = '\0';
    }
    map[soko->nb_lines] = NULL;
    return set_map2(map, fd, buff);
}

void print_map(char **map)
{
    int x = 0;
    int y = 0;
    for (int i = 0; map[i] != NULL; i += 1) {
        mvprintw(y, x, map[i]);
        y += 1;
    }
    return;
}

size_t get_size(char *str)
{
    size_t size = 0;
    struct stat test;
    stat(str, &test);
    size = test.st_size;
    return size;
}

char **set_map2(char **map, int fd, char *buff)
{
    free(buff);
    close(fd);
    return map;
}
