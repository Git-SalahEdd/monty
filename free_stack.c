#include "monty.h"

/**
 * free_stack - frees the stack
 * @head: head pointer
 */

void free_stack(stack_t *head)
{
	while (head)
	{
		free(head);
		head = head->next;
	}
}
