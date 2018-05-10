/*
** EPITECH PROJECT, 2017
** generator
** File description:
** main.c
*/

#include <generator.h>

int main(int ac, char **av)
{
	generator_t generator = init_generator();

	if (ac != 4 && ac != 3)
		return (84);
	if (set_generator(&generator, av) != 0)
		return (84);
	srand(time(NULL));
	start_generator(&generator);
	write(1, generator.map, generator.size);
	destroy_generator(&generator);
	return (0);
}