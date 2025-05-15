#include "push_swap.h"

/*
 * Helper function for quicksort implementation
 */
static void	swap_int(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*
 * Quicksort partition function
 */
static int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap_int(&arr[i], &arr[j]);
		}
		j++;
	}
	swap_int(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/*
 * Recursive quicksort implementation
 */
static void	quick_sort(int *arr, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(arr, low, high);
		quick_sort(arr, low, pivot - 1);
		quick_sort(arr, pivot + 1, high);
	}
}

/*
 * Creates a sorted reference array from stack A
 * Uses quicksort (O(n log n)) for better performance
 * Returns a newly allocated array or NULL if allocation fails
 */
int	*create_sorted_array(t_context *ctx)
{
	int		*arr;
	int		i;
	t_stack	*temp;

	if (!ctx || ctx->size_a == 0)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * ctx->total_size);
	if (!arr)
		return (NULL);
	temp = ctx->stack_a;
	i = 0;
	while (temp)
	{
		arr[i++] = temp->value;
		temp = temp->next;
	}
	quick_sort(arr, 0, ctx->total_size - 1);
	return (arr);
}

/**
 * Replace actual values with their normalized positions
 * This converts the problem into sorting positions (0 to n-1)
 * instead of sorting actual values
 */
void	normalize_values(t_context *ctx, int *sorted)
{
	int		i;
	t_stack	*temp;

	if (!ctx || !sorted)
		return ;
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
			i++;
		}
		temp = temp->next;
	}
}
