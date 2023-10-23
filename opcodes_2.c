#include "monty.h"

/**
 * pchar - print the ascii value of a number
 * @head: pointer to stack
 * @line_num: line number
 */

void pchar(stack_t **head, unsigned int line_num)
{
	stack_t *top;

	if (!head || !(*head))
		err("L%d: can't pchar, stack empty\n", line_num);

	top = *head;
	if (top->n > 127)
		err("L%d: can't pchar, value out of range\n", line_num);
	printf("%c\n", (char)top->n);
}
