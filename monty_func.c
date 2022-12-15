#include "monty.h"

/**
 * exit_monty - exit failure and free stack
 * @stack: stack pointer
 */

void exit_monty(stack_t **stack)
{
	if (stack == NULL)
		return;
	free_dlistint(stack);
	exit(EXIT_FAILURE);
}
/**
 * read_file - function reads files and the stack
 * @filename: path of file
 * @stack: read from the top of the stack
 */

void read_file(char *filename, stack_t *stack)
{
	ssize_t fd;
	size_t n = 0;
	FILE *file = fopen(filename, "r");
	char *buf = NULL;
	instruction_t op_code;
	char *line_buf;
	unsigned int line_number = 1;

	if (!file)
	{
		print("Error: Can't open file %s\n", filename);
		exit_monty(stack);
	}

	while ((fd = getline(&buf, n, file)) != 0)
	{
		line_buf = parse_line(buf);
		if (line_buf == NULL || line_buf =='#')
		{ 
			line_number++;
			continue;
		}
		op_cod = get_opcode(line_buf);
		if (op_code == NULL)
		{
			printf("L%d: Can't open file %s", line_number, line_buf);
			exit_monty(stack);
		}
		op_code(stack, line_number);
		line_number++;
	}
	free(buf);
	exit_monty(stack);

}


/**
 * get_opcode - get opcode and return the suitable function
 * @line: line of monty opcode
 * Return: return's the right opcode
 */

instruction_t get_opcode(char *line)
{
	int i = 0;

	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _stack},
		{"queues" _queues}
	};

	while (instruct[i].f != NULL && strcmp(instruct[i], line) != 0)
	{
		i++;
	}

	return (instruct[i].f);
}


/**
 * parse_line - toeknize the line
 * @str: string
 * Return: tokenized
 */

char *parse_line(char *str)
{
	char *token;

	if (str == NULL)
	{
		return (NULL);
	}
	token = strtok(str, "\n ");

	return (token);

