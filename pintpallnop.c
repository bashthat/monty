#include "monty.h"

/**
 * pall - prints from doubly linked list
 *
 * @ip: data for command
 */

void pall(relish *ip)
{
	stack_t *h = *ip->head;

	if (h == NULL)
		return;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * pint - prints val at the top of the stack\n
 *
 * @ip: access to command struct
 */

void pint(relish *ip)
{
	stack_t *h = *ip->head;

	if (h == NULL)
	{
		printf("L%d: can't pint, stack empty\n", ip->line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", h->n);
}

/**
 * add - adds the top two elements
 *
 * @ip: access to specific data from command struct
 */

void add(relish *ip)
{
	stack_t **h = ip->head;
	stack_t *node_1 = NULL;
	stack_t *node_2 = NULL;
	int sum = 0;

	if (ip == NULL || h == NULL || *h == NULL || (*h)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", ip->line_number);
		exit(EXIT_FAILURE);
	}

	node_1 = *h;
	node_2 = (*h)->next;

	sum = node_1->n + node_2->n;
	node_2->n = sum;

	pop(ip);
}


/**
 * nop - nope.. nothing.. nop. 
 *
 * @ip: command struct
 */

void nop(relish *ip)
{
	(void)ip;
}
