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

bool check_double_valid_path(track_t *track, int next_pos, int double_next_pos,
				generator_t *generator)
{
	if (check_outside_pos(double_next_pos, generator) == true
	|| MAP[next_pos] == '\n'
	|| is_a_hole(MAP[double_next_pos]))
		return (false);
	track->pathes[track->nb_path] = double_next_pos;
	track->nb_path++;
	return (true);
}