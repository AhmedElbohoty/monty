#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/* Definition stack */
__attribute__((unused)) app_state state;

/**
 * main - Initialize the project
 * @argc: The args count
 * @argv: The args vector
 *
 * Return: - If success, returns 0
 *         - Else, returns exit code
 */
int main(int argc, char **argv)
{
	char line[64];
	int i = 0;

	init_app();

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		end_app();
		return (EXIT_FAILURE);
	}

	state.bytecodes = fopen(argv[1], "r");
	if (state.bytecodes == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		end_app();
		return (EXIT_FAILURE);
	}

	while (fgets(line, 1024, state.bytecodes))
	{
		state.tokens = tokenizer(line);
		if (!state.tokens[0])
			continue;

		for (i = 0; i < 7; i++)
		{
			if (strcmp(state.instructions[i].opcode, state.tokens[0]) == 0)
				state.instructions[i].f(&state.stack, state.line_number);
		}
		free(state.tokens);
		state.tokens = NULL;
		state.line_number++;
	}

	end_app();

	return (EXIT_SUCCESS);
}
