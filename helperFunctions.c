#include "monty.h"

/**
 * free_list - frees a dlistint
 *
 * @head: the head
 *Return: void
 */

void free_list(stack_t *head)
{
	stack_t *tmp = head;

	if (head == NULL)
	{
		return;
	}
	while (tmp)
	{
		if (tmp->prev != NULL)
		{
			free(tmp->prev);
		}
		if (tmp->next == NULL)
		{
			free(tmp);
			return;
		}
		else
		{
			tmp = tmp->next;
		}
	}
}

/**
 * errorEXIT - helps push exit
 *
 * @stack: the stack
 * @line_num: the line number
 * @opcode: the opcode
 * @fd: the file
 */
void errorEXIT(stack_t **stack, unsigned int line_num, char *opcode, FILE *fd)
{
	dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_num);
	free_list(*stack);
	free(opcode);
	fclose(fd);
	exit(EXIT_FAILURE);
}

/**
 * add_node - adds a new node to the start of a list
 *
 * @head: pointer to the list
 * @str: str to be listed
 *
 *Return: the address of new element
 */

stack_t *add_node(stack_t **head, const int n, char *opcode, FILE *fd)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free(new);
		free_list(*head);
		free(opcode);
		fclose(fd);
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;

	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
	}
	else
	{
		(*head)->prev = new;
		new->next = *head;
		*head = new;
	}
	return (new);
}

/**
 * pallHelper - prints a list.
 *
 * @h: the starting node.
 *
 * Return: the count of elements printed.
 */

size_t pallHelper(const stack_t *h)
{
	size_t count = 0;
	const stack_t *current = h;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		count++;
		current = current->next;
	}
	return (count);
}
