/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** sokoban
*/

#ifndef SOKOBAN_H
    #define SOKOBAN_H

    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <curses.h>
    #include <locale.h>
    #include <sys/ioctl.h>

typedef struct sokoban {
    int nb_lines;
    int x;
    int y;
    int x_save;
    int y_save;
    int len_max;
    int status;
} sokoabn_t;

//sources/sokoaban/main/main.c

int main(int argc, char **argv);
int arg_error(void);
int usage(void);
int print_error_map(void);

//sources/my/my_putstr.c

int my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int strcompare(char *str1, char *str2);
int strncompare(char *str1, char *str2, int n);

//sources/sokoban/error_handling/error_handling.c

int error_map(char *str);
int check_map(char *str);
int free_buff(char *buff, int fd);
void check_resize(sokoabn_t *soko);

//sources/sokoban/map/map.c

int count_lines(char *str);
void print_map(char **map);
char **set_map(char *str, sokoabn_t *soko);
size_t get_size(char *str);
char **set_map2(char **map, int fd, char *buff);

//sources/sokoban/sokoban.c

int sokoban(char *map);
void free_map(char **map);
int returning(char **map, char **cpy, int flag, sokoabn_t *soko);
sokoabn_t *set_soko(void);
void find_player(sokoabn_t *soko, char **map, int nb, int a);

//sources/sokoban/movement/moove.c

int check_key(int key, char **map, char **cpy, sokoabn_t *soko);
int key_up(char **map, sokoabn_t *soko, char **cpy);
int key_rgt(char **map, sokoabn_t *soko, char **cpy);
int key_lft(char **map, sokoabn_t *soko, char **cpy);
int key_dwn(char **map, sokoabn_t *soko, char **cpy);

//sources/sokoaban/movement/key_space.c

int key_spc(char **map, char **cpy, sokoabn_t *soko);
int checkup(char **map, sokoabn_t *soko);
int checkrgt(char **map, sokoabn_t *soko);
int checklft(char **map, sokoabn_t *soko);
int checkdwn(char **map, sokoabn_t *soko);

//sources/sokoban/movement/player_pos.c

int get_player_x(char **map);
int get_player_y(char **map);
int info_player(int i, int j, char **map, int flag);
void check_win_cond(char **map, int *win, int i, int j);

//sources/sokoban/movement/conditions.c

int check_win(char **map, char **cpy);
int check_around(char **map, int x, int y);
int check_around2(char **map, int x, int y);
int find_nb(char **map, char **cpy, int *win, int i);
int find_win(char **map, int i, int j);

//sources/sokoban/map/check_lenmax.c

void check_lenmax(int len, sokoabn_t *soko);

#endif /* !SOKOBAN_H */
