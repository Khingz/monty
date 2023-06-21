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
	int token_count = 0;
	size_t len = 0;
	char *delims = " \n\t\a\b";
	void (*opcode_f)(stack_t **stack, unsigned int line_number);
	stack_t *stack = NULL;

	if (head_node(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (getline(&line, &len, fd) != -1)
	{
		line_num++;
		tokens = tokenize(line, delims, &token_count);
		if (tokens == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_stack(&stack);
			return (EXIT_FAILURE);
		}
		opcode_f = get_opcode_func(tokens[0]);
		if (opcode_f == NULL)
		{
			if (empty_line(line, delims))
                                continue;
			free_stack(&stack);
			free_tokens(tokens, token_count);
			fprintf(stderr, "L%u: unknown instruction %s\n", line_num, tokens[0]);
			break;
		}
		opcode_f(&stack, line_num);
		free_tokens(tokens, token_count);
	}
	free_stack(&stack);
	if (line && *line == 0)
	{
		free(line);
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
