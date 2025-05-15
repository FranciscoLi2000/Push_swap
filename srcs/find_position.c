#include "push_swap.h"

/*
 * Find minimum value in stack
 */
int	find_min(t_stack *stack)
{
	int	min;

	if (!stack)
		return (INT_MAX);
	min = stack->value;
	stack = stack->next;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

/*
 * Find maximum value in stack
 */
int	find_max(t_stack *stack)
{
	int	max;

	if (!stack)
		return (INT_MIN);
	max = stack->value;
	stack = stack->next;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

/*
 * Find position of a value in stack
 * Returns -1 if not found
 */
int	find_position(t_stack *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->value == value)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (0);
}

/**
 * Calculate how many moves needed to bring a position to the top
 * Returns the minimum number of moves (using rotate or reverse rotate)
 */
int	calculate_moves(int position, int stack_size)
{
	if (position <= stack_size / 2)
		return (position);
	else
		return (stack_size - position);
}
