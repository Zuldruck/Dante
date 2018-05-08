/*
** EPITECH PROJECT, 2018
** solver
** File description:
** a_star_utilities
*/

#include "dante.h"

int compute_h_cost(maze_t *maze, int pos)
{
	return ((maze->height - pos / (maze->width + 1)) +
				(maze->width - pos % (maze->width + 1)));
}

void set_maze_path(char *map, maze_t *maze)
{
	int pos = maze->size - 1;

	while (map[0] != 'o') {
		map[pos] = 'o';
		pos = maze->map[pos].parent;
	}
}