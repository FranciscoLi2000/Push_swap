#include "push_swap.h"
#include <stdio.h>

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

	if (!ctx || chunks <= 0)
		return ;
	chunk_size = ctx->total_size / chunks;
	sorted = create_sorted_array(ctx);
	if (!sorted)
		error_exit(ctx);
	// Replace actual values with their normalized positions
	normalize_values(ctx, sorted);
	// Sort chunk by chunk, from smallest to largest
	c = 0;
	while (c < chunks)
	{
		chunk_start = c * chunk_size;
		chunk_end = (c + 1) * chunk_size - 1;
		// If it's the last chunk, include any remaining elements
		if (c == chunks - 1)
			chunk_end = ctx->total_size - 1;
		// Push all elements in current chunk to B
		while (has_chunk_elements(ctx, chunk_start, chunk_end))
		{
			move_best_chunk_element_to_top(ctx, chunk_start, chunk_end);
			op_pb(ctx, true);
		}
		c++;
	}
	// At this point, stack B has elements in reverse sorted order
	// Push everything back to A
	while (ctx->stack_b)
		op_pa(ctx, true);
	free(sorted);
}
