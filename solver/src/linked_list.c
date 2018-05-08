/*
** EPITECH PROJECT, 2018
** dante
** File description:
** linked_list
*/

#include "dante.h"

void add_node(maze_t *maze, list_t **list, list_t *tab, int pos)
{
	list_t *tmp_node = NULL;
	list_t *tmp = *list;

	tmp_node = &tab[pos];
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
	&& maze->map[pos].f_cost > maze->map[tmp->next->pos].f_cost) {
		tmp = tmp->next;
	}
	tmp_node->next = tmp->next;
	tmp->next = tmp_node;
}

void remove_node(list_t **list, int pos)
{
	list_t *tmp = *list;

	if (!*list)
		return;
	if ((*list)->pos == pos) {
		*list = (*list)->next;
		return;
	}
	while (tmp->next->pos != pos)
		tmp = tmp->next;
	tmp->next = tmp->next->next;
}