/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:57:41 by yufli             #+#    #+#             */
/*   Updated: 2025/05/17 19:40:49 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_index(t_stack *s)
{
	t_stack_node	*node;
	int				min;
	int				index;
	int				i;

	node = s->top;
	min = node->data;
	index = 0;
	i = 0;
	while (node)
	{
		if (node->data < min)
		{
			min = node->data;
			index = i;
		}
		node = node->next;
		i++;
	}
	return (index);
}

static void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	index;

	index = find_min_index(a);
	if (index == 1)
		ra(a, true);
	else if (index == 2)
	{
		ra(a, true);
		ra(a, true);
	}
	else if (index == 3 && a->size == 5)
	{
		rra(a, true);
		rra(a, true);
	}
	else if (index == 4 && a->size == 5)
		rra(a, true);
	pb(a, b, true);
}

void	sort_five(t_stack *a)
{
	t_stack	*b;

	b = stack_init();
	if (!b)
		return ;
	while (a->size > 3)
		push_min_to_b(a, b);
	sort_three(a);
	while (!stack_is_empty(b))
		pa(a, b, true);
	stack_clear(b);
	free(b);
}
