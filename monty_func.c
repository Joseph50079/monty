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
 */

void read_file(char *filename, stack_t **stack)
{
	ssize_t fd;
	int close;
	size_t n = 0;
	char *buf = NULL;
	instruct_f op_code;
	char *line_buf;
	unsigned int line_number = 1;
	FILE *file = fopen(filename, "r");

	if (!file)
	{
		printf("Error: Can't open file %s\n", filename);
		exit_monty(stack);
	}

	while ((fd = getline(&buf, &n, file)) != -1)
	{
		line_buf = parse_line(buf);
		if (line_buf == NULL || line_buf[0] == '#')
		{
			line_number++;
			continue;
		}
		op_code = get_opcode(line_buf);
		if (op_code == NULL)
		{
			printf("L%d: Can't open file %s\n", line_number, line_buf);
			exit_monty(stack);
		}
		op_code(stack, line_number);
		line_number++;
	}

	free(buf);
	close = fclose(file);
	if (close == -1)
		exit(-1);

}


/**
 * get_opcode - get opcode and return the suitable function
 * @line: line of monty opcode
 * Return: return's the right opcode
 */

instruct_f get_opcode(char *line)
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
		{"div", _div}
	};

	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, line) != 0)
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
