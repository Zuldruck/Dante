/*
** EPITECH PROJECT, 2017
** generator
** File description:
** start.c
*/

#include <generator.h>

void get_double_direction(int pos, int next_pos, generator_t *generator)
{
	if (pos == DNORTH(next_pos)) {
		MAP[SOUTH(pos)] = '*';
	}
	if (pos == DSOUTH(next_pos)) {
		MAP[NORTH(pos)] = '*';
	}
	if (pos == DEAST(next_pos)) {
		MAP[WEST(pos)] = '*';
	}
	if (pos == DWEST(next_pos)) {
		MAP[EAST(pos)] = '*';
	}
}

void get_double_next_pos(track_t **track, generator_t *generator)
{
	int index = rand() % (*track)->nb_path;
	int next_pos = (*track)->pathes[index];

	(*track)->nb_path--;
	get_double_direction(INDEX, next_pos, generator);
	TRACKER[next_pos].prev = *track;
	for (int i = index; i != 2; i++)
		(*track)->pathes[i] = (*track)->pathes[i + 1];
	*track = &TRACKER[next_pos];
	INDEX = next_pos;
	set_double_track(*track, generator);
}

void start_backtrack(generator_t *generator)
{
	track_t *track = &TRACKER[0];
	bool odd = SIZE % 2;

	set_double_track(track, generator);
	get_double_next_pos(&track, generator);
	while (track->pos != 0) {
		if (track->nb_path == 0) {
			double_backtrack(&track, generator);
		} else {
			get_double_next_pos(&track, generator);
		}
	}
	MAP[SIZE - 2] = '*';
	if (odd == false)
		MAP[SIZE - 3] = '*';
}