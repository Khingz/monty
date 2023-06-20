#include "monty.h"

/**
 * free_tokens - Frees memory allocated for tokenization for each token
 * @tokens: tokens to free
 */
void free_tokens(char **tokens)
{
	int x;

	x = 0;
	while(tokens[x])
	{
		free(tokens[x]);
		x++;
	}
	free(tokens);
}
