##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

all:	
	make -C generator
	make -C solver

clean:
	make clean -C generator
	make clean -C solver

fclean:
	make fclean -C generator
	make fclean -C solver

re:	fclean all
