/* 
 * PUSH_SWAP MAIN PROGRAM
 * 
 * This file contains the main function for the push_swap program,
 * including a test framework to verify the implementation.
 */

#include "push_swap.h"

/**
 * Main function for push_swap
 * Parses arguments, sorts the stack, and performs cleanup
 */
int	main(int argc, char **argv)
{
	t_context	*ctx;

	if (argc < 2)
		return (0);
	ctx = init_context();
	if (!ctx)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!parse_arguments(ctx, argc, argv))
	{
		write(2, "Error\n", 6);
		cleanup_context(ctx);
		return (1);
	}
	if (!is_stack_sorted(ctx->stack_a))
		sort(ctx);
	cleanup_context(ctx);
	return (0);
}
