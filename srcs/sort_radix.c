#include "push_swap.h"

/*
** Sorts a stack using the radix sort algorithm
** This is optimized specifically for the Push Swap operations
*/
void sort_radix(t_stack *a, t_stack *b)
{
    int max_bits;
    int i;
    int j;
    int size;
    
    if (!a || !b || a->size <= 1 || is_sorted(a))
        return;
    if (a->size == 2)
    {
        sort_two(a);
        return;
    }
    if (a->size == 3)
    {
        sort_three(a);
        return;
    }
    if (a->size <= 5)
    {
        sort_five(a, b);
        return;
    }
    
    // Assign normalized indices
    assign_indices(a);
    
    // Calculate max bits needed (optimized)
    size = a->size;
    max_bits = 0;
    while ((size - 1) >> max_bits)
        max_bits++;
    
    // Sort using radix sort (least significant bit first)
    for (i = 0; i < max_bits; i++)
    {
        for (j = 0; j < size; j++)
        {
            // If the i-th bit is 0, push to stack b
            if (!((a->top->index >> i) & 1))
                pb(a, b);
            else
                ra(a);
        }
        
        // Push all elements back to stack a
        while (b->size > 0)
            pa(a, b);
    }
}
