#include "push_swap.h"
#include <stdio.h>

/*
 * Checks if stack A contains any elements that belong to the current chunk
 */
static bool	has_chunk_elements(t_context *ctx, int *sorted, int chunk_start, int chunk_end)
{
	t_stack	*temp;
	int		i;

	temp = ctx->stack_a;
	while (temp)
	{
		// Check each element in stack A
		i = chunk_start;
		while (i <= chunk_end)
		{
			if (temp->value == sorted[i])
				return (true);
			i++;
		}
		temp = temp->next;
	}
	return (false);
}

/*
 * Calculates the minimum number of operations needed 
 * to bring an element at position 'pos' to the top of a stack
 */
static int	calculate_move_cost(int pos, int stack_size)
{
	// We can either rotate forward or reverse rotate
	// We choose whichever requires fewer operations
	if (pos <= stack_size / 2)
		return (pos);  // Using ra/rb
	else
		return (stack_size - pos);  // Using rra/rrb
}

/*
 * Finds the position of the element in the current chunk that
 * requires the fewest operations to move to the top of stack A
 */
static int	find_best_chunk_element(t_context *ctx, int *sorted, int chunk_start, int chunk_end)
{
	t_stack	*temp;
	int		best_pos;
	int		best_cost;
	int		pos;
	int		cost;

	best_pos = -1;
	best_cost = INT_MAX;
	pos = 0;
	temp = ctx->stack_a;
	while (temp)
	{
		// Check if this element belongs to the current chunk
		i = chunk_start;
		while (i <= chunk_end)
		{
			if (temp->value == sorted[i])
			{
				// Calculate the cost of moving this element to the top
				cost = calculate_move_cost(pos, ctx->size_a);
				// Update our best candidate if this one is cheaper
				if (cost < best_cost)
				{
					best_cost = cost;
					best_pos = pos;
				}
				break ;  // No need to check other values in the chunk
			}
		}
		temp = temp->next;
		pos++;
	}
	return (best_pos);
}

/*
 * Moves the element at position 'pos' to the top of stack A
 * Uses the optimal rotation direction (ra or rra)
 */
static void	move_element_to_top(t_context *ctx, int pos)
{
	int	i;

	if (pos <= ctx->size_a / 2)
	{
		// Element is in the first half, use ra
		i = 0;
		while (i < pos)
		{
			op_ra(ctx, true);
			i++;
		}
	else
	{
		// Element is in the second half, use rra
		i = 0;
		while (i < ctx->size_a - pos)
		{
			op_rra(ctx, true);
			i++;
		}
	}
}

/*
 * Optional optimization: Keep stack B partially sorted
 * by placing larger values toward the bottom
 */
/*static void	optimize_stack_b(t_context *ctx, int value)
{
	// This is an optional optimization
	// If the pushed value is in the lower half of our sorted range,
	// we rotate it to the bottom of B to maintain a partial ordering

	// This requires additional knowledge about the value ranges
	// A simpler approach is to skip this optimization initially

	// If implemented, it could look something like:
	if (value < median_value)
	{
		op_rb(ctx, true);  // Rotate larger values toward the bottom
	}
}*/

/*
 * Helper function to process a single chunk
 * Moves all elements within the given value range from stack A to stack B
 */
static void	process_chunk(t_context *ctx, int *sorted, int chunk_start, int chunk_end)
{
	int	best_pos;

	// Continue until we've moved all elements in this chunk to stack B
	while (has_chunk_elements(ctx, sorted, chunk_start, chunk_end))
	{
		// Find the element in the chunk that requires the fewest moves
		// to reach the top of stack A
		best_pos = find_best_chunk_element(ctx, sorted, chunk_start, chunk_end);
		// Move this element to the top of stack A
		move_element_to_top(ctx, best_pos);
		// Push the element to stack B
		op_pb(ctx, true);
		// Optional: Optimize stack B by rotating larger elements to the bottom
		// This keeps B partially sorted during the process
		// optimize_stack_b(ctx, sorted[best_pos]);
	}
}

/*
 * Sorts the stack using a chunk-based approach
 * The 'chunks' parameter controls how many segments to divide the data into
 * - Smaller values (3-4) work better for medium-sized inputs (20-60 elements)
 * - Larger values (5-8) work better for larger inputs (60-100+ elements)
 */
void	sort_chunks(t_context *ctx, int chunks)
{
	int	chunk_size;
	int	*sorted;
	int	c;
	int	chunk_start;
	int	chunk_end;

	if (!ctx || chunks <= 0 || ctx->size_a <= 1 || is_stack_sorted(ctx->stack_a))
		return ;
	sorted = create_sorted_array(ctx);
	if (!sorted)
		error_exit(ctx);
	chunk_size = ctx->total_size / chunks;
	remaining = ctx->total_size % chunks;
	// Sort chunk by chunk, from smallest to largest
	c = 0;
	while (c < chunks)
	{
		chunk_start = c * chunk_size;
		chunk_end = (c + 1) * chunk_size - 1;
		// If it's the last chunk, include any remaining elements
		if (c == chunks - 1)
			chunk_end += remaining;
		// Push all elements in current chunk to B
		process_chunk(ctx, sorted, chunk_start, chunk_end);
	}
	// At this point, stack B has elements in reverse sorted order
	// Push everything back to A
	while (ctx->stack_b)
		op_pa(ctx, true);
	free(sorted);
}
