#include "push_swap.h"

void sort_butterfly(t_stack *a, t_stack *b)
{
    int size;
    int butterfly_size;
    int i;
    int pushed;

    if (!a || !b || a->size <= 5)
    {
        if (a && a->size <= 5)
            sort_five(a, b);
        return;
    }

    // Assign indices
    assign_indices(a);

    size = a->size;
    // Calculate butterfly size (sqrt(n) is often effective)
    butterfly_size = 0;
    while (butterfly_size * butterfly_size < size)
        butterfly_size++;

    // Push elements to stack b in butterfly pattern
    pushed = 0;
    i = 0;
    while (pushed < size)
    {
        if (a->top->index <= i)
        {
            pb(a, b);
            rb(b);
            pushed++;
            i++;
        }
        else if (a->top->index <= i + butterfly_size)
        {
            pb(a, b);
            pushed++;
            i++;
        }
        else
            ra(a);
    }

    // Sort back to stack a
    while (b->size > 0)
    {
        // Find the position of the largest element in stack b
        int pos = find_largest_pos(b);

        // Rotate stack b to bring the largest element to the top
        if (pos <= b->size / 2)
        {
            while (pos > 0)
            {
                rb(b);
                pos--;
            }
        }
        else
        {
            while (pos < b->size)
            {
                rrb(b);
                pos++;
            }
        }

        pa(a, b);
    }
}
