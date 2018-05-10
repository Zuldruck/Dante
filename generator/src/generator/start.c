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
			//printf("\n\nbacktrack from %d, nb %d, tab %d || %d || %d || %d\n", INDEX, track->nb_path, track->pathes[0], track->pathes[1], track->pathes[2], track->pathes[3]);
			backtrack(&track, generator);
			//printf("backtrack to %d, nb %d, tab %d || %d || %d || %d\n\n", INDEX, track->nb_path, track->pathes[0], track->pathes[1], track->pathes[2], track->pathes[3]);
		} else {
			//printf("\nget_next_pos from %d, nb %d, tab %d || %d || %d || %d\n", INDEX, track->nb_path, track->pathes[0], track->pathes[1], track->pathes[2], track->pathes[3]);
			get_next_pos(&track, generator);
			//printf("get_next_pos to %d, nb %d, tab %d || %d || %d || %d\n\n", INDEX, track->nb_path, track->pathes[0], track->pathes[1], track->pathes[2], track->pathes[3]);
		}
		if (END_NOT_DUG)
			keep_end_track(&track, generator);
		//printf("%s\n", MAP);
	}
}