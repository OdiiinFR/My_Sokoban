/*
** EPITECH PROJECT, 2022
** error_handling.c
** File description:
** error_handling.c
*/

#include "sokoban.h"

int error_map(char *str)
{
    int fd = open(str, O_RDONLY);

    if (fd == -1)
        return 84;
    close(fd);
    return 0;
}

int check_map(char *str)
{
    int fd = open(str, O_RDONLY);
    char *buff = malloc(sizeof(char) * 100000);

    for (int a = 0; a != 100000; a += 1)
        buff[a] = '\0';
    read(fd, buff, 100000);
    for (int i = 0; buff[i] != '\0'; i += 1) {
        if (buff[i] != 32 && buff[i] != 10 && buff[i] != 35 && buff[i] != 88
            && buff[i] != 'P' && buff[i] != 'O')
            return free_buff(buff, fd);
    }
    free(buff);
    close(fd);
    return 0;
}

int free_buff(char *buff, int fd)
{
    free(buff);
    close(fd);
    return 84;
}

void check_resize(sokoabn_t *soko)
{
    struct winsize fen;

    ioctl(0, TIOCGWINSZ, &fen);
    if (fen.ws_col < soko->len_max || fen.ws_row < soko->nb_lines)
        mvprintw(fen.ws_row / 2, fen.ws_col / 2 - 8, "enlarge terminal");
    return;
}
