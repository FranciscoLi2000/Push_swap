#include "push_swap.h"

void	sort_chunks(t_stack *a, t_stack *b, int num_chunks)
{
	int	*arr;
	int	total;

	arr = stack_to_array(a);
	total = a->size;
	if (!arr)
		return ;
	sort_array(arr, total);
	push_chunks(a, b, arr, total, num_chunks);
	push_back_to_a(a, b);
	free(arr);
}
