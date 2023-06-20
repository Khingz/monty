#include "monty.h"
#include <stdlib.h>

/**
 * execute - process and execute monty command
 * @fd: file descriptor
 * Return: success or error
 */
int execute(FILE *fd)
{
	char *line = NULL;
	unsigned int line_num = 0;
	int read;
	size_t len = 0;
	char **tokens, *delims = " \n\t\a\b";

	while (1)
	{
		line_num++;
		line = NULL;
		read = getline(&line, &len, fd);
		if (read == -1)
		{
			free(line);
			if (line && line[0] == 0)
				break;
			return (EXIT_FAILURE);
		}
		tokens = tokenize(line, delims);
		free(line);
	}
	return (EXIT_SUCCESS);
}
