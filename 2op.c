#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: the current line number, from main
 */

void add(stack_t **stack, unsigned int line_number)
{
stack_t *tp = NULL;
int a;
int b;

if (!*stack)
{
fprintf(stderr, "L%d: can't add,stack too short\n", line_number);
same = "error";
return;
}
tp = *stack;
a = tp->n;
tp = tp->prev;
if (!tp)
{
fprintf(stderr, "L%d: cant add, stack too short\n", line_number);
same = "error";
return;
}
b = tp->n;
tp->n = (a + b);
*stack = tp;
tp = tp->next;
free(tp);
}

/**
 * nop - this function doesn't do anything
 * @stack: pointer to the stack
 * @line_number: line number, from main
 */

void nop(stack_t **stack, unsigned int line_number)
{
(void) stack;
(void) line_number;
}
