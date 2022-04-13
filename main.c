#include "monty.h"
/**
 * main - cli for monty
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: always 0
 */
int main(int argc, char **argv)
{
	size_t buffsize = 1024;
	char *buffer = malloc(buffsize * sizeof(char));
	FILE *file;
	ssize_t cmd;
	char *s = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	cmd = getline(&buffer, &buffsize, file);
	/*parse*/

