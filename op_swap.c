#include "monty.h"

/**
 * op_swap - Swaps two top stack elements
 * @stack: the head of the stack
 * @line_number: Line number
 * Return: void
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	int number;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	number = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = number;
}
