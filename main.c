#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/* Definition stack */
__attribute__((unused)) stack_type * stack = NULL;

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
	FILE *bytecodes;
	char line[1024];
	char **tokens;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	bytecodes = fopen(argv[1], "r");
	if (bytecodes == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (fgets(line, 1024, bytecodes))
	{
		tokens = tokenizer(line);
		execute(tokens);
	}

	return (EXIT_SUCCESS);
}

