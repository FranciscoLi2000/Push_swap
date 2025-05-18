#include "stack.h"

/*
** Shifts up all elements of stack a by 1
** The first element becomes the last one
** Prints "ra" to stdout
*/
void	ra(t_stack *a)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!a || !a->top || !a->top->next)
		return ;
	// Find the last node
	last = a->top;
	while (last->next)
		last = last->next;
	// Move the first node to the end
	first = a->top;
	a->top = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 3);
}

/*
** Shifts up all elements of stack b by 1
** The first element becomes the last one
** Prints "rb" to stdout
*/
void	rb(t_stack *b)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!b || !b->top || !b->top->next)
		return ;
	// Find the last node
	last = b->top;
	while (last->next)
		last = last->next;
	// Move the first node to the end
	first = b->top;
	b->top = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "rb\n", 3);
}

/*
** Shifts up all elements of both stacks a and b by 1
** Prints "rr" to stdout
*/
void	rr(t_stack *a, t_stack *b)
{
	t_stack_node	*first;
	t_stack_node	*last;
	// Rotate stack a if possible
	if (a && a->top && a->top->next)
	{
		last = a->top;
		while (last->next)
			last = last->next;
		first = a->top;
		a->top = first->next;
		first->next = NULL;
		last->next = first;
	}
	// Rotate stack b if possible
	if (b && b->top && b->top->next)
	{
		last = b->top;
		while (last->next)
			last = last->next;
		first = b->top;
		b->top = first->next;
		first->next = NULL;
		last->next = first;
	}
	write(1, "rr\n", 3);
}
