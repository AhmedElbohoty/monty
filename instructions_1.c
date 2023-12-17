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
		end_app();
		exit(EXIT_FAILURE);
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

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: The pointer to the stack.
 * @line_number: The line number.
 *
 * Return: Nothing
 */
void pint(stack_type **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		end_app();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
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
	stack_type *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		end_app();
		exit(EXIT_FAILURE);
	}

	(*stack)->n = temp->prev->n;
	(*stack)->next = NULL;
	(*stack)->prev = temp->prev->prev;

	free(temp);
}
