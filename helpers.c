#include "monty.h"

/**
 * free_tokens - Frees memory allocated for tokenization for each token
 * @tokens: tokens to free
 */
void free_tokens(char **tokens, int token_count)
{
	int i;

	if (tokens == NULL)
		return;

	for (i = 0; i < token_count; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}

/**
 * is_empty_line - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delims: delimeter string
 * Return: 1 if empty else 0
 */
int empty_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}
