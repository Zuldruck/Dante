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
	int next_pos = 3;
	int random = 3 - rand() % (*track)->nb_path;
	int directions[4] = {0, 0, 0, 0};

	for (int i = 4; i; i--) {
		if ((*track)->pathes[i - 1] == true) {
			directions[next_pos] = i - 1;
			next_pos--;
		}
	}
	(*track)->nb_path--;
	(*track)->pathes[directions[random]] = false;
	directions[0] = get_direction((*track)->pos,
	directions[random], generator);
	TRACKER[directions[0]].prev = *track;
	*track = &TRACKER[directions[0]];
	INDEX = directions[0];
	set_track(*track, generator);
}
