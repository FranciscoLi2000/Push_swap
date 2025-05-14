#include "push_swap.h"
#include <stdio.h>

/*
 * Reverse rotate operation - shifts all elements of a stack down by 1
 * The last element becomes the first one
 * Used internally by the rra, rrb, and rrr operations
 */
static void	reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = stack_last(*stack);
	// Find the second to last element
	second_last = first;
	while (second_last->next && second_last->next->next)
		second_last = second_last->next;
	if (second_last->next) // Safety check
	{
		last = second_last->next;
		second_last->next = NULL;
		last->next = first;
		*stack = last;
	}
}

/*
 * rra: Reverse rotate stack A (last element becomes first)
 * If print is true, outputs "rra" to stdout
 */
void	op_rra(t_context *ctx, bool print)
{
	if (!ctx || !ctx->stack_a || !ctx->stack_a->next)
		return ;
	reverse_rotate(&ctx->stack_a);
	// Update operation counter
	ctx->counter.rra++;
	ctx->counter.total++;
	if (print)
		write(1, "rra\n", 3);
}

/*
 * rrb: Reverse rotate stack B (last element becomes first)
 * If print is true, outputs "rrb" to stdout
 */
void	op_rrb(t_context *ctx, bool print)
{
	if (!ctx || !ctx->stack_b || !ctx->stack_b->next)
		return ;
	reverse_rotate(&ctx->stack_b);
	// Update operation counter
	ctx->counter.rrb++;
	ctx->counter.total++;
	if (print)
		write(1, "rrb\n", 3);
}

/*
 * rrr: rra and rrb at the same time
 * If print is true, outputs "rrr" to stdout
 */
void	op_rrr(t_context *ctx, bool print)
{
	if (!ctx)
		return ;
	// Perform the reverse rotations without printing
	if (ctx->stack_a && ctx->stack_a->next)
		reverse_rotate(&ctx->stack_a);
	if (ctx->stack_b && ctx->stack_b->next)
		reverse_rotate(&ctx->stack_b);
	// Update operation counter
	ctx->counter.rrr++;
	ctx->counter.total++;
	if (print)
		write(1, "rrr\n", 3);
}
