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

	init_app();
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit_error();
	}

	state.bytecodes = fopen(argv[1], "r");
	if (state.bytecodes == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit_error();
	}

	while (fgets(line, 1024, state.bytecodes))
	{
		if (line[0] == '#')
			continue;
		state.tokens = tokenizer(line);
		if (!state.tokens[0])
			continue;

		handle_instruction();
		free(state.tokens);
		state.tokens = NULL;
		state.line_number++;
	}
	end_app();
	return (EXIT_SUCCESS);
}

/**
 * handle_instruction - Selection function for instruction
 *
 * Return: - Nothing
 */
void handle_instruction(void)
{
	int i = 0;

	for (i = 0; i < 12; i++)
	{
		if (state.instructions[i].opcode == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", state.line_number,
					state.tokens[0]);
			exit_error();
		}
		else if (strcmp(state.instructions[i].opcode, state.tokens[0]) == 0)
		{
			state.instructions[i].f(&state.stack, state.line_number);
			break;
		}
	}
}
