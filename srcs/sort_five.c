/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 07:02:11 by yufli             #+#    #+#             */
/*   Updated: 2025/05/18 07:04:16 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest_pos(t_stack *a)
{
	t_stack_node	*current;
	int				smallest;
	int				pos;
	int				smallest_pos;

	if (!a || !a->top)
		return (-1);
	current = a->top;
	smallest = current->data;
	pos = 0;
	smallest_pos = 0;
	while (current)
	{
		if (current->data < smallest)
		{
			smallest = current->data;
			smallest_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (smallest_pos);
}

void	rotate_to_smallest(t_stack *a)
{
	int	pos;
	int	size;

	pos = find_smallest_pos(a);
	if (pos == -1)
		return ;
	size = a->size;
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ra(a);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rra(a);
			pos++;
		}
	}
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	elements_to_push;

	if (!a || !b || a->size <= 3)
	{
		if (a && a->size <= 3)
			sort_three(a);
		return ;
	}
	elements_to_push = a->size - 3;
	while (elements_to_push > 0)
	{
		rotate_to_smallest(a);
		pb(a, b);
		elements_to_push--;
	}
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}
