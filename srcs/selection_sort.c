/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:24:04 by yufli             #+#    #+#             */
/*   Updated: 2025/05/16 15:27:07 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(const t_stack *s)
{
	t_stack_node	*node = s->top;
	int	min_val;
	int	min_pos = 0;
	int	pos = 0;

	if (!node)
		return (-1);
	min_val = node->data;
	while (node)
	{
		if (node->data < min_val)
		{
			min_val = node->data;
			min_pos = pos;
		}
		node = node->next;
		pos++;
	}
	return (min_pos);
}

void	move_min_to_top(t_stack *s)
{
	int	min_pos = find_min_pos(s);
	int	size = stack_size(s);

	if (min_pos == -1)
		return ;
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(s, true);
	}
	else
	{
		int	rotations = size - min_pos;
		while (rotations-- > 0)
			rra(s, true);
	}
}

void	selection_sort(t_stack *a, t_stack *b)
{
	while (!stack_is_empty(a))
	{
		move_min_to_top(a);
		pb(a, b, true);
	}
	while (!stack_is_empty(b))
		pa(a, b, true);
}
