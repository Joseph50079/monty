#include "monty.h"

/**
 * main - execute function from argv
 * @argv: argument vector
 * @ac: argument count
 * Return: 0
 */

int main(int ac, char **argv)
{
	stack_t *stack;

	stack = NULL;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(argv[1], &stack);
	if (stack != NULL)
		free_dlistint(stack);
	return (0);
}
