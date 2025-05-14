#include "push_swap.h"
#include <stdio.h>

/*
 * Print current state of stacks (for debugging)
 */
void	print_stacks(t_context *ctx)
{
	t_stack	*a;
	t_stack	*b;
	int		max_size;
	int		i;

	if (!ctx)
		return ;
	a = ctx->stack_a;
	b = ctx->stack_b;
	if (ctx->size_a > ctx->size_b)
		max_size = ctx->size_a;
	else
		max_size = ctx->size_b;
	printf("\n-----------------------\n");
	printf("Stacks (total ops: %d):\n", ctx->counter.total);
	i = 0;
	while (i < max_size)
	{
		if (i < ctx->size_a)
		{
			printf("%-11d", a->value);
			a = a->next;
		}
		else
			printf("%-11s", "");
		if (i < ctx->size_b)
		{
			printf("%-11d", b->value);
			b = b->next;
		}
		else
			printf("%-11s", "");
		printf("\n");
		i++;
	}
	printf("-----------  -----------\n");
	printf("%-11s %-11s\n", "stack_a", "stack_b");
	printf("-----------------------\n\n");
}

/*
 * Calculate how many moves needed to bring a position to the top
 * Returns the minimum number of moves (using rotate or reverse rotate)
 */
int	calculate_moves(int position, int stack_size)
{
	if (position <= stack_size / 2)
		return (position);
	else
		return (stack_size - position);
}
