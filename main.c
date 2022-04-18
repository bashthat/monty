#include "monty.h"
/**
 * main - cli for monty
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: always 0
 */
int main(int argc, char **argv)
{
	FILE *file;
	size_t buffsize = 0;
	ssize_t ui = 0;
	char *buffer = malloc(buffsize * sizeof(char));
	char *s = NULL;
	stack_t *st = NULL;
	int x = 1, xit = EXIT_SUCCESS;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	ui = getline(&buffer, &buffsize, file);
	while (ui >= 0)
	{
		s = strtok(buffer, " \t\n\r");
		same = strtok(NULL, " \t\n\r");
		if (same == NULL)
			same = "notanum";
		find_opc(&st, s, x);
		if (strcmp(same, "error") == 0)
		{
			xit = EXIT_FAILURE;
			break;
		}
		ui = getline(&buffer, &buffsize, file);
		x++;
	}
	free(buffer);
	free_list(&st);
	fclose(file);
	exit(xit);
}
