#include "push_swap.h"
#include <stdio.h>

/*
 * Parse command line arguments into stack A
 * Returns true on success, false on failure
 */
bool	parse_arguments(t_context *ctx, int argc, char **argv)
{
	int		i;
	t_stack	*new_node;
	t_stack	*last;
	long	value;

	if (!ctx || argc < 1)
		return (false);
	if (argc == 1)
	{
		parse_single_arg(ctx, argc, argv);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		// Validate argument
		if (!is_valid_integer(argv[i]))
			return (false);
		// Convert to integer
		value = 0;
		if (argv[i][0] == '-')
			value = -atoi(argv[i] + 1);
		else if (argv[i][0] == '+')
			value = atoi(argv[i] + 1);
		else
			value = atoi(argv[i]);
		new_node = stack_new_node((int)value);
		if (!new_node)
			return (false);
		// Add to bottom of stack_a (to maintain order as in args)
		if (!ctx->stack_a)
			ctx->stack_a = new_node;
		else
		{
			last = stack_last(ctx->stack_a);
			last->next = new_node;
		}
		ctx->size_a++;
		i++;
	}
	// Update total size
	ctx->total_size = ctx->size_a;
	// Check for duplicates
	if (has_duplicates(ctx->stack_a))
		return (false);
	return (true);
}
