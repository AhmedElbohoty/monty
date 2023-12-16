#ifndef MONTY_HEADER
#define MONTY_HEADER

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

void *_calloc(unsigned int nmemb, unsigned int size);
char **tokenizer(char *str);
void execute(char **tokens, int line_num);

stack_type *push(stack_type **head, int n);
size_t pall(void);

/* Declare the stack */
extern stack_type *stack;

#endif /* MONTY_HEADER */
