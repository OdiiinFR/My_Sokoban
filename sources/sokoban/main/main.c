/*
** EPITECH PROJECT, 2022
** main sokoban
** File description:
** main sokoban
*/

#include "sokoban.h"

int main(int argc, char **argv)
{
    if (argc != 2)
        return arg_error();
    if (strcompare(argv[1], "-h") == 0)
        return usage();
    if (error_map(argv[1]) == 84)
        return print_error_map();
    if (check_map(argv[1]) == 84)
        return print_error_map();
    return sokoban(argv[1]);
}

int arg_error(void)
{
    write(2, "This programm need 2 arguments !\n", 34);
    return 84;
}

int usage(void)
{
    write(1, "USAGE :\n", 9);
    write(1, "    ./my_sokoban map\n", 22);
    write(1, "DESCRIPTION :\n", 15);
    write(1, "    map : file representing the warehouse map, containing", 58);
    write(1, " '#' for walls,\n          'P' for the player, 'X' for box", 58);
    write(1, "es and 'O' for storage locations.\n", 35);
    return 0;
}

int print_error_map(void)
{
    write(2, "Map invalid\n", 13);
    return 84;
}
