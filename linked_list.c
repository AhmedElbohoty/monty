#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
 * push - Adds a new node at the end of a stack_type list.
 * @head: The pointer to the list.
 * @n: The data for new node.
 *
 * Return: - The address of the new element (Success)
 *         - NULL (Failure)
 */
stack_type *push(stack_type **head, int n)
{
	stack_type *node, *temp;

	/* Create the new node */
	node = malloc(sizeof(stack_type));
	if (node == NULL)
		return (NULL);

	node->prev = NULL;
	node->n = n;
	node->next = NULL;

	if (*head == NULL)
	{
		*head = node;
		return (*head);
	}

	/* Add the new node at the end */
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = node;
	node->prev = temp;

	return (*head);
}

/**
 * pall - Prints all the elements of a stack_type list.
 *
 * Return: the number of nodes
 */
size_t pall(void)
{
	size_t count = 1;
	stack_type *temp = stack;

	if (temp == NULL)
		return (0);

	while (temp->next != NULL)
	{
		temp = temp->next;
		count++;
	}

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}

	return (count);
}

