#include "monty.h"

char **tokenize(char *str, char *delims, int *str_count)
{
	char* copy = strdup(str);
	char* token = strtok(copy, delims);
	int i, tokenCount = 0;
	char **tokens;

	if (str == NULL || delims == NULL || str_count == NULL)
		return NULL;	
	while (token)
	{
		tokenCount++;
		token = strtok(NULL, delims);
	}
	
	tokens = (char**)malloc(tokenCount * sizeof(char*));
	if (tokens == NULL)
	{
		free(copy);
		return NULL;
	}
	token = strtok((char*)str, delims);
	for (i = 0; i < tokenCount; i++)
	{
		tokens[i] = strdup(token);
		token += strspn(token, delims);
		token = strtok(NULL, delims);
	}
	*str_count = tokenCount;
	free(copy);
	return tokens;
}
