#include "monty.h"

/**
 *
 *
 *
 */

ssize_t conveY(stack_t **head)
{
	char *inPut = NULL, *cmd = NULL;
	ssize_t gotLine = 0, gotTotal = 0;
	size_t inLen = 0, line_n = 1;

	for (; (gotLine = getline(&inPut, &inLen, share.inFile)); line_n++)
	{
		cmd = strtok(inPut, SPC_DELIM);
		share.inLine = cmd;
		if (cmd)
			opVerify(head, cmd, line_n);
		gotTotal += gotLine;
	}
	return (gotTotal);
}
