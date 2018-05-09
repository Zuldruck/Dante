/*
** EPITECH PROJECT, 2018
** dante
** File description:
** init_a_star
*/

#include "dante.h"

void start(char *map, maze_t *maze)
{
	list_t *tab = malloc(sizeof(list_t) *
					(maze->height * (maze->width + 1)));
	list_t *open_list = NULL;

	maze->map = map_to_maze(map, maze->size);
	maze->map[0].open = 1;
	open_list = &tab[0];
	open_list->pos = 0;
	open_list->next = NULL;
	a_star_loop(maze, open_list, tab);
	set_maze_path(map, maze);
	write(1, map, maze->size);
}