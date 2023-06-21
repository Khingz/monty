#include "monty.h"

char *get_int(int num);

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

/**
 * token_error - Sets last element of op_toks to be an error code.
 * @err_code: Integer to store as a string in op_toks.
 */
void token_error(int err_code)
{
	int len = 0, i = 0;
	char *exit_str = NULL;
	char **new_tokens = NULL;

	len = token_arr_len();
	new_tokens = malloc(sizeof(char *) * (len + 2));
	if (!tokens)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return;
	}
	while (i < len)
	{
		new_tokens[i] = tokens[i];
		i++;
	}
	exit_str = get_int(err_code);
	if (!exit_str)
	{
		free(new_tokens);
		fprintf(stderr, "Error: malloc failed\n");
		return;
	}
	new_tokens[i++] = exit_str;
	new_tokens[i] = NULL;
	free(tokens);
	tokens = new_tokens;
}

/**
 * get_int - gets a character pointer to new string containing int
 * @num: number to convert to string
 *
 * Return: character pointer to newly created string. NULL if malloc fails.
 */
char *get_int(int num)
{
	unsigned int temp;
	int length = 0;
	long num_l = 0;
	char *ret;

	temp = abs(num);
	length = get_numbase_len(temp, 10);

	if (num < 0 || num_l < 0)
		length++; /* negative sign */
	ret = malloc(length + 1); /* create new string */
	if (!ret)
		return (NULL);

	fill_numbase_buff(temp, 10, ret, length);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}
