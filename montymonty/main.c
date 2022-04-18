#include "monty.h"


/**
 * this is a file that should read, parse and free a line of command.
 * there are general errors used as part of the printf function.
 * there will be a need to tokenize the parsed command line.
 * strlen
 * strcpy
 * fgets: fgets can read a line of code with a single pointer.
 * 1) read -getline, 2) parse, 3) function to "freeall" 
 * set the buffer to NULL buffsize = 0, automatically allocates memory specifically while using getline
 *
 */

void main(int argc, char *argv[])
{	
	size_t buffsize = 0;
	char *buffer = NULL;
	ssize_t linesize;
	FILE *fs;
	int linecount;
	char *cmd;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fs = fopen(argv[1], "r");
	if (fs == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	linesize = getline(&buffer, &buffsize, fs);
	while (linesize >= 0)
	{
		cmd = strtok(buffer, " \n\t\r\v\f");

}
