/* 
 * SORTING ALGORITHMS
 * 
 * This file implements various sorting algorithms for the push_swap project
 * with optimizations for different stack sizes.
 */

#include "push_swap.h"

/*
 * Sort just 2 elements in stack A
 * Only requires a single swap if needed
 */
void	sort_two(t_context *ctx)
{
	if (!ctx || !ctx->stack_a || !ctx->stack_a->next)
		return ;
	if (ctx->stack_a->value > ctx->stack_a->next->value)
		op_sa(ctx, true);
}

/*
 * Sort 3 elements in stack A
 * At most 2 operations are needed
 */
void	sort_three(t_context *ctx)
{
	int	a;
	int	b;
	int	c;

	if (!ctx || ctx->size_a != 3)
		return ;
	a = ctx->stack_a->value;
	b = ctx->stack_a->next->value;
	c = ctx->stack_a->next->next->value;
	if (a > b && b > c)
	{
		op_sa(ctx, true);
		op_rra(ctx, true);
	}
	else if (a > c && c > b)
		op_ra(ctx, true);
	else if (b > a && a > c)
		op_rra(ctx, true);
	else if (b > c && c > a)
	{
		op_sa(ctx, true);
		op_ra(ctx, true);
	}
	else if (c > a && a > b)
		op_sa(ctx, true);
}

/*
 * Helper function: Find the smallest element and push it to B
 * Used by sort_five to extract the smallest elements
 */
static void	push_smallest_to_b(t_context *ctx)
{
	int		min_pos;
	int		min;

	min = find_min(ctx->stack_a);
	min_pos = find_position(ctx->stack_a, min);
	if (min_pos <= ctx->size_a / 2)
	{
		while (min_pos-- > 0)
			op_ra(ctx, true);
	}
	else
	{
		while (min_pos++ < ctx->size_a)
			op_rra(ctx, true);
	}
	op_pb(ctx, true);
}

/*
 * Sort 5 elements
 * Strategy: Push the 2 smallest elements to B, sort the remaining 3,
 * then push everything back to A
 */
void	sort_five(t_context *ctx)
{
	if (!ctx || ctx->size_a < 4 || ctx->size_a > 5)
		return ;
	push_smallest_to_b(ctx);
	if (ctx->size_a == 4)
		push_smallest_to_b(ctx);
	sort_three(ctx);
	while (ctx->stack_b)
		op_pa(ctx, true);
}
