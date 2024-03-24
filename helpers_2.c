#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a stack_type list.
 * @head: The pointer to the list.
 * @n: The data for new node.
 *
 * Return: - The address of the new element (Success)
 *         - NULL (Failure)
 */
stack_type *add_dnodeint_end(stack_type **head, const int n)
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
