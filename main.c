#include "monty.h"
/**
 * main - cli for monty
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: always 0
 */
int main(int argc, char **argv)
{
	size_t buffsize;
	char *buffer = malloc(buffsize * sizeof(char));
	FILE *file;
	char *s = NULL;
	int x = 1;
	stack_t *sn = NULL;

	if (!buffer)
	{
		free(buffer);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/*ui = getline(&buffer, &buffsize, file);*/
	while (getline(&buffer, &buffsize, file) != -1)
	{
		s == tokenize(buffer);
		find_opc(&sn, s, x);
		getline(&buffer, &buffsize, file);
		x++;
	}
	free(buffer);
	free_list(&sn);
	fclose(file);
	exit(EXIT_SUCCESS);
}

/**
 * tokenize - tokenize a string
 * @buffer: buffer line
 * Return: tokenized array
 */
char **tokenize(char *buffer)
{
	char **to_arr;
	char *token;
	int x;
	char delim[] = {' ', '\n'};

	to_arr = malloc(sizeof(char) * 1024);

	token = strtok(buffer, delim);
	to_arr[0] = token;
	for (x = 1; token != NULL; x++)
	{
		token = strtok(NULL, delim);
		to_arr[x] = token;
	}

	return (to_arr);
}

/**
 * find_opc - finds the op code
 * @head: head of stack
 * @string: opcode string passed
 * @line_num: line number
 * Return: the op func
 */

void find_opc(stack_t **head, char *string, unsigned int line_num)
{
	instruction_t fopc[] = {
	{"push", op_push},
	{"pall", op_pall},
	{"pint", op_pint},
	{"pop", op_pop},
	{"swap", op_swap},
	{"add", op_add},
	{"nop", op_nop},
	{NULL, NULL}
	};

	int x = 0;

	while (x < 7)

	if (string == NULL)
		return;
	for (x = 0; fopc[x].opcode; x++)
	{
		if (strcmp(fopc[x].opcode, string) == 0)
		{
			fopc[x].f(head, line_num);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, string);
}
