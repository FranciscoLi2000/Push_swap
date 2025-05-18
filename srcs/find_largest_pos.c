/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_largest_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 07:05:31 by yufli             #+#    #+#             */
/*   Updated: 2025/05/18 07:06:08 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_largest_pos(t_stack *b)
{
	t_stack_node	*current;
	int				largest;
	int				pos;
	int				largest_pos;

	if (!b || !b->top)
		return (-1);
	current = b->top;
	largest = current->data;
	pos = 0;
	largest_pos = 0;
	while (current)
	{
		if (current->data > largest)
		{
			largest = current->data;
			largest_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (largest_pos);
}
