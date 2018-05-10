/*
** EPITECH PROJECT, 2017
** generator
** File description:
** track.c
*/

#include <generator.h>

/// en gros :
/// - Si on est au nord de l'arrivé ou en diagonale, on se déplace au
/// sud.
/// - Si on est à l'ouest, on se déplace à l'est
/// dans les deux cas, on retire le passage des possibilités, on assigne le
/// prev, on replace le tracker et on appel set_track

void keep_end_track(track_t **track, generator_t *generator)
{
	if (INDEX == NORTH(END) || INDEX == NORTH(END) - 1) {
			//printf("end south or diag from %d, tab %d || %d || %d || %d\n\n", INDEX, (*track)->pathes[0], (*track)->pathes[1], (*track)->pathes[2], (*track)->pathes[3]);
		(*track)->valids[SOUTH] = false;
		(*track)->nb_path--;
		TRACKER[SOUTH(INDEX)].prev = *track;
		*track = &TRACKER[SOUTH(INDEX)];
		INDEX = SOUTH(INDEX);
		set_track(*track, generator);
			//printf("end south or diag to %d, tab %d || %d || %d || %d\n\n", INDEX, (*track)->pathes[0], (*track)->pathes[1], (*track)->pathes[2], (*track)->pathes[3]);
	} else if (INDEX == WEST(END)) {
			//printf("end west from %d, tab %d || %d || %d || %d\n\n", INDEX, (*track)->pathes[0], (*track)->pathes[1], (*track)->pathes[2], (*track)->pathes[3]);
		(*track)->valids[EAST] = false;
		(*track)->nb_path--;
		TRACKER[EAST(INDEX)].prev = *track;
		*track = &TRACKER[EAST(INDEX)];
		INDEX = EAST(INDEX);
		set_track(*track, generator);
			//printf("end west to %d, tab %d || %d || %d || %d\n\n", INDEX, (*track)->pathes[0], (*track)->pathes[1], (*track)->pathes[2], (*track)->pathes[3]);
	}
}

void reset_track(track_t *track, generator_t *generator)
{
	track->pos = INDEX;
	//printf("before reset %d, nb %d, tab %d || %d || %d || %d\n", INDEX, track->nb_path, track->pathes[0], track->pathes[1], track->pathes[2], track->pathes[3]);
	//printf("true tab %d || %d || %d || %d\n", track->valids[0], track->valids[1], track->valids[2], track->valids[3]);
	track->nb_path = 0;
	if (track->valids[NORTH] == true)
		track->valids[NORTH] = check_valid_path(track,
		NORTH(INDEX), generator);
	if (track->valids[SOUTH] == true)
		track->valids[SOUTH] = check_valid_path(track,
		SOUTH(INDEX), generator);
	if (track->valids[EAST] == true)
		track->valids[EAST] = check_valid_path(track,
		EAST(INDEX), generator);
	if (track->valids[WEST] == true)
		track->valids[WEST] = check_valid_path(track,
		WEST(INDEX), generator);
	//printf("after reset %d, nb %d, tab %d || %d || %d || %d\n", INDEX, track->nb_path, track->pathes[0], track->pathes[1], track->pathes[2], track->pathes[3]);
	//printf("true tab %d || %d || %d || %d\n", track->valids[0], track->valids[1], track->valids[2], track->valids[3]);
}

void backtrack(track_t **track, generator_t *generator)
{
	(*track) = (*track)->prev;
	INDEX = (*track)->pos;
	reset_track(*track, generator);
}

void set_track_values(track_t *track, generator_t *generator)
{
	track->pos = INDEX;
	track->nb_path = 0;
	track->pathes[0] = 0;
	track->pathes[1] = 0;
	track->pathes[2] = 0;
	track->pathes[3] = 0;
	track->valids[NORTH] = false;
	track->valids[SOUTH] = false;
	track->valids[EAST] = false;
	track->valids[WEST] = false;
	MAP[track->pos] = '*';
}

void set_track(track_t *track, generator_t *generator)
{
	int prev_pos = 0;

	if (INDEX != 0)
		prev_pos = track->prev->pos;
	set_track_values(track, generator);
	if (NORTH(INDEX) != prev_pos)
		track->valids[NORTH] = check_valid_path(track,
		NORTH(INDEX), generator);
	if (SOUTH(INDEX) != prev_pos)
		track->valids[SOUTH] = check_valid_path(track,
		SOUTH(INDEX), generator);
	if (EAST(INDEX) != prev_pos)
		track->valids[EAST] = check_valid_path(track,
		EAST(INDEX), generator);
	if (WEST(INDEX) != prev_pos)
		track->valids[WEST] = check_valid_path(track,
		WEST(INDEX), generator);
}