/* 
 * CONTEXT AND UTILITY FUNCTIONS
 * 
 * This file implements the context initialization, cleanup,
 * parsing, and utility functions for the push_swap project.
 */

#include "push_swap.h"
#include <stdio.h>

/*
 * Initialize the program context
 * Sets up empty stacks and zeroes all counters
 */
t_context	*init_context(void)
{
	t_context	*ctx;

	ctx = (t_context *)malloc(sizeof(t_context));
	if (!ctx)
		return (NULL);
	// Initialize stacks to NULL (empty)
	ctx->stack_a = NULL;
	ctx->stack_b = NULL;
	// Zero out the counter
	ctx->counter.sa = 0;
	ctx->counter.sb = 0;
	ctx->counter.ss = 0;
	ctx->counter.pa = 0;
	ctx->counter.pb = 0;
	ctx->counter.ra = 0;
	ctx->counter.rb = 0;
	ctx->counter.rr = 0;
	ctx->counter.rra = 0;
	ctx->counter.rrb = 0;
	ctx->counter.rrr = 0;
	ctx->counter.total = 0;
	// Initialize size trackers
	ctx->size_a = 0;
	ctx->size_b = 0;
	ctx->total_size = 0;
	// No sorted array yet
	ctx->sorted = NULL;
	// Debug mode off by default
	ctx->debug = false;
	return (ctx);
}

/*
 * Clean up and free all resources
 */
void	cleanup_context(t_context *ctx)
{
	if (!ctx)
		return ;
	// Free both stacks
	stack_free(&ctx->stack_a);
	stack_free(&ctx->stack_b);
	// Free the sorted array if it exists
	if (ctx->sorted)
		free(ctx->sorted);
	// Free the context itself
	free(ctx);
}

/*
 * Check if a string is a valid integer
 * Handles sign characters and checks for overflow
 */
bool	is_valid_integer(const char *str)
{
	long	value;
	int		sign;

	if (!str || !*str)
		return (false);
	// Skip whitespace
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	// Handle sign
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	// Must have at least one digit
	if (!*str || !(*str >= '0' && *str <= '9'))
		return (false);
	// Parse number and check for overflow
	value = 0;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		value = value * 10 + (*str - '0');
		// Check for overflow
		if ((sign == 1 && value > INT_MAX)
			|| (sign == -1 && value * sign < INT_MIN))
			return (false);
		str++;
	}
	// Check if we reached the end of the string
	// If not, there are invalid characters
	return (*str == '\0');
}

/*
 * Check for duplicates in stack
 * Returns true if duplicates are found
 */
bool	has_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*check;

	current = check;
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

/*
 * Print error message and exit
 */
void	error_exit(t_context *ctx)
{
	write(2, "Error\n", 6);
	cleanup_context(ctx);
	exit(1);
}
