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


/**
 * check_mode - Checks if a stack_t linked list is in stack or queue mode.
 * @stack: A pointer to the top
 * Return: 1 or 0 if queue or stack respectively
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
