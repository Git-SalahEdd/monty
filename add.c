#include "monty.h"

/**
 * add - combines the top 2 elements and pops the topmost
 * @head: stack pointer
 * @line_num: line number being operated on
 */

void add(stack_t **head, unsigned int line_num)
{
	stack_t *top;

	if (!head || !(*head) || !(*head)->next)
		err("L%d: can't add, stack too short\n", line_num);

	top = *head;
	top->next->n += top->n;
	pop(head, line_num);
}
