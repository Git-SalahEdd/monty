#include "monty.h"

/**
 * mul - multiplies the second top element
 * of the stack with the top element of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number for opcode
 */

void mul(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		err("L%d : empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	else if (!(*stack)->next)
	{
		err("L%d: can't mul, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		int result = (*stack)->prev->n * (*stack)->n;

		pop(stack, line_number);
		(*stack)->n = result;
	}
}
