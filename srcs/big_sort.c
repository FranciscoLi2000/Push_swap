#include "push_swap.h"
#include <stdio.h>

/*
 * Helper function: Replace actual values with their normalized indices
 * This converts the problem into sorting positions (0 to n-1)
 * instead of sorting actual values
 */
void	normalize_values(t_context *ctx)
{
	int		i;
	int		*sorted;
	t_stack	*temp;
	// Create sorted reference array
	sorted = create_sorted_array(ctx);
	if (!sorted)
		error_exit(ctx);
	// Replace actual values with their index in the sorted array
	temp = ctx->stack_a;
	while (temp)
	{
		i = 0;
		while (i < ctx->total_size)
		{
			if (temp->value == sorted[i])
			{
				temp->value = i;
				break ;
			}
		}
		temp = temp->next;
	}
	free(sorted);
}

/*
 * Radix sort implementation for push_swap
 * This algorithm sorts integers by processing their binary representation
 * bit by bit, from the least significant bit to the most significant bit
 */
void	sort_radix(t_context *ctx)
{
	int	i;
	int	j;
	int	num;
	int	max_bits;
	// First, normalize values to their positions in sorted order
	normalize_values(ctx);
	// Calculate how many bits we need to examine
	// For n elements, we need log2(n) bits
	max_bits = 0;
	num = ctx->total_size - 1;
	while (num > 0)
	{
		max_bits++;
		num >>= 1;
	}
	// Sort by each bit, starting from the least significant bit (LSB)
	i = 0;
	while (i < max_bits)	// Sort by each bit, starting from the least significant bit (LSB)
	{
		j = 0;
		while (j < ctx->total_size)	// Process each element in stack A
		{
			// If current bit is 0, push to B; if 1, rotate to bottom of A
			if ((ctx->stack_a->value >> i) & 1)
				op_ra(ctx, true);  // Bit is 1, keep in A but rotate
			else
				op_pb(ctx, true);  // Bit is 0, push to B
			j++;
		}
		// Push all elements back from B to A to prepare for next bit
		while (ctx->stack_b)
			op_pa(ctx, true);
		i++;
	}
}

/*
 * Main sorting algorithm for larger sets
 * Uses a variation of the Radix sort algorithm adapted for two stacks
 */
void	sort(t_context *ctx)
{
	if (!ctx || ctx->size_a <= 1 || is_stack_sorted(ctx->stack_a))
		return ;
	// Special cases for small stacks
	if (ctx->size_a == 2)
		sort_two(ctx);
	else if (ctx->size_a == 3)
		sort_three(ctx);
	else if (ctx->size_a <= 5)
		sort_five(ctx);
	else if (ctx->size_a <= 20)
		sort_insertion(ctx);
	else if (ctx->size_a <= 60)
		sort_chunks(ctx, 3); // Using 3 chunks for this range
	else if (ctx->size_a <= 100)
		sort_chunks(ctx, 5); // Using 5 chunks for this range
	else
		sort_radix(ctx);
	return ;
}
