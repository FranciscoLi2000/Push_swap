#include "stack.h"

/*
** Swaps the top two elements of stack a
** Does nothing if there are fewer than 2 elements
** Prints "sa" to stdout
*/
void	sa(t_stack *a)
{
	int	temp;

	if (!a || !a->top || !a->top->next)
		return ;
	temp = a->top->data;
	a->top->data = a->top->next->data;
	a->top->next->data = temp;

	// Also swap the indices if they're being used
	temp = a->top->index;
	a->top->index = a->top->next->index;
	a->top->next->index = temp;
	write(1, "sa\n", 3);
}

/*
** Swaps the top two elements of stack b
** Does nothing if there are fewer than 2 elements
** Prints "sb" to stdout
*/
void	sb(t_stack *b)
{
	int	temp;

	if (!b || !b->top || !b->top->next)
		return ;
	temp = b->top->data;
	b->top->data = b->top->next->data;
	b->top->next->data = temp;

	// Also swap the indices if they're being used
	temp = b->top->index;
	b->top->index = b->top->next->index;
	b->top->next->index = temp;
	write(1, "sb\n", 3);
}

/*
** Swaps the top two elements of both stacks a and b
** Prints "ss" to stdout
*/
void	ss(t_stack *a, t_stack *b)
{
	int	temp_a;
	int	temp_b;

	// Swap top two elements of stack a if possible
	if (a && a->top && a->top->next)
	{
		temp_a = a->top->data;
		a->top->data = a->top->next->data;
		a->top->next->data = temp_a;

		// Also swap the indices
		temp_a = a->top->index;
		a->top->index = a->top->next->index;
		a->top->next->index = temp_a;
	}
	// Swap top two elements of stack b if possible
	if (b && b->top && b->top->next)
	{
		temp_b = b->top->data;
		b->top->data = b->top->next->data;
		b->top->next->data = temp_b;

		// Also swap the indices
		temp_b = b->top->index;
		b->top->index = b->top->next->index;
		b->top->next->index = temp_b;
	}
	write(1, "ss\n", 3);
}
