/* 
 * SORTING ALGORITHMS
 * 
 * This file implements various sorting algorithms for the push_swap project
 * with optimizations for different stack sizes.
 */

#include "push_swap.h"
#include <stdio.h>

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
	int	first;
	int	second;
	int	third;

	if (!ctx || ctx->size_a != 3)
		return ;
	a = ctx->stack_a->value;
	b = ctx->stack_a->next->value;
	c = ctx->stack_a->next->next->value;
	// Case 1: a > b > c (321) -> sa, rra
	if (a > b && b > c)
	{
		op_sa(ctx, true);
		op_rra(ctx, true);
	}
	// Case 2: a > c > b (312) -> ra
	else if (a > c && c > b)
		op_ra(ctx, true);
	// Case 3: b > a > c (231) -> rra
	else if (b > a && a > c)
		op_rra(ctx, true);
	// Case 4: b > c > a (213) -> sa, ra
	else if (b > c && c > a)
	{
		op_sa(ctx, true);
		op_ra(ctx, true);
	}
	// Case 5: c > a > b (132) -> sa
	else if (c > a && a > b)
		op_sa(ctx, true);
	// Case 6: c > b > a (123) is already sorted, do nothing
}

/*
 * Helper function: Find the smallest element and push it to B
 * Used by sort_five to extract the smallest elements
 */
static void	push_smallest_to_b(t_context *ctx)
{
	t_stack	*tmp;
	int		min_pos;
	int		min;
	int		i;

	// Find the smallest element
	min = find_min(ctx->stack_a);
	// Find its position
	tmp = ctx->stack_a;
	min_pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->value == min)
		{
			min_pos = i;
			break ;
		}
		tmp = tmp->next;
		i++;
	}
	// Move the smallest element to the top
	if (min_pos <= ctx->size_a / 2)
	{
		while (min_pos-- > 0)
			op_ra(ctx, true);	// Use rotate if in first half
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
	// Push smallest element to B
	push_smallest_to_b(ctx);
	// If we have 5 elements, push the second smallest to B as well
	if (ctx->size_a == 4)
		push_smallest_to_b(ctx);
	// Sort the remaining 3 elements
	sort_three(ctx);
	// Push everything back to A (they'll be in the correct order)
	while (ctx->stack_b)
		op_pa(ctx, true);
}
