/*
** EPITECH PROJECT, 2017
** generator
** File description:
** path.c
*/

#include <generator.h>

bool check_outside_pos(int pos, generator_t *generator)
{
	if (pos < 0 || pos > SIZE - 2 || MAP[pos] == '\n')
		return (true);
	return (false);
}

bool check_valid_pos(int pos, generator_t *generator)
{
	if (check_outside_pos(pos, generator) == false)
		if (is_a_hole(MAP[pos]))
			return (false);
	return (true);
}

bool check_valid_path(track_t *track, int next_pos, generator_t *generator)
{
	if (check_outside_pos(next_pos, generator) == true)
		return (false);
	if (is_a_hole(MAP[next_pos]))
		return (false);
	if (NORTH(next_pos) != track->pos
	&& check_valid_pos(NORTH(next_pos), generator) == false)
		return (false);
	if (SOUTH(next_pos) != track->pos
	&& check_valid_pos(SOUTH(next_pos), generator) == false)
		return (false);
	if (EAST(next_pos) != track->pos
	&& check_valid_pos(EAST(next_pos), generator) == false)
		return (false);
	if (WEST(next_pos) != track->pos
	&& check_valid_pos(WEST(next_pos), generator) == false)
		return (false);
	track->nb_path++;
	return (true);
}