#include "push_swap.h"

void	swap_a(t_stack *s)
{
	int	tmp;

	if (s->top < 1)
		return ;
	tmp = s->data[s->top];
	s->data[s->top] = s->data[s->top - 1];
	s->data[s->top - 1] = tmp;
}

void	swap_b(t_stack *s)
{
	int	first;
	int	second;

	if (s->top < 1)
		return ;
	first = pop(s);
	second = pop(s);
	push(s, first);
	push(s, second);
}

void	swap_a_b(t_stack *s1, t_stack *s2)
{
	swap_a(s1);
	swap_b(s2);
}
