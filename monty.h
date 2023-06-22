#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define UNUSED(x) (void)(x)
#define SPACE " "
#define MAX_TOKENIZED_SIZE 3
#define COMMENT '#'
#define EXECUTION_ENV_INITIALIZER { NULL, NULL, NULL, NULL, 0 }
#define STACK "stack"
#define QUEUE "queue"

/**
 * enum Mode - defines the mode of operation for linked list
 *
 * @STACK_MODE: the linked list operates as a stack
 * @QUEUE_MODE: the linked list operates as a queue
 */
enum Mode
{
	STACK_MODE = 0,
	QUEUE_MODE = 1
};

/**
 * struct stack_s - doubly linked list re-presentation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack or (queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct execution_env - struct to use a group of variables globally
 * @stack: doubly linked list re-presentation of a stack (or queue)
 * @tokenized_str: array of character pointers to the tokenized strings
 * @line_buffer: pointer to buffer that stores opcode
 * @file_pointer: file pointer
 * @mode: stack or queue
*/
typedef struct execution_env
{
	stack_t *stack;
	char **tokenized_str, *line_buffer;
	FILE *file_pointer;
	int mode;
} execution_env_t;

extern execution_env_t execution_env;

/** get_inputs.c functions **/
FILE *open_file(char *file_name);
ssize_t read_line(size_t *buffer_size);
char **tokenize_string(const char *delim);

/** execute_instructions.c functions **/
void (*get_operation(char *opcode))(stack_t **stack, unsigned int line_number);
int execute_operations(char *file_name);
int check_mode_comment(char **tokenized_str);

/** update_mode.c function **/
void update_mode(char *opcode);

/** essential_errors.c functions **/
void usage_error(void);
void open_error(char *file_name);
void malloc_error(void);

/** opcode_errors1.c functions **/
void invalid_instruction_error(unsigned int line_number);
void two_elements_error(unsigned int line_number);

/** opcode_errors2.c functions **/
void empty_stack_error(unsigned int line_number, char *opcode);
void division_by_zero(unsigned int line_number);
void ascii_out_of_range(unsigned int line_number, char *opcode);
void push_non_integer(unsigned int line_number, char *opcode);

/** linked-list.c functions **/
void print_list(const stack_t *head);
size_t get_list_length(const stack_t *head);
stack_t *add_node_at_first(stack_t **head, int n);
stack_t *get_last_node(stack_t **head);
stack_t *add_node_at_end(stack_t **head, int n);
stack_t *delete_first_node(stack_t **head);

/** main_operations.c functions **/
void push_opcode(stack_t **stack, unsigned int line_number);
void pall_opcode(stack_t **stack, unsigned int line_number);
void pint_opcode(stack_t **stack, unsigned int line_number);
void pop_opcode(stack_t **stack, unsigned int line_number);
void nop_opcode(stack_t **stack, unsigned int line_number);

/** arithmetic_operations.c functions **/
void add_opcode(stack_t **stack, unsigned int line_number);
void sub_opcode(stack_t **stack, unsigned int line_number);
void div_opcode(stack_t **stack, unsigned int line_number);
void mul_opcode(stack_t **stack, unsigned int line_number);
void mod_opcode(stack_t **stack, unsigned int line_number);

/** logical_operators.c functions **/
void swap_opcode(stack_t **stack, unsigned int line_number);
void rotl_opcode(stack_t **stack, unsigned int line_number);
void rotr_opcode(stack_t **stack, unsigned int line_number);

/** ascii_operations.c functions **/
void pchar_opcode(stack_t **stack, unsigned int line_number);
void pstr_opcode(stack_t **stack, unsigned int line_number);

/** free.c functions **/
void free_linked_list(stack_t *head);
void free_tokenized_string(char **tokenized_str);
void free_all_and_exit(void);

#endif
