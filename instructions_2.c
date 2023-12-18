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

/**
 * sub - subtracts the top element of the stack from the second
 *       top element of the stack.
 * @stack: The pointer to the stack.
 * @line_number: The line number.
 *
 * Return: Nothing
 */
void sub(stack_type **stack, unsigned int line_number)
{
	stack_type *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit_error();
	}

	while (temp->next != NULL)
		temp = temp->next;

	temp->prev->n = temp->prev->n - temp->n;
	temp->prev->next = NULL;
	free(temp);
}

/**
 * division -  divides the second top element of the stack by
 *        the top element of the stack.
 * @stack: The pointer to the stack.
 * @line_number: The line number.
 *
 * Return: Nothing
 */
void division(stack_type **stack, unsigned int line_number)
{
	stack_type *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit_error();
	}

	while (temp->next != NULL)
		temp = temp->next;

	if (temp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit_error();
	}

	temp->prev->n = temp->prev->n / temp->n;
	temp->prev->next = NULL;
	free(temp);
}

/**
 * mul - multiplies the second top element of the
 *       stack with the top element of the stack.
 * @stack: The pointer to the stack.
 * @line_number: The line number.
 *
 * Return: Nothing
 */
void mul(stack_type **stack, unsigned int line_number)
{
	stack_type *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit_error();
	}

	while (temp->next != NULL)
		temp = temp->next;

	temp->prev->n = temp->prev->n * temp->n;
	temp->prev->next = NULL;
	free(temp);
}
