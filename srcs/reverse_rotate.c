#include "stack.h"

/*
** Shifts down all elements of stack a by 1
** The last element becomes the first one
** Prints "rra" to stdout
*/
void	rra(t_stack *a)
{
	t_stack_node	*last;
	t_stack_node	*second_last;

	if (!a || !a->top || !a->top->next)
		return ;
	// Find the last and second-to-last nodes
	last = a->top;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	// Move the last node to the front
	second_last->next = NULL;
	last->next = a->top;
	a->top = last;
	write(1, "rra\n", 4);
}

/*
** Shifts down all elements of stack b by 1
** The last element becomes the first one
** Prints "rrb" to stdout
*/
void	rrb(t_stack *b)
{
	t_stack_node	*last;
	t_stack_node	*second_last;

	if (!b || !b->top || !b->top->next)
		return ;
	// Find the last and second-to-last nodes
	last = b->top;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	// Move the last node to the front
	second_last->next = NULL;
	last->next = b->top;
	b->top = last;
	write(1, "rrb\n", 4);
}

/*
** Shifts down all elements of both stacks a and b by 1
** Prints "rrr" to stdout
*/
void	rrr(t_stack *a, t_stack *b)
{
	t_stack_node	*last;
	t_stack_node	*second_last;
	// Reverse rotate stack a if possible
	if (a && a->top && a->top->next)
	{
		last = a->top;
		second_last = NULL;
		while (last->next)
		{
			second_last = last;
			last = last->next;
		}
		second_last->next = NULL;
		last->next = a->top;
		a->top = last;
	}
	// Reverse rotate stack b if possible
	if (b && b->top && b->top->next)
	{
		last = b->top;
		second_last = NULL;
		while (last->next)
		{
			second_last = last;
			last = last->next;
		}
		second_last->next = NULL;
		last->next = b->top;
		b->top = last;
	}
	write(1, "rrr\n", 4);
}
