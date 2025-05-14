#include "push_swap.h"
#include <stdio.h>

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
}
