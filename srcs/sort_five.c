#include "push_swap.h"

/*
** Finds the position of the smallest element in the stack
** Returns the position (0-based), or -1 if the stack is empty
*/
int	find_smallest_pos(t_stack *a)
{
	t_stack_node	*current;
	int				smallest;
	int				pos;
	int				smallest_pos;

	if (!a || !a->top)
		return (-1);
	current = a->top;
	smallest = current->data;
	pos = 0;
	smallest_pos = 0;
	while (current)
	{
		if (current->data < smallest)
		{
			smallest = current->data;
			smallest_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (smallest_pos);
}

/*
** Rotates the stack to bring the smallest element to the top
*/
void	rotate_to_smallest(t_stack *a)
{
	int	pos;
	int	size;

	pos = find_smallest_pos(a);
	if (pos == -1)
		return ;
	size = a->size;
	// Choose the most efficient rotation direction
	if (pos <= size / 2)
	{
		// Rotate forward
		while (pos > 0)
		{
			ra(a);
			pos--;
		}
	}
	else
	{
		// Rotate backward
		while (pos < size)
		{
			rra(a);
			pos++;
		}
	}
}

/*
** Sorts a stack with up to 5 elements
*/
void	sort_five(t_stack *a, t_stack *b)
{
	int	elements_to_push;

	if (!a || !b || a->size <= 3)
	{
		if (a && a->size <= 3)
			sort_three(a);
		return ;
	}
	// Push the 2 smallest elements to stack b
	elements_to_push = a->size - 3;
	while (elements_to_push > 0)
	{
		rotate_to_smallest(a);
		pb(a, b);
		elements_to_push--;
	}
	// Sort the remaining 3 elements in stack a
	sort_three(a);
	// Push elements back from stack b to stack a
	while (b->size > 0)
		pa(a, b);
}
