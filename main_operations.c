#include "monty.h"

/**
 * push_opcode - Opcode `push` pushes an element to stack in a Monty script
 * @stack: double pointer to the stack structure stack_t
 *         It represents the address of the top element of the stack
 * @line_number: line number in the Monty script
 */
void push_opcode(stack_t **stack, unsigned int line_number)
{
	int i;
	int number;
	char *opcode = execution_env.tokenized_str[0];
	char *argument = execution_env.tokenized_str[1];

	if (!execution_env.tokenized_str[1])
		push_non_integer(line_number, opcode);

	for (i = 0; argument[i]; i++)
	{
		if (!isdigit(argument[i]) && argument[0] != '-')
			push_non_integer(line_number, opcode);
	}

	number = atoi(argument);

	if (execution_env.mode == STACK_MODE)
		add_node_at_first(stack, number);
	else if (execution_env.mode == QUEUE_MODE)
		add_node_at_end(stack, number);
}

/**
 * pall_opcode - Opcode `pall` prints all the value of the
 *               stack in a Monty script
 * @stack: head of double pointer to the stack structure stack_t
 *         It represents the address of the top element of the stack
 * @line_number: line number in the Monty script
 */
void pall_opcode(stack_t **stack, unsigned int line_number)
{
	UNUSED(line_number);

	if (!stack || !*stack)
		return;

	print_list(*stack);
}

/**
 * pint_opcode - Opcode `pint` prints the top of stack in a Monty script
 * @stack: double pointer to the stack structure stack_t
 *         It represents the address of the top element of the stack
 * @line_number: line number in the Monty script
 */
void pint_opcode(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		empty_stack_error(line_number, execution_env.tokenized_str[0]);
		free_all_and_exit();
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop_opcode - Opcode `pop` removes the top of stack in a Monty script
 * @stack: double pointer to the stack structure stack_t
 *         It represents the address of the top element of the stack
 * @line_number: line number in the Monty script
 */
void pop_opcode(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		empty_stack_error(line_number, execution_env.tokenized_str[0]);
		free_all_and_exit();
	}

	delete_first_node(stack);
}

/**
 * nop_opcode - Opcode `nop` do nothing
 * @stack: double pointer to the stack structure stack_t
 *         It represents the address of the top element of the stack
 * @line_number: line number in the Monty script
 */
void nop_opcode(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
}
