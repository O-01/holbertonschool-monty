#include "monty.h"

/**
 * pchar - prints char at top of stack, if valid
 * @stack: stack, value of top of which to be printed
 * @ln_n: line number within monty instruction file
 */

void pchar(stack_t **stack, size_t ln_n)
{
	stack_t *top = NULL;

	if (!*stack)
	{
		fprintf(stderr, "L%lu: can't pchar, stack empty", ln_n);
		freeStack(stack);
		exit(EXIT_FAILURE);
	}

	top = *stack;

	if (top->n < 32 || top->n > 126)
	{
		fprintf(stderr, "L%lu: can't pchar, value out of range", ln_n);
		freeStack(stack);
		exit(EXIT_FAILURE);
	}

	putchar(top->n);
	putchar('\n');
}
