#include "push_swap.h"
#include <stdio.h>

/*
 * Rotate operation - shifts all elements of a stack up by 1
 * The first element becomes the last one
 * Used internally by the ra, rb, and rr operations
 */
static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = stack_last(*stack);
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

/*
 * ra: Rotate stack A (first element becomes last)
 * If print is true, outputs "ra" to stdout
 */
void	op_ra(t_context *ctx, bool print)
{
	if (!ctx || !ctx->stack_a || !ctx->stack_a->next)
		return ;
	rotate(&ctx->stack_a);
	ctx->counter.ra++;
	ctx->counter.total++;
	if (print)
		write(1, "ra\n", 3);
}

/*
 * rb: Rotate stack B (first element becomes last)
 * If print is true, outputs "rb" to stdout
 */
void	op_rb(t_context *ctx, bool print)
{
	if (!ctx || !ctx->stack_b || !ctx->stack_b->next)
		return ;
	rotate(&ctx->stack_b);
	// Update operation counter
	ctx->counter.rb++;
	ctx->counter.total++;
	if (print)
		write(1, "rb\n", 3);
}

/*
 * rr: ra and rb at the same time
 * If print is true, outputs "rr" to stdout
 */
void	op_rr(t_context *ctx, bool print)
{
	if (!ctx)
		return ;
	// Perform the rotations without printing
	if (ctx->stack_a && ctx->stack_a->next)
		rotate(&ctx->stack_a);
	if (ctx->stack_b && ctx->stack_b->next)
		rotate(&ctx->stack_b);
	// Update operation counter
	ctx->counter.rr++;
	ctx->counter.total++;
	if (print)
		write(1, "rr\n", 3);
}
