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
		(*track)->pathes[SOUTH] = false;
		(*track)->nb_path--;
		TRACKER[SOUTH(INDEX)].prev = *track;
		*track = &TRACKER[SOUTH(INDEX)];
		INDEX = SOUTH(INDEX);
		set_track(*track, generator);
	} else if (INDEX == WEST(END)) {
		(*track)->pathes[EAST] = false;
		(*track)->nb_path--;
		TRACKER[EAST(INDEX)].prev = *track;
		*track = &TRACKER[EAST(INDEX)];
		INDEX = EAST(INDEX);
		set_track(*track, generator);
	}
}

void reset_track(track_t *track, generator_t *generator)
{
	track->pos = INDEX;
	track->nb_path = 0;
	if (track->pathes[NORTH] == true)
		track->pathes[NORTH] = check_valid_path(track,
		NORTH(INDEX), generator);
	if (track->pathes[SOUTH] == true)
		track->pathes[SOUTH] = check_valid_path(track,
		SOUTH(INDEX), generator);
	if (track->pathes[EAST] == true)
		track->pathes[EAST] = check_valid_path(track,
		EAST(INDEX), generator);
	if (track->pathes[WEST] == true)
		track->pathes[WEST] = check_valid_path(track,
		WEST(INDEX), generator);
	MAP[track->pos] = '*';
}

void backtrack(track_t **track, generator_t *generator)
{
	(*track) = (*track)->prev;
	INDEX = (*track)->pos;
	reset_track(*track, generator);
}

/// ! opti : Never look at where we come from ! ///

void set_track_values(track_t *track, generator_t *generator)
{
	track->pos = INDEX;
	track->nb_path = 0;
	track->pathes[0] = false;
	track->pathes[1] = false;
	track->pathes[2] = false;
	track->pathes[3] = false;
	MAP[track->pos] = '*';
}

void set_track(track_t *track, generator_t *generator)
{
	int prev_pos = 0;

	if (INDEX != 0)
		prev_pos = track->prev->pos;
	set_track_values(track, generator);
	if (NORTH(INDEX) != prev_pos)
		track->pathes[NORTH] = check_valid_path(track,
		NORTH(INDEX), generator);
	if (SOUTH(INDEX) != prev_pos)
		track->pathes[SOUTH] = check_valid_path(track,
		SOUTH(INDEX), generator);
	if (EAST(INDEX) != prev_pos)
		track->pathes[EAST] = check_valid_path(track,
		EAST(INDEX), generator);
	if (WEST(INDEX) != prev_pos)
		track->pathes[WEST] = check_valid_path(track,
		WEST(INDEX), generator);
}