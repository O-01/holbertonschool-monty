#include "monty.h"

/**
 * push - push element to stack
 * @stack:
 * @line_n:
 */

void push(stack_t **stack, size_t line_n)
{
	int i = 0, invalid = 0;
	char *value = NULL;
	stack_t *top = NULL;

	value = strtok(NULL, SPC_DELIM);
	for (i = 0, invalid = 0; value[i]; i++)
		if (value[i] < '0' || value[i] > '9')
			invalid = 1;
	if (!value || invalid)
	{
		fprintf(stderr, "L%lu: usage: push integer\n", line_n);
/*		freeStack();*/
		exit(EXIT_FAILURE);
	}
	top = malloc(sizeof(stack_t));
	if (!top)
	{
		fprintf(stderr, "Error: malloc failed\n");
/*		freeStack();*/
		exit(EXIT_FAILURE);
	}

	top->n = atoi(value);
	top->prev = NULL;
	top->next = *stack;

	if (*stack)
		(*stack)->prev = top;

	*stack = top;
}
