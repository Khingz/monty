#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *new_node;
	int x;

	if (!tokens[1])
	{
		fprintf("Not a valid integer\n");
		return;
	}

	new = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf("fail to malloc\n");
		return;
	}

	for (x = 0; tokens[1][x]; x++)
	{
		if (tokens[1][x] == '-' && x == 0)
			continue;
		if (tokens[1][x] < '0' || tokens[1][x] > '9')
		{
			sfprintf("No int passed");
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

void pall(stack_t **stack, unsigned int line_number)
{
	(void)stack;
        (void)line_number;
	printf("from pall\n");
}
