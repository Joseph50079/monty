#include "monty.h"

/**
 * _push - opcode function puts data to stack
 * @stack: stack pointer
 * @line_number: line of the opcode position
 */

void _push(stack_t **stack, unsigned int line_number)
{
	char *arg;

	arg = strtok(NULL, "\n ");
	if (arg == NULL)
	{
		printf("L%d: usage: push integer", line_number);
		exit_monty(stack);
	}
	if (isnumber(arg) == 1 && arg != NULL)
	{
		stack_data = atoi(arg);
	}

	add_dnodeint(stack, line_number);
}


/**
 * _pall - function print all stack element
 * @stack: stack pointer
 * @line_number: line of opecode position
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	if (ptr == NULL)
	{
		exit_monty(stack);
	}
	while (ptr != NULL)
	{
		print("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 *
 */
void _push(stack_t **stack, unsigned int line_number);

/**
 *
 */

void _push(stack_t **stack, unsigned int line_number);

/**
 *
 */

void _push(stack_t **stack, unsigned int line_number);

/**
 *
 */

void _push(stack_t **stack, unsigned int line_number);

/**
 *
 */
void _push(stack_t **stack, unsigned int line_number);

/**
 *
 */

void _push(stack_t **stack, unsigned int line_number);



