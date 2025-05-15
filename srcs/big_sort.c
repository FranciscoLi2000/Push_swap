#include "push_swap.h"

/**
 * Radix sort implementation for push_swap
 * This algorithm sorts integers by processing their binary representation
 * bit by bit, from the least significant bit to the most significant bit
 */
void	sort_radix(t_context *ctx)
{
	int	i;
	int	j;
	int	max_bits;
	int	num;
	int	*sorted;

	sorted = create_sorted_array(ctx);
	if (!sorted)
		error_exit(ctx);
	normalize_values(ctx, sorted);
	free(sorted);
	max_bits = 0;
	num = ctx->total_size - 1;
	while (num > 0)
	{
		max_bits++;
		num >>= 1;
	}
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < ctx->total_size)
		{
			if ((ctx->stack_a->value >> i) & 1)
				op_ra(ctx, true);
			else
				op_pb(ctx, true);
			j++;
		}
		while (ctx->stack_b)
			op_pa(ctx, true);
		i++;
	}
}

/**
 * Main sorting function that selects the appropriate algorithm
 * based on the number of elements to sort
 */
void	sort(t_context *ctx)
{
	if (!ctx || ctx->size_a <= 1 || is_stack_sorted(ctx->stack_a))
		return ;
	if (ctx->size_a == 2)
		sort_two(ctx);
	else if (ctx->size_a == 3)
		sort_three(ctx);
	else if (ctx->size_a <= 5)
		sort_five(ctx);
	else if (ctx->size_a <= 20)
		sort_insertion(ctx);
	else if (ctx->size_a <= 60)
		sort_chunks(ctx, 3);
	else if (ctx->size_a <= 100)
		sort_chunks(ctx, 5);
	else
		sort_radix(ctx);
}
