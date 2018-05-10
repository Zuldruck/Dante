/*
** EPITECH PROJECT, 2017
** generator
** File description:
** start.c
*/

#include <generator.h>

void start_generator(generator_t *generator)
{
	track_t *track = &TRACKER[0];

	set_track(track, generator);
	get_next_pos(&track, generator);
	while (track->pos != 0) {
		if (track->nb_path == 0) {
			backtrack(&track, generator);
		} else {
			get_next_pos(&track, generator);
		}
		if (END_NOT_DUG)
			keep_end_track(&track, generator);
	}
}