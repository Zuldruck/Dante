/*
** EPITECH PROJECT, 2017
** generator
** File description:
** get.c
*/

#include <generator.h>

int get_direction(int pos, int next_pos, generator_t *generator)
{
	if (pos == NORTH(next_pos))
		return (SOUTH);
	if (pos == SOUTH(next_pos))
		return (NORTH);
	if (pos == EAST(next_pos))
		return (WEST);
	if (pos == WEST(next_pos))
		return (EAST);
	return (0);
}

/// ! Risky zone ! ///

void get_next_pos(track_t **track, generator_t *generator)
{
	int index = rand() % (*track)->nb_path;
	int next_pos = (*track)->pathes[index];

	//printf("pos = %d\n\t nb_path = %d index = %d\n\tnext_pos = %d\n\t\t tab = %d || %d || %d || %d\n", INDEX, (*track)->nb_path, index, next_pos, (*track)->pathes[0], (*track)->pathes[1], (*track)->pathes[2], (*track)->pathes[3]);
	(*track)->nb_path--;
	(*track)->valids[get_direction((*track)->pos,
					next_pos, generator)] = false;
	TRACKER[next_pos].prev = *track;
	for (int i = index; i != 2; i++)
		(*track)->pathes[i] = (*track)->pathes[i + 1];
		//printf("\tnb_path = %d tab = %d || %d || %d || %d\n", (*track)->nb_path, (*track)->pathes[0], (*track)->pathes[1], (*track)->pathes[2], (*track)->pathes[3]);
	*track = &TRACKER[next_pos];
	INDEX = next_pos;
	set_track(*track, generator);
}
