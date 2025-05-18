#include "stack.h"

/*
** Checks if the stack is empty
** Returns true if empty, false otherwise
*/
bool	stack_is_empty(const t_stack *s)
{
	return (!s || s->size == 0);
}

/*
** Returns the number of elements in the stack
*/
int	stack_size(const t_stack *s)
{
	if (!s)
		return (0);
	return (s->size);
}

/*
** Checks if the stack is sorted in ascending order
** Returns true if sorted, false otherwise
*/
bool	is_sorted(const t_stack *s)
{
	t_stack_node	*current;

	if (!s || !s->top || s->size <= 1)
		return (true);
	current = s->top;
	while (current->next)
	{
		if (current->data > current->next->data)
			return (false);
		current = current->next;
	}
	return (true);
}

/*
** Checks for duplicate values in the stack
** Returns true if duplicates are found, false otherwise
*/
bool	check_duplicate(const t_stack *s)
{
	t_stack_node	*i;
	t_stack_node	*j;

	if (!s || !s->top)
		return (false);
	i = s->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->data == j->data)
				return (true);
			j = j->next;
		}
		i = i->next;
	}
	return (false);
}

/*
** Prints the contents of the stack for debugging purposes
*/
void	print_stack(const t_stack *s, const char *name)
{
	t_stack_node	*current;

	if (!s)
		return ;
	printf("Stack %s (size %d):\n", name, s->size);
	current = s->top;
	while (current)
	{
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}
