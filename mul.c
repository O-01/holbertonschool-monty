#include "monty.h"

/**
 * mul - multiply top 2 node values in stack, second node takes result, pop top
 * @stack: stack, top 2 elements of which to be multiplied
 * @line_n: line number within monty instruction file
 */
void mul(stack_t **stack, size_t line_n)
{
	stack_t *oldtop_mul = NULL, *newtop_res = NULL;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%lu: can't mul, stack too short\n", line_n);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	oldtop_mul = *stack;
	newtop_res = oldtop_mul->next;
	newtop_res->n *= oldtop_mul->n;
	pop(stack, line_n);
}
