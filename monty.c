#include "monty.h"

/**
 * main - monty interpreter
 *
 * argc: argument count
 * argv: argument variable
 *Return:
 */

char *opGlobal[] = {NULL, NULL, "stack", NULL}

int main(int argc, char *argv[])
{
	FILE *fd

		if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Error: monty file\n");
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
 * find_op - parses file to find desired opcode
 *
 * 
 */

void find_op(*fd)
{
	int line = 1;
	int blah = 0;
	char *opcode;
	size_t length;

	while (line)
	{
		blah = getline(&opcode, &length, fd);
		if (blah == EOF)
		{
			break;
		}
		if (blah > 1) /* checks if there's input */
		{
			for (x = 0; opcode[0] != '\0';
			     x++) /* handles no input */
			{
				if (opcode[x] == '\n' || blah = 1)
					break;
				if (opcode[j] == ' ' || opcode[j] == '\t')
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
		}
		line++;
	}
	if (stack)
	{
		free_list(stack);
		free(opcode);
	}
}