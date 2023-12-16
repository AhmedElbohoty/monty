#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

/**
 * execute - Execute the command
 * @tokens: The command
 *
 * Return: Nothing
 */
int execute(char **tokens)
{
	int num1;

		if (!tokens[0])
		return (EXIT_FAILURE);

	if (strcmp(tokens[0], "push") == 0)
	{
		if (!tokens[1])
		{
			printf("L<line_number>: usage: push integer\n");
			return (EXIT_FAILURE);
		}

		/* TODO: check if second arg is number */
		num1 = atoi(tokens[1]);

		/* TODO: check if node is NULL */
		push(&stack, num1);

		return (EXIT_SUCCESS);
	}

	if (strcmp(tokens[0], "pall") == 0)
	{
		pall();
	}

	if (strcmp(tokens[0], "nop") == 0)
		return (EXIT_FAILURE);

	return (EXIT_SUCCESS);
}
