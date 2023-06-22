#include "monty.h"

/**
 * get_operation - select to perform a specific operation
 * @opcode: the opcode operation to be performed
 * Return: pointer to function to perform the opcode
 *				 or NULL if the opcode is invalid
*/
void (*get_operation(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int idx;
	instruction_t instructions_arr[] = {
		{"push", push_opcode},
		{"pall", pall_opcode},
		{"pint", pint_opcode},
		{"pop", pop_opcode},
		{"swap", swap_opcode},
		{"add", add_opcode},
		{"nop", nop_opcode},
		{"sub", sub_opcode},
		{"div", div_opcode},
		{"mul", mul_opcode},
		{"mod", mod_opcode},
		{"pchar", pchar_opcode},
		{"pstr", pstr_opcode},
		{"rotl", rotl_opcode},
		{"rotr", rotr_opcode},
		{NULL, NULL}
	};

	for (idx = 0; instructions_arr[idx].opcode; idx++)
		if (!strcmp(instructions_arr[idx].opcode, opcode))
			return (instructions_arr[idx].f);

	return (NULL);
}

/**
 * execute_operations - execute the operation of the corresponding opcode
 * @file_name: the file name the contains the opcode
 * Return: EXIT_SUCCESS
*/
int execute_operations(char *file_name)
{
	ssize_t chars_number;
	size_t buffer_size = 0;
	unsigned int line_number = 0;
	char **tokenized_str;
	void (*opcode_func)(stack_t **stack, unsigned int line_number);

	execution_env.file_pointer = open_file(file_name);

	while ((chars_number = read_line(&buffer_size)) != -1)
	{
		line_number++;
		execution_env.line_buffer[chars_number - 1] = '\0';
		execution_env.tokenized_str = tokenize_string(SPACE);
		tokenized_str = execution_env.tokenized_str;

		if (check_mode_comment(tokenized_str))
			continue;

		opcode_func = get_operation(tokenized_str[0]);
		if (opcode_func == NULL)
		{
			invalid_instruction_error(line_number);
		}
		opcode_func(&execution_env.stack, line_number);

		free_tokenized_string(execution_env.tokenized_str);
	}

	free(execution_env.line_buffer);
	free_linked_list(execution_env.stack);
	fclose(execution_env.file_pointer);

	return (EXIT_SUCCESS);
}

/**
 * check_mode_comment - checks the mode of stack
 * @tokenized_str: tokenized string
 * Return: 1 for comment or NULL or change mode, 0 if nothing
*/
int check_mode_comment(char **tokenized_str)
{
	if (tokenized_str[0] == NULL || tokenized_str[0][0] == COMMENT)
	{
		free_tokenized_string(execution_env.tokenized_str);
		return (1);
	}

	if (!strcmp(tokenized_str[0], STACK) || !strcmp(tokenized_str[0], QUEUE))
	{
		update_mode(tokenized_str[0]);
		free_tokenized_string(execution_env.tokenized_str);
		return (1);
	}

	return (0);
}
