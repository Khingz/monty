#include "monty.h"

char **tokens = NULL;

/**
 * main - Entry Point: Interprete monty script
 * @argc: argument count
 * @argv: pointer to an array of arguments passed
 * Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on error
 */
int main(int argc, char **argv)
{
	FILE *fd;
	int exit_value;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	exit_value = (execute(fd));
	fclose(fd);
	return (exit_value);
}
