/*
** EPITECH PROJECT, 2018
** solver
** File description:
** a_star_utilities
*/

#include "dante.h"

list_t *find_smallest_open(list_t *open_list, maze_t maze)
{
	list_t *smallest = open_list;

	if (!open_list)
		return (NULL);
	open_list = open_list->next;
	while (open_list) {
		if (MAZE_POS.f_cost <= maze.\
		map[smallest->pos.x][smallest->pos.y].f_cost
		&& MAZE_POS.h_cost <= maze.\
		map[smallest->pos.x][smallest->pos.y].f_cost)
			smallest = open_list;
		open_list = open_list->next;
	}
	return (smallest);
}

int compute_h_cost(maze_t *maze, pos_t pos)
{
	int a = ABS(maze->width - 1 - pos.y);
	int b = ABS(maze->height - 1 - pos.x);

	return ((a + b) * 10);
}

void set_maze_path(char **map, maze_t maze)
{
	pos_t pos = (pos_t){maze.height - 1, maze.width - 1};

	while (map[0][0] != 'o') {
		map[pos.x][pos.y] = 'o';
		pos = maze.map[pos.x][pos.y].parent;
	}
}