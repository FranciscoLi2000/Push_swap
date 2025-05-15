#include "push_swap.h"

/**
 * Move the element at position 'pos' to the top of stack A
 * Uses the optimal rotation direction (ra or rra)
 */
void	move_element_to_top(t_context *ctx, int pos)
{
	if (pos <= ctx->size_a / 2)
	{
		while (pos-- > 0)
			op_ra(ctx, true);
	}
	else
	{
		while (pos++ < ctx->size_a)
			op_rra(ctx, true);
	}
}

/*
 * Implements an insertion sort algorithm for push_swap
 * This is efficient for small to medium sets (6-20 elements)
 *
 * Strategy:
 * 1. Find the smallest element in stack A
 * 2. Move it to the top of stack A using optimal rotations
 * 3. Push it to stack B
 * 4. Repeat until stack A is empty
 * 5. Push everything back from B to A (they'll be in sorted order)
 */
void	sort_insertion(t_context *ctx)
{
	int	min_value;
	int	min_pos;

	if (!ctx || ctx->size_a <= 1)
		return ;
	while (ctx->stack_a)
	{
		min_value = find_min(ctx->stack_a);
		min_pos = find_position(ctx->stack_a, min_value);
		move_element_to_top(ctx, min_pos);
		op_pb(ctx, true);
	}
	while (ctx->stack_b)
		op_pa(ctx, true);
}
