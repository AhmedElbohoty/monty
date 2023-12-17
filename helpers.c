#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * init_app - Initialize the app state
 *
 * Return: Nothing
 */
void init_app(void)
{
	state.stack = NULL;

	state.instructions = create_instructions();

	state.tokens = NULL;

	state.bytecodes = NULL;

	state.line_number = 1;
}

/**
 * end_app - end the app and free memory
 *
 * Return: Nothing
 */
void end_app(void)
{
	stack_type *temp;

	if (state.bytecodes)
		fclose(state.bytecodes);

	if (state.tokens != NULL)
	{
		free(state.tokens);
		state.tokens = NULL;
	}

	if (state.instructions)
		free(state.instructions);

	if (state.stack)
	{
		while (state.stack != NULL)
		{
			temp = state.stack->next;
			free(state.stack);
			state.stack = temp;
		}
	}
}

/**
 * exit_error - exit the app with error
 *
 * Return: Nothing
 */
void exit_error(void)
{
	end_app();
	exit(EXIT_FAILURE);
}

/**
 * create_instructions - Create instructions
 *
 * Return: pointers to instructions
 */
instruction_t *create_instructions(void)
{
	instruction_t *ptr = malloc(sizeof(instruction_t) * 6);

	if (ptr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit_error();
	}

	ptr[0].opcode = "push", ptr[0].f = push;
	ptr[1].opcode = "pall", ptr[1].f = pall;
	ptr[2].opcode = "pint", ptr[2].f = pint;
	ptr[3].opcode = "pop", ptr[3].f = pop;
	ptr[4].opcode = "nop", ptr[4].f = nop;
	ptr[5].opcode = NULL, ptr[5].f = NULL;

	return (ptr);
}

/**
 * tokenizer - split string
 * @str: pointer to string
 *
 * Return: splitted strings
 */
char **tokenizer(char *str)
{
	int i = 0;
	char *temp, **res, *delim = " \r\t\n";

	temp = strtok(str, delim);

	res = malloc(64 * sizeof(char *));

	if (res == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit_error();
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
