#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

/**
 * execute_cmd - Execute the command
 * @tokens: The command
 *
 * Return: Nothing
 */
void execute(char **tokens)
{
	int i = 0;

	while (tokens[i] != NULL)
	{
		printf("%s\n", tokens[i]);
		i++;
	}
}

