#include "monty.h"
/**
 * opcode_lookup - opcode
 * @line: the line of code
 * @stack: pointer to stack
 * @line_number: line number
 * Return: zero
 */
void opcode_lookup(char *line, int **stack, unsigned int line_number)
{
	int i = 0;
	char *opcode[] = {"push", "pall", "pint", "pop", "swap", "add", "nop"};
	void (*f[11])(int **stack, unsigned int line_number) = {
		push,
		pall,
	};
	

	for (i = 0; i < '\0'; i++)
	{
	if (strncmp(line, opcode[i], strlen(opcode[i])) == 0)
		{
		f[i](stack, line_number);
		break;
		}
	}
	if (i == 11)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);
		exit(EXIT_FAILURE);
	}
}

