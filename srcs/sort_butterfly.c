/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_butterfly.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 06:53:59 by yufli             #+#    #+#             */
/*   Updated: 2025/05/18 06:59:01 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_butterfly_pattern(
	t_stack *a,
	t_stack *b,
	int size,
	int butterfly_size
)
{
	int	i;
	int	pushed;

	i = 0;
	pushed = 0;
	while (pushed < size)
	{
		if (a->top->index <= i)
		{
			pb(a, b);
			rb(b);
			pushed++;
			i++;
		}
		else if (a->top->index <= i + butterfly_size)
		{
			pb(a, b);
			pushed++;
			i++;
		}
		else
			ra(a);
	}
}

static void	sort_back_to_a(t_stack *a, t_stack *b)
{
	int	pos;

	while (b->size > 0)
	{
		pos = find_largest_pos(b);
		if (pos <= b->size / 2)
		{
			while (pos-- > 0)
				rb(b);
		}
		else
		{
			while (pos++ < b->size)
				rrb(b);
		}
		pa(a, b);
	}
}

void	sort_butterfly(t_stack *a, t_stack *b)
{
	int	size;
	int	butterfly_size;

	if (!a || !b || a->size <= 5)
	{
		if (a && a->size <= 5)
			sort_five(a, b);
		return ;
	}
	assign_indices(a);
	size = a->size;
	butterfly_size = 0;
	while (butterfly_size * butterfly_size < size)
		butterfly_size++;
	push_butterfly_pattern(a, b, size, butterfly_size);
	sort_back_to_a(a, b);
}
