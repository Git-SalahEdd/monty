#include "monty.h"

/**
 *sub - subtracts the top element
 *of the stack from the second top element of the stack.
 *@line_number: line number for opcode
 */

void sub(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack)
    {
        err("L%d : empty stack", line_number);
    }
    else if (!(*stack)->next)
    {
        err("L%d: can't sub, stack too short", line_number);
    }
    else
    {
        int result = (*stack)->n - (*stack)->next->n;
        pop(stack, line_number);
        (*stack)->n = result;
    }
}
