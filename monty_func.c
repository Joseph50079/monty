#include "monty.h"

/**
 * exit_monty - exit failure and free stack
 * @stack: stack pointer
 */

void exit_monty(stack_t **stack)
{
	if (*stack != NULL)
		free_dlistint(*stack);
	exit(EXIT_FAILURE);
}

/**
 * read_file - function reads files and the stack
 * @filename: path of file
 * @stack: read from the top of the stack
 * Return: 0
 */

int read_file(char *filename, stack_t **stack)
{
	ssize_t fd;
	int close;
	size_t n = 0;
	char *buf = NULL;
	instruct_f op_code;
	char *token_buf;
	unsigned int line_number = 1;
	FILE *file = fopen(filename, "r");


	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit_monty(stack);
	}

	while ((fd = getline(&buf, &n, file)) != -1)
	{
		token_buf = parse_line(buf);
		if (token_buf == NULL || token_buf[0] == '#')
		{
			line_number++;
			continue;
		}
		op_code = get_opcode(token_buf, line_number);
		if (!op_code)
		{
			fprintf(stderr, "Error: Can't open file %s\n", token_buf);
			exit_monty(stack);
		}
		op_code(stack, line_number);
		line_number++;
	}

	free(buf);
	close = fclose(file);
	if (close == -1)
		exit_monty(stack);
	return (EXIT_SUCCESS);
}


/**
 * get_opcode - get opcode and return the suitable function
 * @line: line of monty opcode
 * @line_number: line of where code occured in file
 * Return: return's the right opcode
 */

instruct_f get_opcode(char *line, unsigned int line_number)
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
		{"pchar", _pchar},
		{"pstr", _pstr},
		{NULL, NULL}
	};

	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, line) != 0)
	{
		i++;
	}
	if (instruct[i].f == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);
		exit(EXIT_FAILURE);
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
	token = strtok(str, "\n\t ");

	return (token);
}



/**
 * isnumber - checks if a string is a number
 * @str: string being passed
 *
 * Return: returns 1 if string is a number, 0 otherwise
 */
int isnumber(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
