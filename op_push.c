#include "monty.h"
/**
 * op_push - push element to a stack
 * @stack: head of list
 * @line_number: void
 * Return: void
 */

void op_push(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *nnode;
	int x;
	const char *same;


	x = atoi(same);
	nnode = malloc(sizeof(stack_t));

	if (nnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	nnode->n = same;
	nnode->prev = NULL;
	if (*stack == NULL)
	{
		nnode->next = NULL;
		*stack = nnode;
	}
	else
	{
		nnode->next = *stack;
		(*stack)->prev = nnode;
		*stack = nnode;
	}
}
