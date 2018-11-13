#include "fuji.h"

/**
* add_node_end - adds a node at the end
* @head: a pointer to a pointer to a struct
* @str: holds the data for the new node
* Return: head
*/

lp_t *add_node_end(lp_t **head, char *str)
{
	lp_t *nxt_ptr;
	lp_t *new_node;

	new_node = malloc(sizeof(lp_t));
	if (!new_node)
		return (NULL);

	new_node->dir = str;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	nxt_ptr = *head;

	while (nxt_ptr->next != NULL)
		nxt_ptr = nxt_ptr->next;
	nxt_ptr->next = new_node;

	return (new_node);
}
