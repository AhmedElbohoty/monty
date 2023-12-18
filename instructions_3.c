#include <stdlib.h>
#include "monty.h"

/**
 * mod - computes the rest of the division of the second top
 *       element of the stack by the top element of the stack.
 * @stack: The pointer to the stack.
 * @line_number: The line number.
 *
 * Return: Nothing
 */
void mod(stack_type **stack, unsigned int line_number)
{
    stack_type *temp = *stack;

    if (temp == NULL || temp->next == NULL)
    {
        fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
        exit_error();
    }

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        exit_error();
    }

    temp->prev->n = temp->prev->n % temp->n;
    temp->prev->next = NULL;
    free(temp);
}
