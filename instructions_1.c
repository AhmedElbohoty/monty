#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
 * push - Adds a new node at the end of a stack_type list.
 * @stack: The pointer to the stack.
 * @line_number: The line number.
 *
 * Return: Nothing
 */
void push(stack_type **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_type *node, *temp;

	/* Create the new node */
	node = malloc(sizeof(stack_type));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return;
	}

	node->prev = NULL;
	node->n = atoi(state.tokens[1]); /* TODO: check if string */
	node->next = NULL;

	if (*stack == NULL)
	{
		*stack = node;
		return;
	}

	/* Add the new node at the end */
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = node;
	node->prev = temp;
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

	if (temp == NULL)
		return;

	while (temp->next != NULL)
		temp = temp->next;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
}
