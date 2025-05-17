#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->top->data;
	y = a->top->next->data;
	z = a->top->next->next->data;
	if (x > y && y < z && x < z)
		sa(a, true);
	else if (x > y && y > z)
	{
		sa(a, true);
		rra(a, true);
	}
	else if (x > y && y < z && x > z)
		ra(a, true);
	else if (x < y && y > z && x < z)
	{
		sa(a, true);
		ra(a, true);
	}
	else if (x < y && y > z && x > z)
		rra(a, true);
}
