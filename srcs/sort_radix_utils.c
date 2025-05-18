#include "push_swap.h"

/*
** Partition function for quick sort
*/
int partition(int *arr, int low, int high)
{
    int pivot;
    int i;
    int j;
    int temp;

    pivot = arr[high];
    i = low - 1;

    for (j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}
/*
static int partition_with_nodes(int *values, t_stack_node **nodes, int low, int high)
{
    int pivot;
    int i;
    int j;
    int temp_val;
    t_stack_node *temp_node;

    pivot = values[high];
    i = low - 1;

    for (j = low; j < high; j++)
    {
        if (values[j] <= pivot)
        {
            i++;
            // Swap values
            temp_val = values[i];
            values[i] = values[j];
            values[j] = temp_val;
            // Swap node pointers
            temp_node = nodes[i];
            nodes[i] = nodes[j];
            nodes[j] = temp_node;
        }
    }

    // Swap values
    temp_val = values[i + 1];
    values[i + 1] = values[high];
    values[high] = temp_val;
    // Swap node pointers
    temp_node = nodes[i + 1];
    nodes[i + 1] = nodes[high];
    nodes[high] = temp_node;

    return (i + 1);
}*/

/*
** Quick sort implementation for sorting the array of values
*/
void quick_sort(int *arr, int low, int high)
{
    int pivot_idx;

    if (low < high)
    {
        pivot_idx = partition(arr, low, high);
        quick_sort(arr, low, pivot_idx - 1);
        quick_sort(arr, pivot_idx + 1, high);
    }
}
/* Modified quicksort that sorts both values and node pointers
static void sort_with_nodes(int *values, t_stack_node **nodes, int low, int high)
{
    int pivot_idx;

    if (low < high)
    {
        pivot_idx = partition_with_nodes(values, nodes, low, high);
        sort_with_nodes(values, nodes, low, pivot_idx - 1);
        sort_with_nodes(values, nodes, pivot_idx + 1, high);
    }
}*/

void assign_indices(t_stack *a)
{
    int *sorted;
    int *positions;
    t_stack_node *current;
    int i;
    
    if (!a || a->size <= 1)
        return;
    
    // Create arrays for sorting and tracking
    sorted = (int *)malloc(sizeof(int) * a->size);
    positions = (int *)malloc(sizeof(int) * a->size);
    if (!sorted || !positions)
    {
        if (sorted)
		free(sorted);
        if (positions)
		free(positions);
        return;
    }
    
    // Copy values to array
    i = 0;
    current = a->top;
    while (current)
    {
        sorted[i] = current->data;
        i++;
        current = current->next;
    }
    
    // Sort the array
    quick_sort(sorted, 0, a->size - 1);
    
    // Create position mapping (handles duplicates correctly)
    for (i = 0; i < a->size; i++)
    {
        if (i > 0 && sorted[i] == sorted[i-1])
            positions[i] = positions[i-1];
        else
            positions[i] = i;
    }
    
    // Assign indices to stack nodes
    current = a->top;
    while (current)
    {
        // Find position of current->data in sorted array
        for (i = 0; i < a->size; i++)
        {
            if (sorted[i] == current->data)
            {
                current->index = positions[i];
                break;
            }
        }
        current = current->next;
    }
    
    free(sorted);
    free(positions);
}
