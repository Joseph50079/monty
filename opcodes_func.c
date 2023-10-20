#include "monty.h"

/**
 * _push - opcode function puts data to stack
 * @stack: stack pointer
 * @line_number: line of the opcode position
 */

void _push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int n;

	arg = strtok(NULL, "\n\t()[]{}<> ");
	n = 0;
	if (isnumber(arg) == 1 && arg != NULL)
	{
		n = atoi(arg);
		add_dnodeint(stack, n);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit_monty(stack);
	}
}


/**
 * _pall - function print all stack element
 * @stack: stack pointer
 * @line_number: line of opecode position
 */

void _pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *ptr = *stack;

	while (ptr != NULL)
	{
		fprintf(stdout, "%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 * _pint - print the top most of stack
 * @stack: stack pointer
 * @line_number: line of opcode position
 *
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	if (ptr == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit_monty(stack);
	}
	fprintf(stdout, "%d\n", ptr->n);
}
/**
 * _pop - pop's ooout the first element in stack
 * @stack: stack pointer
 * @line_number: line of opcode occurance
 *
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	if (ptr == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit_monty(stack);
	}

	delete_dnodeint_at_index(stack, 0);
}

/**
 * _swap - swap's the first two element of the stack
 * @stack: pointer of stack
 * @line_number:line of opcode occurance
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *ptr = *stack;

	if (ptr == NULL || ptr->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit_monty(stack);
	}
	temp = ptr->n;
	ptr->n = ptr->next->n;
	ptr->next->n = temp;
}
