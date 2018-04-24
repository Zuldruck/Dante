/*
** EPITECH PROJECT, 2018
** dante
** File description:
** parsing
*/

#include "dante.h"

int str_error_handling(char *str)
{
	for (int i = 0; str[i]; i++) {
		if (str[i] != '*' && str[i] != 'X')
			return (1);
	}
	return (0);
}

int get_maze_size(char *filepath)
{
	char *str = NULL;
	int i = 0;
	int read = 0;
	size_t len = 0;
	FILE *file = fopen(filepath, "r");

	while ((read = getline(&str, &len, file)) != -1)
		i++;
	fclose(file);
	return (i);
}

char **get_maze(char *filepath)
{
	char *str = NULL;
	char **tab = malloc(sizeof(*tab) * (get_maze_size(filepath) + 1));
	size_t len = 0;
	int i = 0;
	int read = 0;
	FILE *file = fopen(filepath, "r");

	while ((read = getline(&str, &len, file)) != -1) {
		str[read - 1] = 0;
		if ((i > 0 && strlen(tab[i - 1]) != strlen(str))
		|| strlen(str) <= 0 || str_error_handling(str) == 1)
			return (NULL);
		tab[i++] = strdup(str);
	}
	tab[i] = NULL;
	fclose(file);
	return (tab);
}

char **parse_file(char *filepath)
{
	int fd = open(filepath, O_RDONLY);

	if (fd == -1)
		return (NULL);
	close(fd);
	return (get_maze(filepath));
}