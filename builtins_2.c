#include "monty.h"

/**
 * OPpop - implements pop opcode
 *
 * @stack: list
 * @line_num: line number
 * @opcode: opcode
 * @fd: file 
 * 
 */

void OPpop(stack_t **stack, unsigned int line_num, char *opcode, FILE *fd)
{
	stack_t *temp;

	if ((*stack) == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n",
			line_num);
		free_list(*stack);
		free(opcode);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	while (temp->prev != NULL)
	{
		temp = temp->prev;
	}
	if (temp->next != NULL)
	{
		temp->next->prev = NULL;
	}
	if (temp == *stack)
	{
		if ((*stack)->next != NULL)
		{
			*stack = (*stack)->next;
		}
		else
		{
			*stack = NULL;
		}
	}
	free(temp);
}

/**
 * 
 * 
 * 
 * 
 */

void OPadd(stack_t **stack, unsigned int line_num, char *opcode, FILE *fd)
{
	stack_t *temp, *blah;

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
	if (temp == *stack)
	{
		*stack = blah;
	}
	blah->n = temp->n + blah->n;
	blah->prev = NULL;
	free(temp);
}

/**
 * 
 * 
 * 
 */

void OPnop(stack_t **stack, unsigned int line_num, char *opcode, FILE *fd)
{
	stack = stack;
	line_num = line_num;
	opcode = opcode;
	fd = fd;
}