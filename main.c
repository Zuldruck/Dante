/*
** EPITECH PROJECT, 2017
** workshwoup
** File description:
** main.c
*/

#include "my.h"

void maze_init(char *maze, size_t col, size_t row)
{
	for (int i = 0; i != (col + 1) * row; i++) {
		maze[i] = 'X';
		if ((i + 1) % (col + 1) == 0) {
			maze[i] = '\n';
		}
	}
}

void maze_display(char *maze)
{
	my_printf("maze : \n\n%s\n", maze);
}
/* 
int check_inside_maze(int direction, int col, int row)
{
	if (direction < 0 || direction > (col + 1) * row - 2)
		return (1);
	return (0);
}

int check_valid_path(char *maze, int direction, size_t col, size_t row)
{
	int ret = 0;

	if (check_inside_maze(direction, col, row) != 0)
		return (1);
	if (maze[direction] != 'X')
		return (1);
	if (check_inside_maze(direction - col - 1, col, row) == 0)
		if (maze[direction - col - 1] == '*')
			ret++;
	if (check_inside_maze(direction + col + 1, col, row) == 0)
		if (maze[direction + col + 1] == '*')
			ret++;
	if (check_inside_maze(direction - 1, col, row) == 0)
		if (maze[direction - 1] == '*')
			ret++;
	if (check_inside_maze(direction + 1, col, row) == 0)
		if (maze[direction + 1] == '*')
			ret++;
	if (ret != 1)
		return (1);
	return (0);
}

int get_previous_pos(char *maze, int pos, int col, int row)
{
	int direction = rand() % 4;
	int next = 0;

	switch (direction) {
		case NORTH:
		my_printf("NORTH\n");
		next = pos - col - 1;
		break;
		case SOUTH:
		my_printf("SOUTH\n");
		next = pos + col + 1;
		break;
		case EAST:
		my_printf("EAST\n");
		next = pos + 1;
		break;
		case WEST:
		my_printf("WEST\n");
		next = pos - 1;
		break;
	}
	if (check_inside_maze(next, col, row) == 0)
		if (maze[next] == '*')
			return (next);
	return (0);
}

void reset_try(int try[4])
{
	try[0] = 0;
	try[1] = 0;
	try[2] = 0;
	try[3] = 0;
}

int check_end(char *maze, int pos, int col, int row)
{
	if (check_inside_maze(pos, col, row) == 0)
		if (maze[pos] == 'E')
			return (1);
	if (check_inside_maze(pos - col - 1, col, row) == 0)
		if (maze[pos - col - 1] == 'E')
			return (1);
	if (check_inside_maze(pos + col + 1, col, row) == 0)
		if (maze[pos + col + 1] == 'E')
			return (1);
	if (check_inside_maze(pos + 1, col, row) == 0)
		if (maze[pos + 1] == 'E')
			return (1);
	if (check_inside_maze(pos - 1, col, row) == 0)
		if (maze[pos - 1] == 'E')
			return (1); 
	return (0);
}

void maze_dig(char *maze, size_t col, size_t row)
{
	static int pos = 0;
	static int test = 0;
	static int try[4] = {0, 0, 0, 0};
	int direction = rand() % 4;
	int next = 0;

	if (check_end(maze, pos, col, row) == 1) {
		maze_display(maze);
		exit (0);
	}
	maze[pos] = '*';
	if (try[0] == 1 && try[1] == 1 && try[2] == 1 && try[3] == 1) {
		reset_try(try);
		pos = get_previous_pos(maze, pos, col, row);
	}
	maze_display(maze);
	switch (direction) {
		case NORTH:
		next = pos - col - 1;
		try[0] = 1;
		break;
		case SOUTH:
		next = pos + col + 1;
		try[1] = 1;
		break;
		case EAST:
		next = pos + 1;
		try[2] = 1;
		break;
		case WEST:
		next = pos - 1;
		try[3] = 1;
		break;
	}
	if (check_valid_path(maze, next, col, row) == 1) {
		my_printf("dig\n");
		maze_dig(maze, col, row);
	} else {
		reset_try(try);
		maze[next] = '*';
		pos = next;
		maze_dig(maze, col, row);
	}
} */

#define NORTH(x) (x - col - 1)
#define SOUTH(x) (x + col + 1)
#define EAST(x) (x + 1)
#define WEST(x) (x - 1)

typedef enum
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3,
} direction_t;

char get_path(char *maze, int next_pos, size_t col, size_t row)
{
	if (next_pos < 0 || next_pos > (col + 1) * row - 2)
		return (0);
	return (maze[next_pos]);
}

int check_valid_path(char path)
{
	if (path != 'X')
		return (1);
	return (0);
}

