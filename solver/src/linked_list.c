/*
** EPITECH PROJECT, 2018
** dante
** File description:
** linked_list
*/

#include "dante.h"

void add_node(maze_t *maze, list_t **list, int pos)
{
	list_t *tmp_node = malloc(sizeof(*tmp_node));
	list_t *tmp = *list;

	tmp_node->pos = pos;
	tmp_node->next = NULL;
	if (!*list) {
		*list = tmp_node;
		return;
	} else if (maze->map[pos].f_cost <= maze->map[tmp->pos].f_cost) {
		tmp_node->next = tmp;
		*list = tmp_node;
		return;
	}
	while (tmp->next != NULL
	&& maze->map[pos].f_cost > maze->map[tmp->next->pos].f_cost)
		tmp = tmp->next;
	tmp_node->next = tmp->next;
	tmp->next = tmp_node;
}