#include "monty.h"

/**
 * pchar_opcode - prints the char at the top of the stack
 * @stack: pointer to the head of stack
 * @line_number: line number in the Monty script
 */
void pchar_opcode(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		empty_stack_error(line_number, execution_env.tokenized_str[0]);
	}

	if (!isascii((*stack)->n))
	{
		ascii_out_of_range(line_number, execution_env.tokenized_str[0]);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * pstr_opcode - prints the string starting at the top of the stack
 * @stack: pointer to the head of stack
 * @line_number: line number in the Monty script
 */
void pstr_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	UNUSED(line_number);

	while (current)
	{
		if (current->n == 0 || !isascii(current->n))
			break;
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