int get_next_pos(int pos, size_t col, size_t path)
{
	switch (path) {
		case NORTH:
		return (NORTH(pos));
		break;
		case SOUTH:
		return (SOUTH(pos));
		break;
		case EAST:
		return (EAST(pos));
		break;
		case WEST:
		return (WEST(pos));
		break;
	}
	return (0);
}

int check_valid_pos(char *maze, int next_pos, size_t col, size_t row)
{
	char north = get_path(maze, NORTH(next_pos), col, row);
	char south = get_path(maze, SOUTH(next_pos), col, row);
	char east = get_path(maze, EAST(next_pos), col, row);
	char west = get_path(maze, WEST(next_pos), col, row);
	int blocked_pathes = 0;
	char pos = get_path(maze, next_pos, col, row);

	if (pos != 'X')
		return (1);
	if (north == 0 || north == '\n')
		blocked_pathes++;
	if (south == 0 ||south == '\n')
		blocked_pathes++;
	if (east == 0 || east == '\n')
		blocked_pathes++;
	if (west == 0 || west == '\n')
		blocked_pathes++;
	if (blocked_pathes == 3)
		return (1);
	blocked_pathes = 0;
	if (north != 'X' && north != 0 && north != '\n')
		blocked_pathes++;
	if (south != 'X' && south != 0 && south != '\n')
		blocked_pathes++;
	if (east != 'X' && east != 0 && east != '\n')
		blocked_pathes++;
	if (west != 'X' && west != 0 && west != '\n')
		blocked_pathes++;
	if (blocked_pathes > 1)
		return (1);
	return (0);
}

int check_blocked(char *maze, int pos, size_t col, size_t row)
{
	if (check_valid_pos(maze, NORTH(pos), col, row) != 0 && check_valid_pos(maze, SOUTH(pos), col, row) != 0
	&& check_valid_pos(maze, EAST(pos), col, row) != 0 && check_valid_pos(maze, WEST(pos), col, row) != 0)
		return (0);
	return (1);
}

int check_already_blocked(int *prev_pos_tab, int prev_index, int pos)
{
	for (int i = 0; i != prev_index; i++) {
		if (prev_pos_tab[i] == pos)
			return (1);
	}
	return (0);
}

int go_back(int pos, char *maze, size_t col, size_t row)
{
	static int prev_pos_tab[99999999];
	static int prev_index = 0;
	int back_pos_tab[4] = {NORTH(pos), SOUTH(pos), EAST(pos), WEST(pos)};
	char back_path_tab[4] = {get_path(maze, back_pos_tab[0], col, row),
	get_path(maze, back_pos_tab[1], col, row),
	get_path(maze, back_pos_tab[2], col, row),
	get_path(maze, back_pos_tab[3], col, row)};
	int index = rand() % 4;

	while (42) {
		if (back_path_tab[index] == '*' && check_already_blocked(prev_pos_tab, prev_index, back_pos_tab[index]) == 0)
			break;
		index = rand() % 4;
	}
	prev_pos_tab[prev_index] = pos;
	prev_index++;
	return (back_pos_tab[index]);
}

int check_end(int pos, size_t col, size_t row)
{
	int goal = (col + 1) * row - 2;

	if (pos == goal || NORTH(pos) == goal || SOUTH(pos) == goal || EAST(pos) == goal || WEST(pos) == goal)
		return (0);
	return (1);
}

void maze_dig(char *maze, size_t col, size_t row)
{
	static unsigned int pos = 0;
	int path = rand() % 4;
	char next_path = 0;
	int next_pos = 0;

	maze[pos] = '*';
	//maze_display(maze);
	if (check_end(pos, col, row) == 0) {
		maze[(col + 1) * row - 2] = 'E';
		maze_display(maze);
		exit (0);
	}
	if (check_blocked(maze, pos, col, row) == 0) {
		pos = go_back(pos, maze, col, row);
		maze_dig(maze, col, row);
	} else {
		next_pos = get_next_pos(pos, col, path);
		next_path = get_path(maze, next_pos, col, row);
		if (check_valid_pos(maze, next_pos, col, row) != 0) {
			maze_dig(maze, col, row);
		} else {
			pos = next_pos;
			maze_dig(maze, col, row);
		}
	}
}

int main(int ac, char **av)
{
	if (ac != 3)
		return (84);
	int col = atoi(av[1]);
	int row = atoi(av[2]);
	char *maze = malloc(sizeof(char) * ((col + 1) * row + 1));

	srand(time(NULL));
	if (!maze)
		return (84);
	maze[(col + 1) * row] = 0;
	maze_init(maze, col, row);
	maze_dig(maze, col, row);
	maze_display(maze);
	return (0);
}