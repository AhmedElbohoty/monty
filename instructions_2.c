#include <stdlib.h>
#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @stack: Double linked list
 * @line_number: File line execution
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
