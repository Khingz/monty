#include "monty.h"

/**
 * head_node - Create head node
 * @stack: address of node
 * Return: EXIT_ERROR or EXIT_SUCCESS
 */
int head_node(stack_t **stack)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Can't malloc\n");
		return (EXIT_FAILURE);
	}

	node->n = 0;
	node->prev = NULL;
	node->next = NULL;

	*stack = node;

	return (EXIT_SUCCESS);
}

/**
 * free_stack - Frees a stack_t stack.
 * @stack: A pointer to the head of stack
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

