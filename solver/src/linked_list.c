/*
** EPITECH PROJECT, 2018
** dante
** File description:
** linked_list
*/

#include "dante.h"

void add_node(list_t **list, pos_t pos)
{
	list_t *tmp = malloc(sizeof(*tmp));

	tmp->pos = pos;
	tmp->next = NULL;
	if (!*list) {
		*list = tmp;
		return;
	}
	while ((*list)->next != NULL)
		*list = (*list)->next;
	(*list)->next = tmp;
}

int check_first_node(list_t **list, pos_t pos_to_remove)
{
	list_t *tmp = NULL;

	if ((*list)->pos.x == pos_to_remove.x
	&& (*list)->pos.y == pos_to_remove.y) {
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
		return (1);
	}
	return (0);
}

void remove_node(list_t **list, pos_t pos_to_remove)
{
	list_t *tmp = *list;
	list_t *tmp_free = NULL;

	if (!*list)
		return;
	if (check_first_node(list, pos_to_remove) == 1)
		return;
	while (tmp && tmp->next) {
		if (tmp->next->pos.x == pos_to_remove.x
		&& tmp->next->pos.y == pos_to_remove.y) {
			tmp_free = tmp->next;
			tmp->next = tmp->next->next;
			free(tmp_free);
			return;
		}
		tmp = tmp->next;
	}
}