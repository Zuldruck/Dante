/*
** EPITECH PROJECT, 2017
** generator
** File description:
** get.c
*/

#include <generator.h>

int get_direction(int pos, int next_pos, generator_t *generator)
{
	switch (next_pos) {
		case NORTH:
		return (NORTH(pos));
		case SOUTH:
		return (SOUTH(pos));
		case EAST:
		return (EAST(pos));
		case WEST:
		return (WEST(pos));
	}
	return (0);
}

/// ! Risky zone ! ///

void get_next_pos(track_t **track, generator_t *generator)
{
	int next_pos = 0;
	int random = rand() % (*track)->nb_path + 1;
	int direction = 0;

	for (; random; next_pos++) {
		if ((*track)->pathes[next_pos] == true)
			random--;
		if (random == 0)
			break;
	}
	(*track)->nb_path--;
	(*track)->pathes[next_pos] = false;
	direction = get_direction((*track)->pos, next_pos, generator);
	TRACKER[direction].prev = *track;
	*track = &TRACKER[direction];
	INDEX = direction;
	set_track(*track, generator);
}
