#include "monty.h"

/**
 * rotr - rotates bottom element of stack to top
 * @stack: stack, bottom element of which to be rotated to stack top
 * @line_n: line number within monty instruction file
 */
void rotr(stack_t **stack, size_t line_n)
{
	stack_t *iter = NULL, *oldtop = NULL;
	stack_t *newtop = NULL, *bottom = NULL;

	(void)line_n;
	if (!*stack || !(*stack)->next)
		return;
	oldtop = *stack;
	for (iter = oldtop; iter->next; iter = iter->next)
		;
	iter->prev->next = NULL;
	for (bottom = iter; iter != oldtop; iter = iter->prev)
		;
	oldtop->prev = bottom;
	bottom->prev = NULL;
	bottom->next = oldtop;
	newtop = bottom;
	*stack = newtop;
}
