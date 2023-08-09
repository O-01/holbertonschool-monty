#include "monty.h"

/**
 * pall -
 * @stack:
 * @line_n:
 */

void pall(stack_t **stack, size_t line_n)
{
	int i = 0;

	(void)line_n;

	if (!(*stack))
		return;

	for (i = 0; *stack; i++)
		printf("%d\n", (*stack)->n), (*stack) = (*stack)->next;
}
