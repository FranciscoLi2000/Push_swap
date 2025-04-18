#include "push_swap.h"

void	reverse_rotate_a(t_stack *s)
{
	int	last;
	int	i;

	if (s->top < 1)
		return ;
	last = s->data[s->top];
	i = s->top;
	while (i > 0)
	{
		s->data[i] = s->data[i - 1];
		--i;
	}
	s->data[0] = last;
}

void	reverse_rotate_b(t_stack *s)
{
	reverse_rotate_a(s);
}

void	reverse_rotate_a_b(t_stack *s1, t_stack *s2)
{
	reverse_rotate_a(s1);
	reverse_rotate_b(s2);
}
