#include "monty.h"

/**
 * mod - modulo top 2 node values in stack, second node takes result, pop top
 * @stack: stack, division of top 2 elements of which to find the remainder
 * @line_n: line number within monty instruction file
 */
void mod(stack_t **stack, size_t line_n)
{
	stack_t *oldtop_mod = NULL, *newtop_res = NULL;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%lu: can't mod, stack too short\n", line_n);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%lu: division by zero\n", line_n);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	oldtop_mod = *stack;
	newtop_res = oldtop_mod->next;
	newtop_res->n %= oldtop_mod->n;
	pop(stack, line_n);
}
