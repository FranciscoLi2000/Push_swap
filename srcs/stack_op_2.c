#include "push_swap.h"

/**
 * Gets the last node in the stack
 * Returns NULL if the stack is empty
 */
t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/*
 * Gets the number of nodes in the stack
 */
int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

/*
 * Checks if the stack is sorted in ascending order
 * Returns true if sorted, false otherwise
 */
bool	is_stack_sorted(t_stack *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

/*
 * Frees all nodes in the stack and sets the stack pointer to NULL
 */
void	stack_free(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}
