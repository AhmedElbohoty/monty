#include <stdlib.h>
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

	state.line_number = 0;
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

	if (state.tokens)
		free(state.tokens);

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
 * create_instructions - Create instructions
 *
 * Return: pointers to instructions
 */
instruction_t *create_instructions(void)
{
	instruction_t *ptr = malloc(sizeof(instruction_t) * 3);

	if (!ptr)
		fprintf(stderr, "Error: malloc failed\n");

	ptr[0].opcode = "push", ptr[0].f = push;
	ptr[1].opcode = "pall", ptr[1].f = pall;
	ptr[2].opcode = NULL, ptr[2].f = NULL;

	return (ptr);
}

/**
 * _calloc - Allocates memory for an array, using malloc
 * @nmemb: number of elements
 * @size: size bytes
 *
 * Return: - If nmemb or size is 0 OR malloc fails, return NULL.
 *         - Else, pointer to the allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *p;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);

	for (i = 0; i < (size * nmemb); i++)
		p[i] = 0;

	return (p);
}
