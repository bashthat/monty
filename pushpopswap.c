#include "monty.h"

/**
 * push - adds a new node at the top of the stack_t list,
 * @ip: access specific data for command
 * Return: NULL || nunode
 */

void push(relish *ip)
{
	stack_t **h = ip->head;
	stack_t *new = NULL;
	stack_t *temp = NULL;

	if (h == NULL)
	{
		printf("L%d: usage: push integer\n", ip->line_number);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		exit(EXIT_FAILURE);

	if (*ip->mode == 1)
	{

		new->n = ip->arg;
		new->next = NULL;
		new->prev = NULL;

		if (*h == NULL)
		{
			*h = new;
			return;
		}

		temp = *h;

		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
		return;
	}
	if (*h == NULL)
	{
		new->n = ip->arg;
		new->next = *h;
		new->prev = NULL;
		*h = new;
		return;
	}
	(*h)->prev = new;
	new->n = ip->arg;
	new->next = *h;
	new->prev = NULL;
	*h = new;
}

/**
 * pop - remove top element of the stack
 *
 * @ip: data from command struct
 */

void pop(relish *ip)
{
	stack_t **h = ip->head;
	stack_t *current = NULL;

	if (*h == NULL || h == NULL)
	{
		printf("L%d: can't pop an empty stack\n", ip->line_number);
		exit(EXIT_FAILURE);
	}

	current = *h;
	*h = (*h)->next;
	free(current);
}

/**
 * swap - swaps the top stack
 * @ip: data from command struct
 */

void swap(relish *ip)
{
	stack_t **h = ip->head;
	stack_t *first = NULL;
	stack_t *second = NULL;
	stack_t *third = NULL;

	if (*h == NULL || h == NULL || (*h)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", ip->line_number);
		exit(EXIT_FAILURE);
	}
	first = *h;
	second = (*h)->next;
	third = second->next;

	first->next = second->next;
	second->next = first;
	if (third)
		third->prev = first;
	first->prev = second;
	second->prev = NULL;
	*h = second;
}
