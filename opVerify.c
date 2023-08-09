#include "monty.h"

/**
 * opVerify - manages commands & calls correlating function upon matching input
 * @stack:
 * @cmd: command to be verified against list of valid instructions
 * @line_n:
 */

void opVerify(stack_t **stack, char *cmd, size_t line_n)
{
	instr_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	int i = 0;

	if (cmd)
		for (i = 0; ops[i].opcode; i++)
			if (!strcmp(ops[i].opcode, cmd))
			{
				ops[i].f(stack, line_n);
				return;
			}

	fprintf(stderr, "L%lu: unknown instruction %s\n", line_n, cmd);
/*	freeStack();*/
	exit(EXIT_FAILURE);
}
