#include "push_swap.h"

/**
 * Print current state of stacks (for debugging)
 * This is only used when debug mode is enabled
 */
void	print_stacks(t_context *ctx)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	if (!ctx)
		return ;
	a = ctx->stack_a;
	b = ctx->stack_b;
	ft_putstr_fd("\n-----------------------\n", 1);
	ft_putstr_fd("Stacks (total ops: ", 1);
	ft_putnbr_fd(ctx->counter.total, 1);
	ft_putstr_fd("):\n", 1);
	i = 0;
	while (i < ctx->size_a || i < ctx->size_b)
	{
		if (i < ctx->size_a)
		{
			ft_putnbr_fd(a->value, 1);
			ft_putstr_fd("\t\t", 1);
			a = a->next;
		}
		else
			ft_putstr_fd("\t\t", 1);
		if (i < ctx->size_b)
		{
			ft_putnbr_fd(b->value, 1);
			b = b->next;
		}
		ft_putchar_fd('\n', 1);
		i++;
	}
	ft_putstr_fd("-----------  -----------\n", 1);
	ft_putstr_fd("stack_a\t\tstack_b\n", 1);
	ft_putstr_fd("-----------------------\n\n", 1);
}
