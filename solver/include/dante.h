/*
** EPITECH PROJECT, 2018
** dante
** File description:
** dante
*/

#ifndef	__DANTE__
#define	__DANTE__

#include "my.h"
#include <stdbool.h>
#include <string.h>

#define LIST_X open_list->pos.x
#define LIST_Y open_list->pos.y
#define ABS(X) X < 0 ? -X : X

#define NORTH(X) (X - maze->width - 1)
#define SOUTH(X) (X + maze->width + 1)
#define EAST(X) (X + 1)
#define WEST(X) (X - 1)

typedef struct tile_s {
	bool close;
	bool open;
	bool blocked;
	int g_cost;
	int f_cost;
	int parent;
} tile_t;

typedef struct list_s {
	int pos;
	struct list_s *next;
} list_t;

typedef struct maze_s {
	int width;
	int height;
	int size;
	tile_t *map;
} maze_t;

char *parse_file(maze_t *maze, char *filepath);
void start(char *map, maze_t *maze);
tile_t *map_to_maze(char *map, int size);
void add_node(maze_t *maze, list_t **list, int pos);
void a_star_loop(maze_t *maze, list_t *open_list);
int compute_h_cost(maze_t *maze, int pos);
void set_maze_path(char *map, maze_t *maze);

#endif /* __DANTE__ */