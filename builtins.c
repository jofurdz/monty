#include "monty.h"

/**
 * OPpush - implements psuh op
 *
 * @stack: list
 * @fd: file
 * @line_num: line number
 * @opcode: opcode
 */

void OPpush(stack_t **stack, unsigned int line_num, char *opcode, FILE *fd)
{
	int i, j;

	if (!opGlobal[1])
	{
		errorEXIT(stack, line_num, opcode, fd);
	}
	for (j = 0; opGlobal[1][j] != 0; j++)
	{
		if (isalpha(opGlobal[1][j]) != 0)
		{
			errorEXIT(stack, line_num, opcode, fd);
		}
	}
	if (strcmp(opGlobal[1], "0") == 0 || strcmp(opGlobal[1], "-0") == 0)
	{
		i = 0;
	}
	else
	{
		i = atoi(opGlobal[1]);

		if (i == 0)
		{
			errorEXIT(stack, line_num, opcode, fd);
		}
	}
	add_node(stack, i, opcode, fd);
}

/**
 * OPpall - implements pall
 *
 * @stack: list
 * @line_num: line number
 * @opcode: opcode
 * @fd: file
 */

void OPpall(stack_t **stack, unsigned int line_num, char *opcode, FILE *fd)
{
	(void)opcode;
	(void)fd;
	(void)line_num;
	if (*stack)
	{
		pallHelper(*stack);
	}
}

/**
 * OPpint - implements pint
 *
 * @stack: list
 * @line_num: line number
 * @opcode: opcode
 * @fd: file
 */

void OPpint(stack_t **stack, unsigned int line_num, char *opcode, FILE *fd)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n",
			line_num);
		free_list(*stack);
		free(opcode);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	while (temp->prev != NULL)
		temp = temp->prev;
	printf("%i\n", temp->n);
}

/**
 * OPswap - Implements swap
 * @stack: the list
 * @line_num: line number
 * @opcode: opcode
 * @fd: file
 */
void OPswap(stack_t **stack, unsigned int line_num, char *opcode, FILE *fd)
{
	stack_t *temp, *blah;
	int n;

	if (*stack == NULL ||
	    (((*stack)->prev == NULL) && (*stack)->next == NULL))
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n",
			line_num);
		free_list(*stack);
		free(opcode);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	for (temp = *stack; temp->prev; temp = temp->prev)
	{
	}
	blah = temp->next;
	n = temp->n;
	temp->n = blah->n;
	blah->n = n;
}
