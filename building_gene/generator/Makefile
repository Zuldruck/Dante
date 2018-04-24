##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	= 	src/main.c		\
		src/parsing.c		\
		src/linked_list.c	\
		src/init_a_star.c	\
		src/map_to_maze.c	\
		src/a_star.c		\
		src/a_star_utils.c	\

OBJ	=	$(SRC:.c=.o)

CC	= 	gcc -Wextra -Wall -Werror -g3 -no-pie

NAME	=	generator

LIB_NAME	=	libmy.a

FLAGS	=	-L./lib/my -lmy

CFLAGS	=	-I./include

all:	prepare_lib $(NAME)

prepare_lib:
	make -C lib/my

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(CFLAGS)

clean:
	make clean -C lib/my
	rm -f $(OBJ)

fclean:	clean
	rm -f lib/my/$(LIB_NAME)
	rm -f $(NAME)

re:	fclean all
