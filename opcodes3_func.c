#include "monty.h"

/**
 * _mod - computes modules between the first and second value in stack
 * @stack: stack pointer
 * @line_number: position wweeree opcode occurs
 */

 void _mod(stack_t **stack, unsigned int line_number)
 {
    stack_t *ptr = *stack;
    int sum, temp;

    if (ptr == NULL || ptr->next == NULL)
    {
        fprintf(stderr,"L%d: can't mod, stack too short\n", line_number);
        exit_monty(stack);
    }
    if (ptr->n == 0 || ptr->next->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
	exit_monty(stack);
    }

    	temp = ptr->n;
	sum = ptr->next->n % temp;
	ptr = ptr->next;
	ptr->n = sum;
	_pop(stack, line_number);
}


/**
 * _pchar - char print top stack
 * @stack: list pointer
 * @line_number: line number
 *
 */

void _pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	if (!stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit_monty(stack);
	}
	if (ptr->n < 0 || ptr->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit_monty(stack);
	}
	putchar(ptr->n);
	putchar('\n');
}


/**
 * _pstr - 
 */

void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	(void)line_number;

	if (stack)
	{
		while(ptr && ptr->n >= 0 && ptr->n < 128)
		{
			putchar(ptr->n);
			ptr = ptr->next;
		}
	}
	putchar('\n');
}
