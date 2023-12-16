#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

/**
 * execute - Execute the command
 * @tokens: The command
 * @line_num: the number line
 *
 * Return: Nothing
 */
void execute(char **tokens, int line_num)
{
	int num1;

	if (!tokens[0])
		return;

	if (strcmp(tokens[0], "push") == 0)
	{
		if (!tokens[1] || atoi(tokens[1]) == 0)
		{
			printf("L%d: usage: push integer\n", line_num);
			return;
		}

		/* TODO: check if second arg is number */
		num1 = atoi(tokens[1]);

		/* TODO: check if node is NULL */
		push(&stack, num1);
	}

	if (strcmp(tokens[0], "pall") == 0)
	{
		pall();
	}
}
