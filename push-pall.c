#include "monty.h"

/**
 * f_push - push a node to the stack.
 * @new_node: Pointer to the new node.
 * @n: line number of the opcode.
 */
void f_push(stack_t **new_node, unsigned int n)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * f_pall - pall a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @n: line number of the opcode.
 */
void f_pall(stack_t **stack, unsigned int n)
{
	stack_t *tmp;

	(void) n;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
