/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 06:51:24 by yufli             #+#    #+#             */
/*   Updated: 2025/05/18 06:52:53 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ra(t_stack *a)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!a || !a->top || !a->top->next)
		return ;
	last = a->top;
	while (last->next)
		last = last->next;
	first = a->top;
	a->top = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!b || !b->top || !b->top->next)
		return ;
	last = b->top;
	while (last->next)
		last = last->next;
	first = b->top;
	b->top = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (a && a->top && a->top->next)
	{
		last = a->top;
		while (last->next)
			last = last->next;
		first = a->top;
		a->top = first->next;
		first->next = NULL;
		last->next = first;
	}
	if (b && b->top && b->top->next)
	{
		last = b->top;
		while (last->next)
			last = last->next;
		first = b->top;
		b->top = first->next;
		first->next = NULL;
		last->next = first;
	}
	write(1, "rr\n", 3);
}
