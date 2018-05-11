/*
** EPITECH PROJECT, 2018
** dante
** File description:
** init_a_star
*/

#include "dante.h"

tile_t fill_tile_info(char c)
{
	tile_t tile;

	if (c == 'X' || c == '\n')
		tile.blocked = 1;
	else
		tile.blocked = 0;
	tile.close = 0;
	tile.open = 0;
	tile.g_cost = -1;
	tile.f_cost = -1;
	tile.parent = 0;
	return (tile);
}

tile_t *map_to_maze(char *map, int size)
{
	tile_t *maze = NULL;

	maze = malloc(sizeof(*maze) * size);
	for (unsigned int i = size; i > 0; --i)
		maze[i] = fill_tile_info(map[i]);
	return (maze);
}

void start(char *map, maze_t *maze)
{
	list_t *open_list = NULL;

	maze->map = map_to_maze(map, maze->size);
	maze->map[0].open = 1;
	open_list = malloc(sizeof(*open_list));
	open_list->pos = 0;
	open_list->next = NULL;
	a_star_loop(maze, open_list);
	set_maze_path(map, maze);
	write(1, map, maze->size);
}