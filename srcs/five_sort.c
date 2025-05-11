/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:11:28 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 19:48:54 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_position(t_stack *a)
{
	int	min;
	int	min_pos;
	int	i;

	min = a->numbers[0];
	min_pos = 0;
	i = 1;
	while (i < a->size)
	{
		if (a->numbers[i] < min)
		{
			min = a->numbers[i];
			min_pos = i;
		}
		i++;
	}
	return (min_pos);
}

void	move_min_to_top(t_stack *a)
{
	int	min_pos;

	min_pos = find_min_position(a);
	if (min_pos <= a->size / 2)
	{
		while (min_pos > 0)
		{
			ra(a);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < a->size)
		{
			rra(a);
			min_pos++;
		}
	}
}

void	five_sort(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		move_min_to_top(a);
		pb(a, b);
	}
	small_sort(a, b);
	while (b->size > 0)
		pa(a, b);
}
