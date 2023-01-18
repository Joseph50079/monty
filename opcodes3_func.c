#include "monty.h"

/**
 * _mod - computes modules between the first and second value in stack
 * @stack: stack pointer
 * @line_number: position wweeree opcode occurs
 */

 void _mod(stack_t **stack, unsigned int line_number)
 {
    stack_t *ptr = *stack;

    if (ptr == NULL || ptr->next == NULL)
    {
        fprintf(stderr,"L%d: can't mod, stack too short\n", line_number);
        exit_monty(stack);
    }
    if (ptr->n == 0)
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