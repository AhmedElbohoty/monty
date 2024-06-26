#ifndef MONTY_HEADER
#define MONTY_HEADER

#include <stdio.h>
#include <stdlib.h>

/* Type defs */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_type;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_type **stack, unsigned int line_number);
} instruction_t;

/**
 * struct state - app state
 * @stack: the stack
 * @instructions: instructions
 * @bytecodes: bytecodes
 * @tokens: tokens
 * @line_number: the line number
 *
 */
typedef struct state
{
	stack_type *stack;
	instruction_t *instructions;
	char **tokens;
	FILE *bytecodes;
	unsigned int line_number;
} app_state;

/* Functions */
char **tokenizer(char *str);

void init_app(void);
void end_app(void);
void exit_error(void);
instruction_t *create_instructions(void);
void handle_instruction(void);

void push(stack_type **stack, unsigned int line_number);
void pall(stack_type **stack, unsigned int line_number);
void pint(stack_type **stack, unsigned int line_number);
void pop(stack_type **stack, unsigned int line_number);
void nop(stack_type **stack, unsigned int line_number);
void swap(stack_type **stack, unsigned int line_number);
void add(stack_type **stack, unsigned int line_number);
void sub(stack_type **stack, unsigned int line_number);
void mul(stack_type **stack, unsigned int line_number);
void division(stack_type **stack, unsigned int line_number);
void mod(stack_type **stack, unsigned int line_number);
stack_type *add_dnodeint_end(stack_type **head, const int n);

extern app_state state;

#endif /* MONTY_HEADER */
