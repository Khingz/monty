#include "monty.h"

/**
 * push - add a stack node to the begining of the stack
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: current line.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *new_node;
	int x;

	if (!tokens[1])
	{
		fprintf(stderr, "Not a valid integer\n");
		return;
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "fail to malloc on line %d\n", line_number);
		return;
	}

	for (x = 0; tokens[1][x]; x++)
	{
		if (tokens[1][x] == '-' && x == 0)
			continue;
		if (tokens[1][x] < '0' || tokens[1][x] > '9')
		{
			fprintf(stderr, "No int passed");
			return;
		}
	}
	new_node->n = atoi(tokens[1]);
	temp = (*stack)->next;
	new_node->prev = *stack;
	new_node->next = temp;
	if (temp)
		temp->prev = new_node;
	(*stack)->next = new_node;
}

/**
 * prints - prints a stack dlinked list
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: current line.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;

	if (!stack || *stack == NULL)
		return;
	(void)line_number;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	(void)line_number;
}

/**
 * pint - Prints the top most value of a stack.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: current line.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "Pints error\n");
		return;
	}
	(void)line_number;
	printf("%d\n", (*stack)->next->n);
}
