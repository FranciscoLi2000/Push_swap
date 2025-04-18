#include "push_swap.h"

void	push_a(t_stack *s1, t_stack *s2)
{
	int	val;

	if (is_empty(s2))
		return ;
	val = pop(s2);
	push(s1, val);
}

void	push_b(t_stack *s1, t_stack *s2)
{
	int	val;

	if (is_empty(s1))
		return ;
	val = pop(s1);
	push(s2, val);
}
