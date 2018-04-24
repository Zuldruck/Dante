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

	if (c == 'X')
		tile.blocked = 1;
	else
		tile.blocked = 0;
	tile.close = 0;
	tile.open = 0;
	tile.g_cost = -1;
	tile.h_cost = -1;
	tile.f_cost = -1;
	tile.parent = (pos_t){0, 0};
	return (tile);
}

maze_t map_to_maze(char **map)
{
	int i = 0;
	tile_t **maze = NULL;
	maze_t maze_info;

	for (i = 0; map[i]; i++);
	maze = malloc(sizeof(*maze) * (i + 1));
	maze_info.height = i;
	maze_info.width = strlen(map[0]);
	for (i = 0; map[i]; i++) {
		maze[i] = malloc(sizeof(tile_t) * (strlen(map[i])));
		for (int j = 0; map[i][j]; j++)
			maze[i][j] = fill_tile_info(map[i][j]);
	}
	maze[i] = NULL;
	maze_info.map = maze;
	return (maze_info);
}