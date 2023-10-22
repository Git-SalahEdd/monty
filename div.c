#include "monty.h"

/**
 *_div - divides the second top element of the stack
 *by the top element of the stack.
 *@stack: pointer poiting to pointer pointing to the stack
 *@line_number: line number for opcode
 */

void _div(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		err("L%d : empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	else if (!(*stack)->next)
	{
		err("L%d: can't div, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		int result = (*stack)->prev->n / (*stack)->n;

		pop(stack, line_number);
		(*stack)->n = result;
	}
}
