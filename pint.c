#include "monty.h"

/**
 * f_pint - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @n: the line number of of the opcode.
 */
void f_pint(stack_t **stack, unsigned int n)
{
	if (stack == NULL || *stack == NULL)
		fprintf(stderr, "L%d: can't pint, stack empty\n", n);
	printf("%d\n", (*stack)->n);
}

