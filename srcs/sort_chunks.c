#include "push_swap.h"

/**
 * Checks if stack A contains any elements that belong to the current chunk
 */
bool	has_chunk_elements(t_context *ctx, int *sorted, int start, int end)
{
	t_stack	*temp;
	int		i;

	temp = ctx->stack_a;
	while (temp)
	{
		i = start;
		while (i <= end)
		{
			if (temp->value == sorted[i])
				return (true);
			i++;
		}
		temp = temp->next;
	}
	return (false);
}

/**
 * Finds the position of the element in the current chunk that
 * requires the fewest operations to move to the top of stack A
 */
int	find_best_chunk_element(t_context *ctx, int *sorted, int start, int end)
{
	int		best_pos;
	int		best_cost;
	int		pos;
	int		cost;
	t_stack	*temp;
	int		i;

	best_pos = -1;
	best_cost = INT_MAX;
	pos = 0;
	temp = ctx->stack_a;
	while (temp)
	{
		i = start;
		while (i <= end)
		{
			if (temp->value == sorted[i])
			{
				cost = calculate_moves(pos, ctx->size_a);
				if (cost < best_cost)
				{
					best_cost = cost;
					best_pos = pos;
				}
				break ;
			}
			i++;
		}
		temp = temp->next;
		pos++;
	}
	return (best_pos);
}

/**
 * Process a single chunk
 * Moves all elements within the given value range from stack A to stack B
 */
static void	process_chunk(t_context *ctx, int *sorted, int start, int end)
{
	int	best_pos;

	while (has_chunk_elements(ctx, sorted, start, end))
	{
		best_pos = find_best_chunk_element(ctx, sorted, start, end);
		move_element_to_top(ctx, best_pos);
		op_pb(ctx, true);
	}
}

/**
 * Sorts the stack using a chunk-based approach
 * The 'chunks' parameter controls how many segments to divide the data into
 */
void	sort_chunks(t_context *ctx, int chunks)
{
	int		*sorted;
	int		chunk_size;
	int		c;
	int		chunk_start;
	int		chunk_end;
	int		remaining;

	if (!ctx || chunks <= 0 || ctx->size_a <= 1 || is_stack_sorted(ctx->stack_a))
		return ;
	sorted = create_sorted_array(ctx);
	if (!sorted)
		error_exit(ctx);
	chunk_size = ctx->total_size / chunks;
	remaining = ctx->total_size % chunks;
	c = 0;
	while (c < chunks)
	{
		chunk_start = c * chunk_size;
		chunk_end = (c + 1) * chunk_size - 1;
		if (c == chunks - 1)
			chunk_end += remaining;
		process_chunk(ctx, sorted, chunk_start, chunk_end);
		c++;
	}
	while (ctx->stack_b)
		op_pa(ctx, true);
	free(sorted);
}
