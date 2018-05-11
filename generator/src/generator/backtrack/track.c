/*
** EPITECH PROJECT, 2017
** generator
** File description:
** track.c
*/

#include <generator.h>

void set_track_values(track_t *track, generator_t *generator)
{
	track->pos = INDEX;
	track->nb_path = 0;
	track->pathes[0] = 0;
	track->pathes[1] = 0;
	track->pathes[2] = 0;
	track->pathes[3] = 0;
	MAP[track->pos] = '*';
}

void reset_double_track(track_t *track, generator_t *generator)
{
	track->pos = INDEX;
	track->nb_path = 0;
	check_double_valid_path(track, NORTH(INDEX), DNORTH(INDEX), generator);
	check_double_valid_path(track, SOUTH(INDEX), DSOUTH(INDEX), generator);
	check_double_valid_path(track, EAST(INDEX), DEAST(INDEX), generator);
	check_double_valid_path(track, WEST(INDEX), DWEST(INDEX), generator);
}

void double_backtrack(track_t **track, generator_t *generator)
{
	(*track) = (*track)->prev;
	INDEX = (*track)->pos;
	reset_double_track(*track, generator);
}
void set_double_track(track_t *track, generator_t *generator)
{
	set_track_values(track, generator);
	check_double_valid_path(track, NORTH(INDEX), DNORTH(INDEX), generator);
	check_double_valid_path(track, SOUTH(INDEX), DSOUTH(INDEX), generator);
	check_double_valid_path(track, EAST(INDEX), DEAST(INDEX), generator);
	check_double_valid_path(track, WEST(INDEX), DWEST(INDEX), generator);
}