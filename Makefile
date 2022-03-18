##
## EPITECH PROJECT, 2021
## Cpool_part2 2026
## File description:
## Makefile
##

SRC	=	sources/sokoban/main/main.c	\
		sources/my/my_putstr.c	\
		sources/sokoban/error_handling/error_handling.c	\
		sources/sokoban/sokoban.c	\
		sources/sokoban/map/map.c	\
		sources/sokoban/movement/moove.c	\
		sources/sokoban/movement/key_space.c	\
		sources/sokoban/movement/player_pos.c	\
		sources/sokoban/movement/conditions.c	\
		sources/sokoban/map/check_lenmax.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Iincludes -lncurses

NAME	=	my_sokoban

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) $(CFLAGS) -g3

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f *~
	rm -f *'#'
	rm -f *vgcore.*
	rm -f *.gdb
	rm -f $(NAME)

re:	fclean all
