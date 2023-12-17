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

    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n",
                line_number);
        exit_error();
    }

    n = (*stack)->n;

    (*stack)->n = (*stack)->next->n;

    (*stack)->next->n = n;
}
