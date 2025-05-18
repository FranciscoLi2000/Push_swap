/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 07:23:37 by yufli             #+#    #+#             */
/*   Updated: 2025/05/18 07:24:59 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

bool	stack_is_empty(const t_stack *s)
{
	return (!s || s->size == 0);
}

int	stack_size(const t_stack *s)
{
	if (!s)
		return (0);
	return (s->size);
}

bool	is_sorted(const t_stack *s)
{
	t_stack_node	*current;

	if (!s || !s->top || s->size <= 1)
		return (true);
	current = s->top;
	while (current->next)
	{
		if (current->data > current->next->data)
			return (false);
		current = current->next;
	}
	return (true);
}

bool	check_duplicate(const t_stack *s)
{
	t_stack_node	*i;
	t_stack_node	*j;

	if (!s || !s->top)
		return (false);
	i = s->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->data == j->data)
				return (true);
			j = j->next;
		}
		i = i->next;
	}
	return (false);
}
