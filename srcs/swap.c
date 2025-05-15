/* 
 * PUSH_SWAP OPERATIONS IMPLEMENTATION
 * 
 * This file implements the required stack operations for the push_swap project:
 * - sa, sb, ss: swap operations
 * - pa, pb: push operations
 * - ra, rb, rr: rotate operations
 * - rra, rrb, rrr: reverse rotate operations
 */

#include "push_swap.h"

/*
 * Swap operation - swaps the top two elements of a stack
 * Used internally by the sa, sb, and ss operations
 */
static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

/*
 * sa: Swap the first two elements of stack A
 * If print is true, outputs "sa" to stdout
 */
void	op_sa(t_context *ctx, bool print)
{
	if (!ctx || !ctx->stack_a || !ctx->stack_a->next)
		return ;
	swap(&ctx->stack_a);
	ctx->counter.sa++;
	ctx->counter.total++;
	if (print)
		write(1, "sa\n", 3);
}

/*
 * sb: Swap the first two elements of stack B
 * If print is true, outputs "sb" to stdout
 */
void	op_sb(t_context *ctx, bool print)
{
	if (!ctx || !ctx->stack_b || !ctx->stack_b->next)
		return ;
	swap(&ctx->stack_b);
	ctx->counter.sb++;
	ctx->counter.total++;
	if (print)
		write(1, "sb\n", 3);
}

/*
 * ss: sa and sb at the same time
 * If print is true, outputs "ss" to stdout
 */
void	op_ss(t_context *ctx, bool print)
{
	if (!ctx)
		return ;
	if (ctx->stack_a && ctx->stack_a->next)
		swap(&ctx->stack_a);
	if (ctx->stack_b && ctx->stack_b->next)
		swap(&ctx->stack_b);
	ctx->counter.ss++;
	ctx->counter.total++;
	if (print)
		write(1, "ss\n", 3);
}
