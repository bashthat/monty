#include "monty.h"

/**
 * eval - reads operation 
 * @line: input to parse
 * @h: head
 * @t: tail
 * @mode: stack or queue mode
 * @ln: line number read
 */
void eval(char *line, stack_t **h, stack_t **t, int *mode, unsigned int ln)
{
	relish cmd;

	cmd.mode = mode;
	cmd.line_number = ln;
	cmd.head = h;
	cmd.tail = t;

	if (parse(line, &cmd))
		run(&cmd);
}
