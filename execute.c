#include "monty.h"

/**
 * execute - process and execute monty command
 * @fd: file descriptor
 * Return: success or error
 */
int execute(FILE *fd)
{
	char *line = NULL;
	unsigned int prev_token_len = 0, line_num = 0;
	size_t exit_code = EXIT_SUCCESS, len = 0;
	char *delims = " \n\t\a\b";
	void (*opcode_f)(stack_t **stack, unsigned int line_number);
	stack_t *stack = NULL;

	if (head_node(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (getline(&line, &len, fd) != -1)
	{
		line_num++;
		tokens = tokenize(line, delims);
		if (tokens == NULL)
		{
			if (empty_line(line, delims))
				continue;
			free_stack(&stack);
			return (malloc_error());
		}
		else if (tokens[0][0] == '#')
		{
			free_tokens();
			continue;
		}
		opcode_f = get_opcode_func(tokens[0]);
		if (opcode_f == NULL)
		{
			free_stack(&stack);
			exit_code = unknown_op_error(tokens[0], line_num);
			free_tokens();
			break;
		}
		prev_token_len = token_arr_len();
		opcode_f(&stack, line_num);
		if (token_arr_len() != prev_token_len)
		{
			if (tokens && tokens[prev_token_len])
				exit_code = atoi(tokens[prev_token_len]);
			else
				exit_code = EXIT_FAILURE;
			free_tokens();
			break;
		}
		free_tokens();
	}
	free_stack(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (malloc_error());
	}

	free(line);
	return (exit_code);
}
