#include "push_swap.h"

/*
** Finds the position of the largest element in the stack
** Returns the position (0-based), or -1 if the stack is empty
*/
int	find_largest_pos(t_stack *b)
{
	t_stack_node	*current;
	int				largest;
	int				pos;
	int				largest_pos;

	if (!b || !b->top)
		return (-1);
	current = b->top;
	largest = current->data;
	pos = 0;
	largest_pos = 0;
	while (current)
	{
		if (current->data > largest)
		{
			largest = current->data;
			largest_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (largest_pos);
}

/*
** Sorts a stack using insertion sort
*/
void	sort_insertion(t_stack *a, t_stack *b)
{
	int	pos;

	if (!a || !b || a->size <= 5)
	{
		if (a && a->size <= 5)
			sort_five(a, b);
		return ;
	}
	// Push all elements except the last one to stack b
	while (a->size > 1)
		pb(a, b);
	// Insert elements back into stack a in sorted order
	while (b->size > 0)
	{
		// Find the position of the largest element in stack b
		pos = find_largest_pos(b);
		// Rotate stack b to bring the largest element to the top
		if (pos <= b->size / 2)
		{
			// Rotate forward
			while (pos > 0)
			{
				rb(b);
				pos--;
			}
		}
		else
		{
			// Rotate backward
			while (pos < b->size)
			{
				rrb(b);
				pos++;
			}
		}
		// Push the largest element to stack a
		pa(a, b);
	}
}
