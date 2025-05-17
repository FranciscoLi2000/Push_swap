/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:59:13 by yufli             #+#    #+#             */
/*   Updated: 2025/05/17 19:53:56 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_in_sorted(int value, int *sorted, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	find_max(t_stack *s)
{
	t_stack_node	*node;
	int				max;

	if (!s || !s->top)
		return (0);
	node = s->top;
	max = node->data;
	while (node)
	{
		if (node->data > max)
			max = node->data;
		node = node->next;
	}
	return (max);
}

int	find_position(t_stack *s, int value)
{
	t_stack_node	*node;
	int				pos;

	if (!s || !s->top)
		return (-1);
	node = s->top;
	pos = 0;
	while (node)
	{
		if (node->data == value)
			return (pos);
		node = node->next;
		pos++;
	}
	return (-1);
}
/*
void	rotate_b_to_position(t_stack *b, int pos, bool print)
{
	if (!b || pos < 0 || pos >= b->size)
		return ;
	if (pos <= b->size / 2)
	{
		while (pos--)
			rb(b, print);
	}
	else
	{
		pos = b->size - pos;
		while (pos--)
			rrb(b, print);
	}
}*/
