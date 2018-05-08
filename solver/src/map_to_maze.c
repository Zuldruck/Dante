/*
** EPITECH PROJECT, 2018
** dante
** File description:
** map_to_maze
*/

#include "dante.h"

tile_t fill_tile_info(char c)
{
	tile_t tile;

	if (c == 'X' || c == '\n')
		tile.blocked = 1;
	else
		tile.blocked = 0;
	if (c == '\n')
		tile.limit = true;
	else
		tile.limit = false;
	tile.close = 0;
	tile.open = 0;
	tile.g_cost = -1;
	tile.h_cost = -1;
	tile.f_cost = -1;
	tile.parent = 0;
	return (tile);
}

tile_t *map_to_maze(char *map, int size)
{
	int i = 0;
	tile_t *maze = NULL;

	maze = malloc(sizeof(*maze) * size);
	for (i = 0; map[i]; i++)
		maze[i] = fill_tile_info(map[i]);
	return (maze);
}