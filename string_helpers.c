#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * tokenizer - split string
 * @str: pointer to string
 *
 * Return: splitted strings
 */
char **tokenizer(char *str)
{
	int i = 0;
	char *temp, **res, *delim = " ";

	temp = strtok(str, delim);

	res = _calloc(50, sizeof(char *));

	if (!res)
	{
		free(res);
		return (NULL);
	}

	while (temp)
	{
		if (temp[0] != '\n' && temp[0] != ' ')
			res[i] = temp;

		temp = strtok(NULL, delim);
		i++;
	}

	res[i] = NULL;

	return (res);
}

