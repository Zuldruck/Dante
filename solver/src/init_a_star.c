/*
** EPITECH PROJECT, 2018
** dante
** File description:
** init_a_star
*/

#include "dante.h"

void start(char **map)
{
	maze_t maze = map_to_maze(map);
	list_t *open_list = NULL;

	add_node(&open_list, (pos_t){0, 0});
	maze.map[0][0].open = true;
	a_star_loop(maze, open_list);
	set_maze_path(map, maze);
	for (int i = 0; map[i]; i++) {
		write(1, map[i], strlen(map[i]));
		if (map[i + 1])
			write(1, "\n", 1);
	}
}