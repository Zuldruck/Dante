/*
** EPITECH PROJECT, 2018
** solver
** File description:
** a_star
*/

#include "dante.h"

void set_open_costs(maze_t *maze, list_t *open_list, pos_t pos, pos_t parent)
{
	int g_cost = maze->map[parent.x][parent.y].g_cost == -1 ? 10 :
			maze->map[parent.x][parent.y].g_cost + 10;
	int h_cost = compute_h_cost(maze, pos);
	int f_cost = g_cost + h_cost;


	if (!maze->map[pos.x][pos.y].open) {
		add_node(&open_list, pos);
		maze->map[pos.x][pos.y].open = true;
	}
	if (maze->map[pos.x][pos.y].f_cost < 0
	|| f_cost < maze->map[pos.x][pos.y].f_cost) {
		maze->map[pos.x][pos.y].parent = parent;
		maze->map[pos.x][pos.y].g_cost = g_cost;
		maze->map[pos.x][pos.y].h_cost = h_cost;
		maze->map[pos.x][pos.y].f_cost = f_cost;
	}
}

void add_sides_to_open_list(maze_t *maze, list_t *open_list, pos_t pos)
{
	if (pos.y + 1 < maze->width && !maze->map[pos.x][pos.y + 1].blocked
	&& !maze->map[pos.x][pos.y + 1].close)
		set_open_costs(maze, open_list, (pos_t){pos.x, pos.y + 1}, pos);
	if (pos.y - 1 >= 0 && !maze->map[pos.x][pos.y - 1].blocked
	&& !maze->map[pos.x][pos.y - 1].close)
		set_open_costs(maze, open_list, (pos_t){pos.x, pos.y - 1}, pos);
	if (pos.x + 1 < maze->height && !maze->map[pos.x + 1][pos.y].blocked
	&& !maze->map[pos.x + 1][pos.y].close)
		set_open_costs(maze, open_list, (pos_t){pos.x + 1, pos.y}, pos);
	if (pos.x - 1 >= 0 && !maze->map[pos.x - 1][pos.y].blocked
	&& !maze->map[pos.x - 1][pos.y].close)
		set_open_costs(maze, open_list, (pos_t){pos.x - 1, pos.y}, pos);
}

void a_star_loop(maze_t maze, list_t *open_list)
{
	list_t *open = NULL;

	while (!maze.map[maze.height - 1][maze.width - 1].close) {
		open = find_smallest_open(open_list, maze);
		if (!open)
			break;
		add_sides_to_open_list(&maze, open_list, open->pos);
		maze.map[open->pos.x][open->pos.y].close = true;
		remove_node(&open_list, open->pos);
	}
}