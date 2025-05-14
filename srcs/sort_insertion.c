#include "push_swap.h"
#include <stdio.h>

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
	int	size;

	if (!ctx || ctx->size_a <= 1)
		return ;
	// Keep track of initial size
	size = ctx->size_a;
	// Phase 1: Move all elements to stack B in ascending order
	while (ctx->stack_a)
	{
		// Find the minimum value and its position
		min_value = find_min(ctx->stack_a);
		min_pos = find_position(ctx->stack_a, min_value);
		// Optimize the rotations: choose between ra and rra
		// based on whether min_pos is in the first or second half
		if (min_pos <= ctx->size_a / 2)
		{
			// Element is in the first half, use ra
			while (ctx->stack_a->value != min_value)
				op_ra(ctx, true);
		}
		else
		{
			// Element is in the second half, use rra
			while (ctx->stack_a->value != min_value)
				op_rra(ctx, true);
		}
		// Push the minimum to B
		op_pb(ctx, true);
	}
	// Phase 2: Push everything back to A
	// Since elements are already sorted in B (in reverse),
	// we can just push them all back to A
	while (ctx->stack_b)
		op_pa(ctx, true);
}
