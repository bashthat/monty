#include "monty.h"
/**
 * find_opc - finds the op code
 * @stack: head of stack
 * @string: opcode string passed
 * @line_number: line number
 * Return: the op func
 */
void find_opc(stack_t **stack, char *string, unsigned int line_number)
{
int x = 0;
instruction_t fopc[] = OPCODES;

if (string == NULL)
return;
for (x = 0; fopc[x].opcode; x++)
{
if (strcmp(fopc[x].opcode, string) == 0)
{
fopc[x].f(stack, line_number);
return;
}
}
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, string);
same = "error";
}
