#include "monty.h"

/**
 * main - monty interpreter
 *
 * argc: argument count
 * argv: argument variable
 *Return:
 */

char *opGlobal[] = { NULL, NULL, "stack", NULL };

int main(int argc, char *argv[])
{
	FILE *fd;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s/n", argv[1]);
		exit(EXIT_FAILURE);
	}
	find_op(fd);
	if (fclose(fd) != 0)
		exit(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * opcode_exe - executes the found opcode
 *
 * @stack: list
 * @line: line number
 * @opcode: opcode
 * @fd: file
 */

void opcode_exe(stack_t **stack, unsigned int line, char *opcode, FILE *fd)
{
	int j = 0, flag = 0;
	instruction_t opStruct[] = { { "push", OPpush }, { "pall", OPpall },
				     { "pint", OPpint }, { "pop", OPpop },
				     { "swap", OPswap }, { "add", OPadd },
				     { "nop", OPnop },	 { NULL, NULL } };

	for (j = 0; opStruct[j].opcode != NULL; j++)
	{
		if (strcmp(opStruct[j].opcode, opGlobal[0]) == 0)
			opStruct[j].f(stack, line, opcode, fd);
		flag = 1;
		break;
	}
	if (flag != 1)
	{
		dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line,
			opGlobal[0]);
		free(opcode);
		free_list(*stack);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
}

/**
 * find_op - parses file to find desired opcode
 *
 * @fd: file
 */

void find_op(FILE *fd)
{
	int line = 1;
	int blah = 0, x = 0;
	char *opcode = NULL;
	size_t length = 0;
	stack_t *stack = NULL;

	while (line)
	{
		blah = getline(&opcode, &length, fd);
		if (blah == EOF)
			break;
		if (blah > 1) /* checks if there's input */
		{
			for (x = 0; opcode[0] != '\0';
			     x++) /* handles no input */
			{
				if (opcode[x] == '\n' || blah == 1)
					break;
				if (opcode[x] == ' ' || opcode[x] == '\t')
					blah = 0;
				else
					blah = 1;
			}
			opGlobal[0] = strtok(opcode, " \n\t");
			if (strcmp(opGlobal[0], "push") == 0)
				opGlobal[1] = strtok(NULL, " \n\t");
			else
				opGlobal[1] = strtok(NULL, " \n\t");
			if (opGlobal[0][0] == '#') /* checks for comment */
				continue;
			opcode_exe(&stack, line, opcode, fd);
		}
		line++;
	}
	if (stack)
		free_list(stack);
	free(opcode);
}
