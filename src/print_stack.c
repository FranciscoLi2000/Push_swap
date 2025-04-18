#include "push_swap.h"
#include <stdio.h>

void	print_stack(const t_stack *s, const char *name)
{
	int	i;

	printf("Stack %s:\n", name);
	i = s->top;
	while (i >= 0)
	{
		printf("%d\n", s->data[i]);
		--i;
	}
	printf("\n");
}
