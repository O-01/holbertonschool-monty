#include "monty.h"

global_t share;

/**
 * main - entrance to monty interpreter program
 * @argc - argument count
 * @argv - vector of arguments supplied upon launch
 * Return: 0 upon success
 */

int main(int argc, char **argv)
{
	stack_t *head = NULL;

	iniT(argc, argv[1]);

	conveY(&head);

	exit(EXIT_SUCCESS);

	return (0);
}
