#include "monty.h"

/**
 * free_linked_list - frees a doubly linked list.
 * @head: dlinked list head
*/
void free_linked_list(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * free_tokenized_string - free an array of character pointers to tokenized str
 * @tokenized_str: an array of character pointers to tokenized string
*/
void free_tokenized_string(char **tokenized_str)
{
	int idx;

	for (idx = 0; tokenized_str[idx]; idx++)
		free(tokenized_str[idx]);

	free(tokenized_str);
}

/**
 * free_all_and_exit - frees all the allocated memories
 *                     and exit the program with EXIT_FAILURE status
 */
void free_all_and_exit(void)
{
	if (execution_env.stack)
		free_linked_list(execution_env.stack);

	if (execution_env.tokenized_str)
		free_tokenized_string(execution_env.tokenized_str);

	if (execution_env.line_buffer)
		free(execution_env.line_buffer);

	if (execution_env.file_pointer)
		fclose(execution_env.file_pointer);

	exit(EXIT_FAILURE);
}
