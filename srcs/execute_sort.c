#include "push_swap.h"

void	execute_sort(t_stack *a, t_stack *b)
{
	int	chunk_size;

	if (a->size <= 1)
		return ; // 无需排序
	// 小规模数据专用排序
	if (a->size <= 5)
	{
		small_sort(a, b);
		return ;
	}
	// 中大规模数据排序
	chunk_size = calculate_chunk_size(a->size);
	chunk_sort(a, b, chunk_size);
}
