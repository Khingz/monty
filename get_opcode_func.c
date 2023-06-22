#include "monty.h"

/**
 * get_opcode_func - gets appropraite opcode function
 * @cmd: specifier type
 * Return: Null or pointer address to func
 */
void (*get_opcode_func(const char *cmd))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{NULL, NULL}
	};
	
	while (opcodes[i].opcode)
	{
		if (strcmp(cmd, opcodes[i].opcode) == 0)
			return (opcodes[i].f);
		i++;
	}
	return (NULL);
}
