#include "monty.h"

/**
 * push - Adds a node to the stack.
 * @head: Pointer to the new node.
 * @n: number
 */

void push(stack_t **head, int n)
{
	stack_t *tmp;

	if (!head)
		return;

	tmp = malloc(sizeof(stack_t));
	if (!tmp)
		err("Error: malloc failed\n");

	tmp->n = n;
	tmp->prev = NULL;

	if (*head)
	{
		tmp->next = *head;
		(*head)->prev = tmp;
	}
	else
		tmp->next = NULL;
	*head = tmp;
}


/**
 * pall - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 */

void pall(stack_t *stack)
{
	if (!stack)
		return;
	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}

/**
 * pop_top - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		err("L%d: can't pop an empty stack\n", line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * pint - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		err("L%d: can't pint, stack empty\n", line_number);
	printf("%d\n", (*stack)->n);
}

/**
 * swap - swaps the top 2 elements on the stack
 * @head: head pointer
 * @line_num: line number being operated on
 */

void swap(stack_t **head, unsigned int line_num)
{
	int tmp;
	if (!head || !(*head)->next)
		err("L%d: can't swap, stack too short\n", line_num);
	tmp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = tmp;
}
