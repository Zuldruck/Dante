/*
** EPITECH PROJECT, 2018
** dante
** File description:
** dante made by Sanchez Lucas
*/

#include "dante.h"

int check_start_end(char **maze)
{
	int i = 0;

	for (i = 0; maze[i]; i++);
	if (maze[0][0] == 'X' || maze[i - 1][strlen(maze[i - 1]) - 1] == 'X')
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	char **maze = NULL;

	if (ac != 2)
		return (84);
	maze = parse_file(av[1]);
	if (!maze)
		return (84);
	if (check_start_end(maze) == 1) {
		printf("no solution found\n");
		return (0);
	}
	start(maze);
	return (0);
}
