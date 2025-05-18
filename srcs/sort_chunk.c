#include "push_swap.h"

/*
** Sorts a stack using the chunk method with improved correctness
** The stack is divided into 'num_chunks' chunks
*/
void	sort_chunks(t_stack *a, t_stack *b, int num_chunks)
{
	int	min;
	int	max;
	int	range;
	int	chunk_size;
	int	i;
	int	pushed;
	int	chunk_min;
	int	chunk_max;

	if (!a || !b || a->size <= 20)
	{
		if (a && a->size <= 20)
			sort_insertion(a, b);
		return ;
	}
	// Find min and max values in stack a
	find_min_max(a, &min, &max);
	range = max - min + 1;
	chunk_size = range / num_chunks;
	if (range % num_chunks != 0)
		chunk_size++;
	// Push elements to stack b in chunks
	i = 0;
	while (i < num_chunks)
	{
		pushed = 0;
		while (pushed < chunk_size && !stack_is_empty(a))
		{
			// Calculate current chunk boundaries
			chunk_min = min + i * chunk_size;
			chunk_max = min + (i + 1) * chunk_size - 1;
			if (i == num_chunks - 1)
				chunk_max = max; // Ensure the last chunk includes max
			// Find and push elements in current chunk
			if (push_chunk_elements(a, b, chunk_min, chunk_max, &pushed) == 0)
				break ; // No more elements in this chunk
		}
		i++;
	}
	// Sort elements back from stack b to stack a
	sort_back_to_a(a, b);
	// Verify the stack is sorted
	if (!is_sorted(a))
		// Final correction if needed
		correct_sort(a);
}
