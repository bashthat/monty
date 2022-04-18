#include "monty.h"
/**
 * push - push element to a stack
 * @stack: head of list
 * @line_number: void
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
stack_t *nnode = malloc(sizeof(stack_t));
int line = atoi(same);

if (!nnode)
{
free(nnode);
fprintf(stderr, "Error: malloc failed\n");
same = "error";
exit(EXIT_FAILURE);
}
while (*same)
{
if (*same == '-')
same++;
if (isdigit(*same) == 0)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
same = "error";
free(nnode);
exit(EXIT_FAILURE);
}
same++;
}
nnode->n = line;
nnode->next = *stack;
nnode->prev = NULL;
if (*stack)
(*stack)->prev = nnode;
*stack = nnode;
}
