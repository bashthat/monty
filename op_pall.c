#include "monty.h"
/**
 * op_pall - print value of stack
 * @stack: head of stack
 * @line_number: line number
 * Return: void
 */

void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int inc = 0;

	(void)line_number;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
		inc++;
	}
}
