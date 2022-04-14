#include "monty.h"

/**
 * parse - parses user input to tokens
 * @line: input to parse and tokenize
 * @ip: arguments
 * Return: 0 skip, 1 continue
 */
int parse(char *line, relish *ip)
{
	char delims[] = " \t\r\n";
	char *p;
	char *arg;
	int size;
	unsigned int ln = ip->line_number;

	if (line == NULL)
		return (0);

	p = strtok(line, delims);

	if (p == NULL || p[0] == '#')
		return (0);

	if (strcmp(p, "stack") == 0)
	{
		*ip->mode = 0;
		return (0);
	}

	if (strcmp(ip, "queue") == 0)
	{
		*ip->mode = 1;
		return (0);
	}

	if (strcmp(ip, "push") == 0)
	{
		arg = strtok(NULL, delims);
		if (arg == NULL)
		{
			printf("L%d: usage: push integer\n", ln);
			exit(EXIT_FAILURE);
		}
		siz = strlen(arg);
		while (siz--)
		{
			if (siz == 0 && arg[siz] == '-')
				break;
			if (arg[siz] > 57 || arg[siz] < 48)
			{
				printf("L%d: usage: push integer\n", ln);
				exit(EXIT_FAILURE);
			}
		}
		ip->arg = atoi(arg);
		ip->p = p;
		return (1);
	}
	ip->p = p;

	return (1);
}
