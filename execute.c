#include "monty.h"
#include <stdlib.h>

/**
 * execute - process and execute monty command
 * @fd: file descriptor
 * Return: success or error
 */
int execute(int fd)
{
	printf("Executing, %d\n", fd);
	return (EXIT_SUCCESS);
}
