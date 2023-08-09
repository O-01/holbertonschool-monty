#include "monty.h"

/**
 * pint -
 * @stack:
 * @line_n:
 */

void pint(stack_t **stack, size_t line_n)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%lu: can't pint, stack empty\n", line_n);
/*		freeStack();*/
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
