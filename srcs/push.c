#include "push_swap.h"
#include <stdio.h>

/*
 * pa: Push the first element of stack B to stack A
 * If print is true, outputs "pa" to stdout
 */
void	op_pa(t_context *ctx, bool print)
{
	t_stack	*top_b;

	if (!ctx || !ctx->stack_b)
		return ;
	top_b = stack_pop(&ctx->stack_b);
	if (top_b)
	{
		stack_push(&ctx->stack_a, top_b);
		ctx->size_a++;
		ctx->size_b--;
	}
	// Update operation counter
	ctx->counter.pa++;
	ctx->counter.total++;
	if (print)
		write(1, "pa\n", 3);
}

/*
 * pb: Push the first element of stack A to stack B
 * If print is true, outputs "pb" to stdout
 */
void	op_pb(t_context *ctx, bool print)
{
	t_stack	*top_a;
	
	if (!ctx || !ctx->stack_a)
		return ;
	top_a = stack_pop(&ctx->stack_a);
	if (top_a)
	{
		stack_push(&ctx->stack_b, top_a);
		ctx->size_a--;
		ctx->size_b++;
	}
	// Update operation counter
	ctx->counter.pb++;
	ctx->counter.total++;
	if (print)
		write(1, "pb\n", 3);
}
