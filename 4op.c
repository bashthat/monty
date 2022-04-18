#include "monty.h"
/**
 * pall - print value of stack
 * @stack: head of stack
 * @line_number: line number
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
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

/**
 * pint - prints value at top of stack
 * @stack: head node of stack
 * @line_number: line number
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = *stack;

if (tmp != NULL)
printf("%d\n", tmp->n);
else
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
}

/**
 * pop - removes the top element of the stack
 * @stack: head of stack
 * @line_number: line number
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
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

/**
 * swap - Swaps two top stack elements
 * @stack: the head of the stack
 * @line_number: Line number
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
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
