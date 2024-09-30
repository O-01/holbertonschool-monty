#include "monty.h"

/**
 * add - add top 2 node values in stack, second node takes sum, then pop top
 * @stack: stack, top 2 elements of which to be added
 * @line_n: line number within monty instruction file
 */
void add(stack_t **stack, size_t line_n)
{
	stack_t *oldtop_add = NULL, *newtop_sum = NULL;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%lu: can't add, stack too short\n", line_n);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	oldtop_add = *stack;
	newtop_sum = oldtop_add->next;
	newtop_sum->n += oldtop_add->n;
	pop(stack, line_n);
}
