#include "push_swap.h"

/**
 * Check for duplicates in stack
 * Returns true if duplicates are found
 */
bool	has_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*check;

	current = stack;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (true);
			check = check->next;
		}
		current = current->next;
	}
	return (false);
}

/**
 * Parse command line arguments into stack A
 * Returns true on success, false on failure
 */
bool	parse_arguments(t_context *ctx, int argc, char **argv)
{
	int		i;
	t_stack	*new_node;
	long	value;

	if (!ctx || argc < 1)
		return (false);
	if (argc == 2)
		return (parse_single_arg(ctx, argc, argv));
	i = 1;
	while (i < argc)
	{
		if (!is_valid_integer(argv[i]))
			return (false);
		value = ft_atoi(argv[i]);
		new_node = stack_new_node((int)value);
		if (!new_node)
			return (false);
		if (!ctx->stack_a)
			ctx->stack_a = new_node;
		else
			stack_last(ctx->stack_a)->next = new_node;
		ctx->size_a++;
		i++;
	}
	ctx->total_size = ctx->size_a;
	if (has_duplicates(ctx->stack_a))
		return (false);
	return (true);
}
