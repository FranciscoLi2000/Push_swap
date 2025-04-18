#include "includes/push_swap.h"
#include <stdio.h>

int	find_min_index(const t_stack *s)
{
	int	min_index;
	int	i;

	min_index = s->top;
	i = s->top - 1;
	while (i >= 0)
	{
		if (s->data[i] < s->data[min_index])
			min_index = i;
		--i;
	}
	return (min_index);
}

void	bring_to_top(t_stack *s, int index)
{
	int	distance;
	int	i;

	distance = s->top - index;
	i = 0;
	while (i < distance)
	{
		rotate_a(s);
		++i;
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int	i;
	int	num;
	int	min_index;

	stack_init(&a);
	stack_init(&b);
	i = 1;
	while (i < argc)
	{
		num = atoi(argv[i]);
		push(&a, num);
		++i;
	}
	printf("Inicial:\n");
	print_stack(&a, "a");

	while (!is_empty(&a))
	{
		min_index = find_min_index(&a);
		bring_to_top(&a, min_index);
		push(&b, pop(&a));
	}
	while (!is_empty(&b))
		push(&a, pop(&b));
	printf("After sorting:\n");
	print_stack(&a, "a");
	return (0);
}
