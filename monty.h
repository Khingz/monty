#ifndef MONTY_H_
#define MONTY_H_

/*		HEADER FILES		*/
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

/*		STRUCT DEFINITIONS	*/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*		MACROS			*/
extern char **tokens;

/*		FUNCTION PROTOTYPES	*/
int execute(FILE *fd);
char **tokenize(char *str, char *delims);
void (*get_opcode_func(const char *cmd))(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
int head_node(stack_t **stack);
void free_stack(stack_t **stack);
void token_error(int err_code);
int malloc_error(void);
int no_int_error(unsigned int line_number);
int short_stack_error(unsigned int line_number, char *op);
int pint_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);
int unknown_op_error(char *opcode, unsigned int line_number);
unsigned int token_arr_len(void);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
		       char *buff, int buff_size);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);

/*			HELPERS		*/
void free_tokens(void);
int empty_line(char *line, char *delims);

#endif
