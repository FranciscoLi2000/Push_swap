#include "push_swap.h"

void	rotate_a(t_stack *s)
{
	int	first;
	int	i;

	if (s->top <= 1)
		return ;
	first = s->data[0];
	i = 0;
	while (i < s->top)
	{
		s->data[i] = s->data[i + 1];
		++i;
	}
	s->data[s->top] = first;
}

void	rotate_b(t_stack *s)
{
	rotate_a(s);
}

void	rotate_a_b(t_stack *s1, t_stack *s2)
{
	rotate_a(s1);
	rotate_b(s2);
}
