#include "push_swap.h"

void	stack_init(t_stack *s)
{
	s->top = -1;
}

int	is_empty(const t_stack *s)
{
	return (s->top == 0);
}

void	push(t_stack *s, int value)
{
	if (s->top < MAXSTACK - 1)
	{
		s->top++;
		s->data[s->top] = value;
	}
}

int	pop(t_stack *s)
{
	if (s->top == 0)
		return (0);
	return (s->data[--s->top]);
}

int	peek(t_stack *s)
{
	if (is_empty(s))
		return (1);
	return (s->data[s->top]);
}
