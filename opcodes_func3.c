#include "monty.h"

/**
 * nop - does nothing
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * pchar - Prints the character in the top value( ASCII char)
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		token_error(pchar_error(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		token_error(pchar_error(line_number, "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * pstr - Prints the string contained in a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;

	while (temp && temp->n != 0 && (temp->n > 0 && temp->n <= 127))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
	(void)line_number;
}

/**
 * rotl - rotates top val of a stack_t linked list to bottom.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *butt, *top;
	(void)line_number;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	butt = (*stack)->next;
	while (butt->next != NULL)
		butt = butt->next;
	top->next->prev = *stack;
	(*stack)->next = top->next;
	butt->next = top;
	top->next = NULL;
	top->prev = butt;
}

/**
 * rotr - rotates bottom value of a stack_t linked list to the top.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *butt, *top;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;
	(void)line_number;
	top = (*stack)->next;
	butt = (*stack)->next;
	while (butt->next != NULL)
		butt = butt->next;
	butt->prev->next = NULL;
	(*stack)->next = butt;
	butt->prev = *stack;
	butt->next = top;
	top->prev = butt;
}
