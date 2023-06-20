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
