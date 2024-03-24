#include <stdlib.h>
#include <stdio.h>
#include "monty.h"
#include <ctype.h>

/**
 * push - Adds a new node at the end of a stack_type list.
 * @stack: The pointer to the stack.
 * @line_number: The line number.
 *
 * Return: Nothing
 */
void push(stack_type **stack, unsigned int line_number)
{
	stack_type *new_node;
	int value;

	if (state.tokens[1] == NULL || !isdigit(*state.tokens[1]))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit_error();
	}

	value = atoi(state.tokens[1]);
	new_node = malloc(sizeof(stack_type));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit_error();
	}

	new_node->n = value;
	new_node->prev = NULL;

	add_dnodeint_end(stack, value);
}

/**
 * pall - Prints all the elements of a stack_type list.
 * @stack: The pointer to the stack.
 * @line_number: The line number.
 *
 * Return: Nothing
 */
void pall(stack_type **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_type *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit_error();
	}

	while (temp->next != NULL)
		temp = temp->next;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
}

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: The pointer to the stack.
 * @line_number: The line number.
 *
 * Return: Nothing
 */
void pint(stack_type **stack, unsigned int line_number)
{
	stack_type *temp = *stack;

	if (temp == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit_error();
	}

	while (temp->next != NULL)
		temp = temp->next;

	printf("%d\n", temp->n);
}

/**
 * pop - removes the top element of the stack.
 * @stack: The pointer to the stack.
 * @line_number: The line number.
 *
 * Return: Nothing
 */
void pop(stack_type **stack, unsigned int line_number)
{
	stack_type *temp, *prev;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit_error();
	}

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	prev = temp->prev;
	if (prev == NULL)
	{
		*stack = NULL;
		free(temp);
	}
	else
	{
		prev->next = NULL;
		free(temp);
	}
}

/**
 * nop - Do nothing
 * @stack: The pointer to the stack.
 * @line_number: The line number.
 *
 * Return: Nothing
 */
void nop(__attribute__((unused)) stack_type **stack,
		 __attribute__((unused)) unsigned int line_number)
{
}
