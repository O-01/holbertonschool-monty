#include "monty.h"

FILE *open_file(int argc, char *inFile);
ssize_t convey(stack_t **stack);
void op_verify(stack_t **stack, char *cmd, size_t line_n);
void free_stack(stack_t **stack);

global_t share;

/**
 * main - entrance to monty interpreter program
 * @argc: argument count
 * @argv: vector of arguments supplied upon launch
 * Return: 0 upon success
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;

	open_file(argc, argv[1]);
	convey(&stack);
	free_stack(&stack);
	exit(EXIT_SUCCESS);
	return (0);
}

/**
 * open_file - opens file, if it exists
 * @argc: argument count to main upon launch
 * @inFile: argv[1], or file to be opened for interpretation
 * Return: file pointer to newly opened file stream
 */
FILE *open_file(int argc, char *inFile)
{
	FILE *stream;

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	stream = fopen(inFile, "r");
	if (!stream)
	{
		fprintf(stderr, "Error: Can't open file %s\n", inFile);
		exit(EXIT_FAILURE);
	}
	share.file = stream;
	return (stream);
}

/**
 * convey - conveys instruction line (if applicable) to op verifier
 * @stack: empty stack upon which operations are expected to be performed
 * Return: total number of characters retrieved, used mainly for debug
 */
ssize_t convey(stack_t **stack)
{
	char *input = NULL, *cmd = NULL;
	ssize_t line = 0, total = 0;
	size_t in_len = 0, line_n = 1;

	for (; (line = getline(&input, &in_len, share.file)) != -1;
		line_n++, total += line)
	{
		cmd = strtok(input, SPC_DELIM);
		share.line = cmd;
		if (cmd)
			op_verify(stack, cmd, line_n);
	}
	return (total);
}

/**
 * op_verify - manages commands & calls correlating function upon matched input
 * @stack: stack upon which operations are expected to be performed
 * @cmd: command to be verified against list of valid instructions
 * @line_n: line number within monty instruction file
 */
void op_verify(stack_t **stack, char *cmd, size_t line_n)
{
	instr_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", diV},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	int i = 0, sz = 0;

	if (cmd)
		for (sz = (sizeof(ops) / sizeof(instr_t)); i < (sz - 1); ++i)
			if (!strcmp(ops[i].opcode, cmd))
			{
				ops[i].f(stack, line_n);
				return;
			}
	if (cmd[0] != '#')
	{
		fprintf(stderr, "L%lu: unknown instruction %s\n", line_n, cmd);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * free_stack - frees memory allocated for stack
 * @stack: stack to be freed
 */
void free_stack(stack_t **stack)
{
	stack_t *top = NULL, *pos = NULL;

	if (share.line)
		free(share.line);
	if (share.file)
		fclose(share.file);
	for (top = *stack; top;)
		pos = top, top = top->next, free(pos);
	*stack = NULL;
}
