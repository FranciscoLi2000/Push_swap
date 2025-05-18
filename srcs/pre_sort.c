#include "push_swap.h"

/*
** Pre-sorts the stack to reduce the number of operations needed
*/
void pre_sort(t_stack *a, t_stack *b)
{
    int median;

    if (!a || !b || a->size <= 5)
        return;

    // Find the median value
    median = find_median(a);

    // Push all elements smaller than the median to stack b
    while (count_elements_below_median(a, median) > 0)
    {
        if (a->top->data < median)
            pb(a, b);
        else
            ra(a);
    }

    // Sort the remaining elements in stack a
    sort_remaining(a);

    // Sort elements in stack b and push back to stack a
    sort_and_push_back(a, b);
}
