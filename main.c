#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

#define MAX_LINE_LENGTH 1024

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
	char line[MAX_LINE_LENGTH];
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

	while (fgets(line, MAX_LINE_LENGTH, bytecodes))
	{
		tokens = tokenizer(line);
		execute(tokens);
	}

	return (EXIT_SUCCESS);
}

