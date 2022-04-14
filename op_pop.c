#include "monty.h"

/**
 * op_pop - removes the top element of the stack
 * @stack: head of stack
 * @line_number: line number
 * Return: void
 */

void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = tmp->next;
	free(*stack);
	*stack = tmp;
}
