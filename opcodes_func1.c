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
		token_error(no_int_error(line_number));
		return;
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		token_error(malloc_error());
		return;
	}

	for (x = 0; tokens[1][x]; x++)
	{
		if (tokens[1][x] == '-' && x == 0)
			continue;
		if (tokens[1][x] < '0' || tokens[1][x] > '9')
		{
			token_error(no_int_error(line_number));
			return;
		}
	}
	new_node->n = atoi(tokens[1]);

	if (check_mode(*stack) == STACK) /* is stack */
	{
		temp = (*stack)->next;
		new_node->prev = *stack;
		new_node->next = temp;
		if (temp)
			temp->prev = new_node;
		(*stack)->next = new_node;
	}
	else /*Is queue */
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		new_node->prev = temp;
		new_node->next = NULL;
		temp->next = new_node;
	}
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
		token_error(pint_error(line_number));
		return;
	}
	printf("%d\n", (*stack)->next->n);
}

/**
 * pop - removes the top element of the stack.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		token_error(pop_error(line_number));
		return;
	}
	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * swap - swaps top two elements of the stack
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		token_error(short_stack_error(line_number, tokens[0]));
		return;
	}
	temp = (*stack)->next->next;
	(*stack)->next->next = temp->next;
	(*stack)->next->prev = temp;
	if (temp->next)
		temp->next->prev = (*stack)->next;
	temp->next = (*stack)->next;
	temp->prev = *stack;
	(*stack)->next = temp;
}
