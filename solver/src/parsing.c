/*
** EPITECH PROJECT, 2018
** dante
** File description:
** parsing
*/

#include "dante.h"

int get_first_width(char *str)
{
	int width = 0;

	for (int i = 0; str[i] && str[i] != '\n'; i++)
		width += 1;
	return (width);
}

int str_error_handling(maze_t *maze, char *str)
{
	int height = 1;
	int width = 0;
	int first_width = get_first_width(str);

	for (int i = 0; str[i]; i++) {
		if (str[i] != '*' && str[i] != 'X' && str[i] != '\n')
			return (1);
		if (str[i] == '\n' && width != first_width)
			return (1);
		else if (str[i] == '\n') {
			height += 1;
			width = 0;
		} else
			width += 1;
	}
	if (width != first_width)
		return (1);
	maze->height = height;
	maze->width = first_width;
	return (0);
}

char *get_maze(maze_t *maze, char *filepath, int fd)
{
	struct stat buf;
	char *str = NULL;

	lstat(filepath, &buf);
	str = malloc(sizeof(char) * buf.st_size + 1);
	read(fd, str, buf.st_size);
	str[buf.st_size] = 0;
	if (str_error_handling(maze, str)) {
		printf("error handling\n");
		return (NULL);
	}
	return (str);
}

char *parse_file(maze_t *maze, char *filepath)
{
	int fd = open(filepath, O_RDONLY);

	if (fd == -1)
		return (NULL);
	return (get_maze(maze, filepath, fd));
}