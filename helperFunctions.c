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
