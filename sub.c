#include "monty.h"

/**
 *sub - subtracts the top element
 *of the stack from the second top element of the stack.
 *@stack: Pointer to a pointer pointing to top node of the stack.
 *@line_number: line number for opcode
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (!stack || !(*stack) || !(*stack)->next)
		err("L%d: can't sub, stack too short\n", line_number);

	top = *stack;
	top->next->n -= top->n;
	pop(stack, line_number);
}
