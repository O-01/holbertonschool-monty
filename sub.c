#include "monty.h"

/**
 * sub - subtract top 2 node values in stack, second node takes result, pop top
 * @stack: stack, top 2 elements of which to be subtracted
 * @line_n: line number within monty instruction file
 */
void sub(stack_t **stack, size_t line_n)
{
	stack_t *oldtop_sub = NULL, *newtop_res = NULL;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%lu: can't sub, stack too short\n", line_n);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	oldtop_sub = *stack;
	newtop_res = oldtop_sub->next;
	newtop_res->n -= oldtop_sub->n;
	pop(stack, line_n);
}
