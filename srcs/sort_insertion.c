#include "push_swap.h"
#include <stdio.h>

/*
 * Implements an insertion sort algorithm for push_swap
 * This is efficient for small to medium sets (6-20 elements)
 *
 * Strategy:
 * 1. Find the smallest element in stack A
 * 2. Move it to the top of stack A using optimal rotations
 * 3. Push it to stack B
 * 4. Repeat until stack A is empty
 * 5. Push everything back from B to A (they'll be in sorted order)
 */
void	sort_insertion(t_context *ctx)
{
	int	min_value;
	int	min_pos;
	int	size;

	if (!ctx || ctx->size_a <= 1)
		return ;
}
