##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## all clean fclean re
##

SRC	=	src/main.c		\
		src/init/generator.c	\
		src/generator/backtrack/start.c	\
		src/generator/backtrack/track.c	\
		src/generator/backtrack/path.c	\

OBJS	=	$(SRC:.c=.o)

NAME_BINARY	=	generator

NAME	=	generator

NAME2	=	unit-tests

CFLAGS	=	 -Wall -Wextra -W -I./include/ -Ofast

CC	=	gcc

_END=$'\x1b[0m'
_RED=$'\x1b[31m'
NO_OF_FILES := $(words $(SRC))

all:	$(NAME)

tests_run:
	make -C tests/
	tests/unit-tests


$(NAME):	$(OBJS)
	@ echo "\033[1;36m[ FILES COMPILED ] \033[0m \033[1;35m$(NO_OF_FILES)\033[0m"
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS) $(CFLAGS)
	@ echo "\033[1;31m ------------------Name of Binary : \033[1;35m$(NAME)\033[0;31m®\033[1;31m Created Sucesfully ------------------\033[0m"

clean:
	make clean -C tests/
	$(RM) $(OBJS)

fclean:	clean
	make fclean -C tests/
	$(RM) $(NAME)

re:	fclean all
re_game: fclean game


%.o:	%.c
	@ echo "\033[1;35m[ OK ]\033[0m Compiling" $<
	@ $(CC) -o $@ -c $< $(CFLAGS)

.SILENT:
