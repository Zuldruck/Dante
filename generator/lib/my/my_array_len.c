/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** (enter)
*/

int my_array_len(char **array)
{
	int i = 0;

	for (; array[i]; i++);
	return (i);
}
