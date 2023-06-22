#include "monty.h"

/**
 * delete_first_node - delete the first node
 * @head: pointer to the head of stack
 * Return: address of new head or NULL if empty
 */
stack_t *delete_first_node(stack_t **head)
{
	stack_t *temp = *head;

	if (*head == NULL)
		return (NULL);

	*head = (*head)->next;
	if (*head != NULL)
		(*head)->prev = NULL;

	temp->next = NULL;
	free(temp);

	return (*head);
}

/**
 * print_list - prints all the elements of a list
 * @head: head of the list
 * Return: the number of nodes
 */
void print_list(const stack_t *head)
{
	const stack_t *current;

	if (!head)
		return;

	current = head;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
