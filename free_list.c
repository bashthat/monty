#include "monty.h"

/**
 * free_list - frees the memory
 * @head: head of stack
 */

void free_list(stack_t **head)
{
	stack_t *tmp = *head;

	if (head == NULL)
		return;
	while (*head != NULL)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
	free(tmp);
	*head = NULL;
}
