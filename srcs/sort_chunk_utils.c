#include "push_swap.h"

/*
** Returns the minimum of two integers
*/
int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
/*
** Finds minimum and maximum values in the stack
*/
void find_min_max(t_stack *s, int *min, int *max)
{
    t_stack_node *current;

    if (!s || !s->top)
    {
        *min = 0;
        *max = 0;
        return;
    }

    *min = s->top->data;
    *max = s->top->data;
    current = s->top->next;

    while (current)
    {
        if (current->data < *min)
            *min = current->data;
        if (current->data > *max)
            *max = current->data;
        current = current->next;
    }
}

/*
** Partitions the array for quicksort
*
int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] <= pivot)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		j++;
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return (i + 1);
}
*/
/*
** Pushes elements from stack a to stack b if they are in the specified range
** Returns the number of elements pushed
*/
int push_chunk_elements(t_stack *a, t_stack *b, int min_val, int max_val, int *pushed)
{
    int elements_pushed = 0;
    int size = a->size;
    int i;

    for (i = 0; i < size; i++)
    {
        if (a->top->data >= min_val && a->top->data <= max_val)
        {
            pb(a, b);
            (*pushed)++;
            elements_pushed++;
        }
        else
        {
            ra(a);
        }

        // Break if we've pushed enough elements or stack a is empty
        if (*pushed >= size || stack_is_empty(a))
            break;
    }

    return elements_pushed;
}


/*
** Implements the quicksort algorithm
*
void	quick_sort(int *arr, int low, int high)
{
	int	pivot_idx;

	if (low < high)
	{
		pivot_idx = partition(arr, low, high);
		quick_sort(arr, low, pivot_idx - 1);
		quick_sort(arr, pivot_idx + 1, high);
	}
}*/
/*
** Sorts elements from stack b back to stack a
*/
void sort_back_to_a(t_stack *a, t_stack *b)
{
    int pos;

    while (!stack_is_empty(b))
    {
        // Find the position of the largest element in stack b
        pos = find_largest_pos(b);

        // Rotate stack b to bring the largest element to the top
        if (pos <= b->size / 2)
        {
            // Rotate forward
            while (pos > 0)
            {
                rb(b);
                pos--;
            }
        }
        else
        {
            // Rotate backward
            while (pos < b->size)
            {
                rrb(b);
                pos++;
            }
        }

        // Push the largest element to stack a
        pa(a, b);
    }
}

/*
** Creates a sorted array of the values in the stack
** Returns a pointer to the array, or NULL if allocation fails
*/
int	*create_sorted_array(t_stack *a)
{
	int				*arr;
	t_stack_node	*current;
	int				i;

	if (!a)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * a->size);
	if (!arr)
		return (NULL);
	// Copy stack values to array
	current = a->top;
	i = 0;
	while (current)
	{
		arr[i] = current->data;
		current = current->next;
		i++;
	}
	// Sort the array
	quick_sort(arr, 0, a->size - 1);
	return (arr);
}
/*
** Final correction to ensure the stack is sorted
*/
void correct_sort(t_stack *a)
{
    int min_pos;

    if (!a || a->size <= 1)
        return;

    // Find the position of the minimum element
    min_pos = find_smallest_pos(a);

    // Rotate to bring the minimum element to the top
    if (min_pos <= a->size / 2)
    {
        // Rotate forward
        while (min_pos > 0)
        {
            ra(a);
            min_pos--;
        }
    }
    else
    {
        // Rotate backward
        while (min_pos < a->size)
        {
            rra(a);
            min_pos++;
        }
    }
}
