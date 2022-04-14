#include "monty.h"

/**
 * free_list - free's a stack
 * @head: pointer to head
 */
void free_list(stack_t **head)
{
	stack_t *rn;
	stack_t *tx;

	if (*head)
	{
		rn = *head;
		*head = NULL;

		while (rn->next)
		{
			tx = rn;
			rn = rn->next;
			free(tx);
		}
		free(rn);
	}
}
