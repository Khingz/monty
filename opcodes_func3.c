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
