#include "monty.h"

/**
 * _add - function add last top two in the stack
 * @stack: stack pointer
 * @line_number: line number in opcode occurance
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int sum, temp;

	if (ptr == NULL || ptr->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit_monty(stack);
	}
	temp = ptr->n;
	sum = ptr->next->n + temp;
	ptr = ptr->next;
	ptr->n = sum;
	_pop(stack, line_number);
}

/**
 * _nop - does nothing
 * @stack: stack pointer
 * @line_number: line of opcode occurance
 */

void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _sub - subtract from the two top of the stack
 * @stack: stack pointer
 * @line_number: opcode occuring line
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int sum, temp;

	if (ptr == NULL || ptr->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit_monty(stack);
	}
	temp = ptr->n;
	sum = ptr->next->n - temp;
	ptr = ptr->next;
	ptr->n = sum;
	_pop(stack, line_number);
}


/**
 * _div - division
 * @stack: stack pointer
 * @line_number: line of opcode occurance
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int sum, temp;

	if (ptr == NULL || ptr->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit_monty(stack);
	}
	if (ptr->n == 0 || ptr->next->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit_monty(stack);
	}
	temp = ptr->n;
	sum = ptr->next->n / temp;
	ptr = ptr->next;
	ptr->n = sum;
	_pop(stack, line_number);
}

/**
 * _mul - multiply from top of stack
 * @stack: stack pointer
 * @line_number: line of oopcode position
 */

void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int sum, temp;

	if (ptr == NULL || ptr->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit_monty(stack);
	}

	temp = ptr->n;
	sum = ptr->next->n * temp;
	ptr = ptr->next;
	ptr->n = sum;
	_pop(stack, line_number);
}
