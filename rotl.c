#include "monty.h"

/**
 *
 *
 *
 */

void rotl(stack_t **stack, size_t line_n)
{
	stack_t *oldtop = NULL, *newtop = NULL;

	if (!*stack)
		return;

	oldtop = *stack;
	newtop = oldtop->next;

	for (; oldtop; oldtop = oldtop->next)
		;

	...
}
