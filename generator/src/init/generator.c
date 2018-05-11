/*
** EPITECH PROJECT, 2017
** generator
** File description:
** generator.c
*/

#include <generator.h>

int my_str_isnum(char *str)
{
	for (int i = 0; str[i]; i++)
		if (str[i] < '0' || str[i] > '9')
			return (1);
	return (0);
}

void destroy_generator(generator_t *generator)
{
	free(MAP);
	free(TRACKER);
}

int get_len(generator_t *generator, char *len_x, char *len_y)
{
	if (my_str_isnum(len_x) != 0 || my_str_isnum(len_y) != 0)
		return (84);
	LEN_X = atoi(len_x);
	LEN_Y = atoi(len_y);
	if (LEN_X <= 0 || LEN_Y <= 0 || (LEN_X == 1 && LEN_Y == 1))
		return (84);
	SIZE = (LEN_X + 1) * LEN_Y;
	return (0);
}

int set_generator(generator_t *generator, char **str)
{
	if (get_len(generator, str[1], str[2]) != 0)
		return (84);
	if (str[3]) {
		if (strcmp(str[3], "perfect") == 0)
			generator->perfect = true;
		else
			return (84);
	}
	MAP = malloc(sizeof(char) * (SIZE));
	if (!MAP)
		return (84);
	memset(MAP, 'X', SIZE - 1);
	for (int i = LEN_X; i != SIZE - 1; i += LEN_X + 1)
		MAP[i] = '\n';
	TRACKER = malloc(sizeof(track_t) * (SIZE));
	if (!TRACKER) {
		free(MAP);
		return (84);
	}
	return (0);
}

generator_t init_generator(void)
{
	return ((generator_t){(vector_t){0, 0}, 0, 0, false, NULL, NULL});
}