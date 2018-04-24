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
#define MAZE_POS maze.map[LIST_X][LIST_Y]
#define ABS(X) X < 0 ? -X : X

typedef struct pos_s {
	int x;
	int y;
} pos_t;

typedef struct tile_s {
	bool close;
	bool open;
	bool blocked;
	int g_cost;
	int h_cost;
	int f_cost;
	pos_t parent;
} tile_t;

typedef struct maze_s {
	tile_t **map;
	int width;
	int height;
} maze_t;

typedef struct list_s {
	pos_t pos;
	struct list_s *next;
} list_t;

char **parse_file(char *filepath);
void start(char **map);
maze_t map_to_maze(char **map);
void add_node(list_t **list, pos_t pos);
void remove_node(list_t **list, pos_t pos_to_remove);
void a_star_loop(maze_t maze, list_t *open_list);
list_t *find_smallest_open(list_t *open_list, maze_t maze);
int compute_h_cost(maze_t *maze, pos_t pos);
void set_maze_path(char **map, maze_t maze);

#endif /* __DANTE__ */