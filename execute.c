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
	int read, token_count = 0;
	size_t len = 0;
	char **tokens, *delims = " \n\t\a\b";
	void (*opcode_f)(stack_t **stack, unsigned int line_number);

	while (1)
	{
		line_num++;
		line = NULL;
		read = getline(&line, &len, fd);
		if (read == -1)
		{
			free(line);
			if (line || line[0] == 0)
				break;
			return (EXIT_FAILURE);
		}
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';
		tokens = tokenize(line, delims, &token_count);
		if (tokens == NULL)
		{
			fprintf(stderr, "token error %d\n", line_num);
			return (EXIT_FAILURE);
		}
		opcode_f = get_opcode_func(tokens[0]);
		if (opcode_f == NULL)
		{
			fprintf(stderr, "L<%u>: unknown instruction <%s>\n", line_num, tokens[0]);
			return (EXIT_FAILURE);
		}
		printf("%s\n", tokens[0]);
		free(line);
		free_tokens(tokens, token_count);
	}
	fclose(fd);
	return (EXIT_SUCCESS);
}
