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

	if (ac != 2)
	{
		print("USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	read_file(argv[1], stack);
	free_dlistint(stack);
}
