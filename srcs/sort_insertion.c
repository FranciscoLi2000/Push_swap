/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:24:04 by yufli             #+#    #+#             */
/*   Updated: 2025/05/17 19:40:27 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_insert_position_b(t_stack *b, int value)
{
	t_stack_node	*node;
	int				index;

	index = 0;
	node = b->top;
	while (node)
	{
		if (value > node->data)
			return (index);
		index++;
		node = node->next;
	}
	return (index);
}

static void	rotate_b_to_position(t_stack *b, int pos, bool print)
{
	int	i;

	if (pos <= b->size / 2)
	{
		i = 0;
		while (i++ < pos)
			rb(b, print);
	}
	else
	{
		i = 0;
		while (i++ < b->size - pos)
			rrb(b, print);
	}
}

void	sort_insertion(t_stack *a, t_stack *b)
{
	int	value;
	int	position;

	while (!stack_is_empty(a))
	{
		value = a->top->data;
		position = find_insert_position_b(b, value);
		rotate_b_to_position(b, pos, true);
		pb(a, b, true);
	}
	while (!stack_is_empty(b))
		pa(a, b, true);
}
