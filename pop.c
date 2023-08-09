#include "monty.h"

/**
 * pop - remove
 * @stack -
 * @line_n -
 */

void pop(stack_t **stack, size_t line_n)
{
	stack_t *del;

	if (!(*stack))
	{
		fprintf(stderr, "L%lu: can't pop an empty stack\n", line_n);
/*		freeStack();*/
		exit(EXIT_FAILURE);
	}

	del = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	free(del);
}
