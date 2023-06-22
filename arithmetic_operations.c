#include "monty.h"

/**
 * add_opcode - adds the top two elements of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number in the Monty script
 */
void add_opcode(stack_t **stack, unsigned int line_number)
{
	int value;

	if (get_list_length(*stack) < 2)
	{
		two_elements_error(line_number);
	}

	value = (*stack)->n;
	delete_first_node(stack);
	(*stack)->n += value;
}

/**
 * sub_opcode - subtracts the top element of the stack from the second top
 * @stack: pointer to the head of the stack
 * @line_number: line number in the Monty script
 */
void sub_opcode(stack_t **stack, unsigned int line_number)
{
	int value;

	if (get_list_length(*stack) < 2)
	{
		two_elements_error(line_number);
	}

	value = (*stack)->n;

	delete_first_node(stack);
	(*stack)->n -= value;
}

/**
 * div_opcode - divides the second top element of the stack by the top element
 * @stack: pointer to the head of the stack
 * @line_number: line number in the Monty script
 */
void div_opcode(stack_t **stack, unsigned int line_number)
{
	int value;

	if (get_list_length(*stack) < 2)
	{
		two_elements_error(line_number);
	}
	if ((*stack)->n == 0)
	{
		division_by_zero(line_number);
	}

	value = (*stack)->n;
	delete_first_node(stack);
	(*stack)->n /= value;
}

/**
 * mul_opcode - multiplies the second top element of the stack with the top
 * @stack: pointer to the head of the stack
 * @line_number: line number in the Monty script
 */
void mul_opcode(stack_t **stack, unsigned int line_number)
{
	int value;

	if (get_list_length(*stack) < 2)
	{
		two_elements_error(line_number);
	}

	value = (*stack)->n;
	delete_first_node(stack);
	(*stack)->n *= value;
}

/**
 * mod_opcode - computes the rest of the division of the second top element
 * @stack: pointer to the head of the stack
 * @line_number: line number in the Monty script
 */
void mod_opcode(stack_t **stack, unsigned int line_number)
{
	int value;

	if (get_list_length(*stack) < 2)
	{
		two_elements_error(line_number);
	}

	if ((*stack)->n == 0)
	{
		division_by_zero(line_number);
	}

	value = (*stack)->n;
	delete_first_node(stack);
	(*stack)->n %= value;
}
