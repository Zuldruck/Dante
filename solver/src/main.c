/*
** EPITECH PROJECT, 2018
** dante
** File description:
** dante made by Sanchez Lucas
*/

#include "dante.h"

int check_start_end(char *maze, int size)
{
	if (maze[0] == 'X' || maze[size - 1] == 'X')
		return (1);
	return (0);
}

void my_signals(int sig)
{
	if (sig == SIGSEGV)
		exit(84);
}

int main(int ac, char **av)
{
	char *map = NULL;
	maze_t maze;

	if (ac != 2)
		return (84);
	signal(SIGSEGV, &my_signals);
	map = parse_file(&maze, av[1]);
	if (!map)
		return (84);
	maze.size = (maze.width + 1) * maze.height - 1;
	if (check_start_end(map, maze.size) == 1) {
		printf("no solution found");
		return (0);
	}
	start(map, &maze);
	return (0);
}
