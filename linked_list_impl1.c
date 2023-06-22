#include "monty.h"

/**
 * get_list_length - calculate the number of nodes
 * @head: head of the list
 * Return: number of elements
 */
size_t get_list_length(const stack_t *head)
{
	const stack_t *current;
	size_t nodes_number = 0;

	if (!head)
		return (0);

	current = head;

	while (current != NULL)
	{
		current = current->next;
		nodes_number++;
	}

	return (nodes_number);
}

/**
 * add_node_at_first - adds a new node at the beginning of a list
 * @head: pointer to the head of the list
 * @n: data to be inserted
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_node_at_first(stack_t **head, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;

	if (!*head)
	{
		*head = new_node;
		return (*head);
	}

	(*head)->prev = new_node;
	*head = new_node;

	return (*head);
}

/**
 * get_last_node - get the address of the last node
 * @head: pointer to the head of the list
 * Return: address of last node
 */
stack_t *get_last_node(stack_t **head)
{
	stack_t *current = *head;

	while (current->next != NULL)
		current = current->next;

	return (current);
}

/**
 * add_node_at_end - adds a new node at the end of a list
 * @head: pointer to the head of the list
 * @n: data to be inserted
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_node_at_end(stack_t **head, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *last;

	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (!head || !*head)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (*head);
	}

	last = get_last_node(head);
	new_node->prev = last;
	last->next = new_node;

	return (*head);
}
