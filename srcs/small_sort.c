#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	top = a->top->value;
	mid = a->top->next->value;
	bot = a->bottom->value;
	if (top > mid && mid < bot && bot > top)
		sa(a);
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && mid < bot && bot < top)
		ra(a);
	else if (top < mid && mid > bot && bot > top)
	{
		sa(a);
		ra(a);
	}
	else if (top < mid && mid > bot && bot < top)
		rra(a);
}

void	small_sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else
		sort_five(a, b);
}
