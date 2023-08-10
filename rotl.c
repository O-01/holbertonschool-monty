#include "monty.h"

/**
 *
 *
 *
 */

void rotl(stack_t **stack, size_t line_n)
{
	stack_t *oldtop = NULL/*, *newtop = NULL*/;

	(void)line_n;
	if (!*stack)
		return;

	oldtop = *stack;
/*	newtop = oldtop->next;*/

	for (; oldtop; oldtop = oldtop->next)
		;
	/* ... WIP ... */
}
