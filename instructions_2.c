#include <stdlib.h>
#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @stack: The pointer to the stack.
 * @line_number: The line number.
 *
 * Return: Nothing
 */
void swap(stack_type **stack, unsigned int line_number)
{
	int n;
	stack_type *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit_error();
	}

	while (temp->next != NULL)
		temp = temp->next;

	n = temp->n;
	temp->n = temp->prev->n;
	temp->prev->n = n;
}

/**
 * add - adds the top two elements of the stack.
 * @stack: The pointer to the stack.
 * @line_number: The line number.
 *
 * Return: Nothing
 */
void add(stack_type **stack, unsigned int line_number)
{
	stack_type *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit_error();
	}

	while (temp->next != NULL)
		temp = temp->next;

	temp->prev->n = temp->n + temp->prev->n;
	temp->prev->next = NULL;
	free(temp);
}
