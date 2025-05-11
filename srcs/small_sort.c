/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 00:15:32 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 02:24:31 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(t_stack *stack)
{
	if (stack->numbers[0] > stack->numbers[1])
		sa(stack);
}

void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->numbers[0];
	b = stack->numbers[1];
	c = stack->numbers[2];
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
}

static int	find_min_index(t_stack *stack)
{
	int	min;
	int	min_index;
	int	i;

	min = stack->numbers[0];
	min_index = 0;
	i = 1;
	while (i < stack->size)
	{
		if (stack->numbers[i] < min)
		{
			min = stack->numbers[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

void	sort_five_or_less(t_stack *stack_a, t_stack *stack_b)
{
	int	min_idx;
	int	push_count;

	push_count = stack_a->size - 3;
	while (push_count > 0)
	{
		min_idx = find_min_index(stack_a);
		if (min_idx <= stack_a->size / 2)
		{
			while (min_idx > 0)
			{
				ra(stack_a);
				min_idx--;
			}
		}
		else
		{
			while (min_idx < stack_a->size)
			{
				rra(stack_a);
				min_idx++;
			}
		}
		pb(stack_a, stack_b);
		push_count--;
	}
	sort_three(stack_a);
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}
