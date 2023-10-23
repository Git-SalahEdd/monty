#include "monty.h"

/**
 * mod - mods 2 topmost elements
 * @head: stack pointer
 * @line_num: line number being operated on
 */

void mod(stack_t **head, unsigned int line_num)
{
	stack_t *top;

	if (!head || !(*head) || !(*head)->next)
		err("L%d: can't mod, stack too short\n", line_num);

	top = *head;
	if (top->n == 0)
		err("L%d: division by zero\n", line_num);

	top->next->n %= top->n;
	pop(head, line_num);
}
