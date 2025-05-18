#include "push_swap.h"

/*
** Checks if the stack is nearly sorted (few elements out of place)

static bool is_nearly_sorted(t_stack *a)
{
    int inversions;
    t_stack_node *i;
    t_stack_node *j;
    
    if (!a || a->size <= 5)
        return true;
    
    inversions = 0;
    i = a->top;
    while (i)
    {
        j = i->next;
        while (j)
        {
            if (i->data > j->data)
                inversions++;
            j = j->next;
        }
        i = i->next;
    }
    
    // If less than 10% of possible pairs are inverted, consider it nearly sorted
    return (inversions <= (a->size * (a->size - 1)) / 20);
}*/

/*
** Main sorting function that dispatches to the appropriate algorithm
** based on the size of the stack
*/
void sort(t_stack *a, t_stack *b)
{
    if (!a || a->size <= 1 || is_sorted(a))
        return;
    
    if (a->size == 2)
        sort_two(a);
    else if (a->size == 3)
        sort_three(a);
    else if (a->size <= 5)
        sort_five(a, b);
    else
        sort_butterfly(a, b);  // Use radix sort for all larger stacks
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	// Parse the input arguments
	if (argc == 2 && ft_strchr(argv[1], ' '))
		a = parse_single_arg(argv[1]);
	else
		a = parse_multiple_args(argc, argv);
	// Check for errors
	if (!a || check_duplicate(a))
	{
		write(2, "Error\n", 6);
		if (a)
		{
			stack_clear(a);
			free(a);
		}
		return (1);
	}
	// Check if the stack is already sorted
	if (is_sorted(a))
	{
		stack_clear(a);
		free(a);
		return (0);
	}
	// Initialize stack b
	b = stack_init();
	if (!b)
	{
		write(2, "Error\n", 6);
		stack_clear(a);
		free(a);
		return (1);
	}
	// Sort the stack
	sort(a, b);
	// Clean up
	stack_clear(a);
	stack_clear(b);
	free(a);
	free(b);
	return (0);
}
