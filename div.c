#include "monty.h"

/**
 * diV - divide top 2 node values in stack, second node takes result, pop top
 * @stack: stack, top 2 elements of which to be divided
 * @line_n: line number within monty instruction file
 */

void diV(stack_t **stack, size_t line_n)
{
	stack_t *oldtopDIV = NULL, *newtopRES = NULL;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%lu: can't add, stack too short\n", line_n);
		freeStack(stack);
		exit(EXIT_FAILURE);
	}

	oldtopDIV = *stack;
	newtopRES = oldtopDIV->next;
	newtopRES->n /= oldtopDIV->n;

	pop(stack, line_n);
}
