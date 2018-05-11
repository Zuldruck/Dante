/*
** EPITECH PROJECT, 2018
** solver
** File description:
** a_star
*/

#include "dante.h"

void set_open_costs(maze_t *maze, list_t **open_list, int pos, int parent)
{
	int g_cost = maze->map[parent].g_cost == -1 ? 1 :
			maze->map[parent].g_cost + 1;
	int h_cost = compute_h_cost(maze, pos);
	int f_cost = g_cost + h_cost;

	if (maze->map[pos].f_cost < 0 || f_cost < maze->map[pos].f_cost) {
		maze->map[pos].parent = parent;
		maze->map[pos].g_cost = g_cost;
		maze->map[pos].f_cost = f_cost;
	}
	if (!maze->map[pos].open) {
		add_node(maze, open_list, pos);
		maze->map[pos].open = true;
	}
}

void add_sides_to_open_list(maze_t *maze, list_t **open_list, int pos)
{
	if (EAST(pos) < maze->size && !maze->map[EAST(pos)].blocked
	&& !maze->map[EAST(pos)].close)
		set_open_costs(maze, open_list, EAST(pos), pos);
	if (WEST(pos) >= 0 && !maze->map[WEST(pos)].blocked
	&& !maze->map[WEST(pos)].close)
		set_open_costs(maze, open_list, WEST(pos), pos);
	if (SOUTH(pos) < maze->size && !maze->map[SOUTH(pos)].blocked
	&& !maze->map[SOUTH(pos)].close)
		set_open_costs(maze, open_list, SOUTH(pos), pos);
	if (NORTH(pos) >= 0 && !maze->map[NORTH(pos)].blocked
	&& !maze->map[NORTH(pos)].close)
		set_open_costs(maze, open_list, NORTH(pos), pos);
}

void a_star_loop(maze_t *maze, list_t *open_list)
{
	list_t *open = NULL;
	int last_char = maze->size - 1;

	for (open = open_list; !maze->map[WEST(last_char)].close
	&& !maze->map[NORTH(last_char)].close && open; open = open_list) {
		open_list = open_list->next;
		add_sides_to_open_list(maze, &open_list, open->pos);
		maze->map[open->pos].close = true;
	}
	if (!maze->map[WEST(last_char)].close
	&& !maze->map[NORTH(last_char)].close) {
		printf("no solution found");
		exit(0);
	}
	maze->map[last_char].close = true;
}