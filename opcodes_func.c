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
		printf("L%d: usage: push integer\n", line_number);
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

void _pall(stack_t **stack, unsigned int line_number__attribute__((unused)))
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
		printf("L%d: can't pint, stack empty\n", line_number);
		exit_monty(stack);
	}
	printf("%d\n", ptr->n);
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
		printf("L%d: can't pop an empty stack\n", line_number);
		exit_monty(stack);
	}

	ptr = ptr->next;
	*stack = ptr;
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
		printf("L%d: can't swap, stack too short\n", line_number);
		exit_monty(stack);
	}
	temp = ptr->n;
	ptr->n = ptr->next->n;
	ptr->next->n = temp;
}

/**
 * _add - function add last top two in the stack
 * @stack: stack pointer
 * @line_number: line number in opcode occurance
 */

void _add(stack_t **stack, unsigned int line_number)
{


/**
 *
 */
void _nop(stack_t **stack, unsigned int line_number);

/**
 *
 */

void _sub(stack_t **stack, unsigned int line_number);



