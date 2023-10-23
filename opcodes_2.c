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
	if (top->n < 0 || top->n > 127)
		err("L%d: can't pchar, value out of range\n", line_num);
	printf("%c\n", (char)top->n);
}

/**
 * pstr - prints string vallue of stack->n
 * @head: pointer to stack
 */

void pstr(stack_t **head)
{
	stack_t *top;

	if (!head || !(*head))
	{/* do nothing */}

	top = *head;
	while (top)
	{
		if (top->n < 1 || top->n > 127)
			break;
		printf("%c", (char)top->n);
		top = top->next;
	}
	printf("\n");
}

/**
 * rotr - moves the last node to the first
 * @head: pointer to stack
 */

void rotr(stack_t **head)
{
	stack_t *first;
	stack_t *temp;

	if (!head || !(*head) || !(*head)->next)
		return;

	temp = *head;
	while (temp->next->next)
		temp = temp->next;
	first = temp->next;
	temp->next = NULL;
	first->next = *head;
	*head = first;
}

void rotl(stack_t **head)
{
	stack_t *last;
	stack_t *temp;

	if (!head || !(*head) || !(*head)->next)
		return;

	temp = *head;
	last = temp;
	while (temp->next)
		temp = temp->next;
	temp = last;
}
