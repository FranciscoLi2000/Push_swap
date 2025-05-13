#include "push_swap.h"

void	init_stacks(t_stack **a, t_stack **b)
{
	*a = (t_stack *)malloc(sizeof(t_stack));
	*b = (t_stack *)malloc(sizeof(t_stack));
	if (!*a || !*b)
		return ;
	(*a)->top = NULL;
	(*a)->bottom = NULL;
	(*a)->size = 0;
	(*b)->top = NULL;
	(*b)->bottom = NULL;
	(*b)->size = 0;
}

int	error_exit(t_stack *a, t_stack *b)
{
	write(2, "Error\n", 6);
	free_stacks(a, b);
	return (1);
}

int	clean_exit(t_stack *a, t_stack *b)
{
	free_stacks(a, b);
	return (0);
}

static void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next_node;
	if (!stack)
		return ;
	current = stack->top;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	free(stack);
}

void	free_stacks(t_stack *a, t_stack *b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
}
