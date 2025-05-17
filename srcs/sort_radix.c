/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 19:10:51 by yufli             #+#    #+#             */
/*   Updated: 2025/05/17 19:52:38 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_indices(t_stack *a)
{
	t_stack_node	*node;
	int				*array;
	int				i;

	array = stack_to_array(a);
	if (!array)
		return ;
	sort_array(array, a->size);
	node = a->top;
	while (node)
	{
		i = 0;
		while (i < a->size)
		{
			if (node->data == array[i])
			{
				node->index = i;
				break ;
			}
			i++;
		}
		node = node->next;
	}
	free(array);
}

void	sort_radix(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	assign_indices(a);
	size = a->size;
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((a->top->index >> i) & 1) == 0)
				pb(a, b, true);
			else
				ra(a, true);
			j++;
		}
		while (!stack_is_empty(b))
			pa(a, b, true);
		i++;
	}
}
