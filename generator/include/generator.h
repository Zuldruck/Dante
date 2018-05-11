/*
** EPITECH PROJECT, 2017
** generator.h
** File description:
** all prototypes of generator
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <wait.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <errno.h>
#include <stddef.h>

#define NORTH(x) (x - LEN_X - 1)
#define SOUTH(x) (x + LEN_X + 1)
#define EAST(x) (x + 1)
#define WEST(x) (x - 1)

#define DNORTH(x) (x - 2 * LEN_X - 2)
#define DSOUTH(x) (x + 2 * LEN_X + 2)
#define DEAST(x) (x + 2)
#define DWEST(x) (x - 2)

#define LEN_X generator->len.x
#define LEN_Y generator->len.y
#define SIZE generator->size
#define MAP generator->map
#define TRACKER generator->tracker
#define INDEX generator->index

#define is_a_hole(x) (x == '*')
#define END (SIZE - 2)
#define END_NOT_DUG (MAP[END] == 'X')

typedef enum
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3,
} direction_t;

typedef struct vector_s
{
	int x;
	int y;
} vector_t;

typedef struct track_s track_t;

typedef struct track_s
{
	int pos;
	int nb_path;
	int pathes[4];
	track_t *prev;
} track_t;

typedef struct generator_s
{
	vector_t len;
	int size;
	int index;
	bool perfect;
	char *map;
	track_t *tracker;
} generator_t;

///////////////////////////////////////// FUNC

generator_t init_generator(void);
int set_generator(generator_t *generator, char **str);
void start_generator(generator_t *generator);
void destroy_generator(generator_t *generator);
void set_track(track_t *track, generator_t *generator);
bool check_valid_path(track_t *track, int next_pos, generator_t *generator);
void get_next_pos(track_t **track, generator_t *generator);
void backtrack(track_t **track, generator_t *generator);
void keep_end_track(track_t **track, generator_t *generator);
bool check_outside_pos(int pos, generator_t *generator);
void start_backtrack(generator_t *generator);
void set_double_track(track_t *track, generator_t *generator);
void double_backtrack(track_t **track, generator_t *generator);
bool check_double_valid_path(track_t *track, int next_pos, int double_next_pos,
				generator_t *generator);
void set_track_values(track_t *track, generator_t *generator);

#endif /* GENERATOR_H_ */