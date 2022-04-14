#include "monty.h"

/**
 * addop - utilizes function or operation
 * @ip: data used for function of operation
 */
void opz(relish *ip)
{
	instruction_t funcs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	
	int i = 0;

	while (funcs[i].opcode)
	{
		if (strcmp(ip->ip, funcs[i].opcode) == 0)
		{
			funcs[i].f(ip);
			return;
		}
		i++;
	}

	printf("L%d: unknown instruction %s\n", ip->line_number, ip->ip);
	exit(EXIT_FAILURE);
}
