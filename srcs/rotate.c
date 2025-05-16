/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 00:02:56 by yufli             #+#    #+#             */
/*   Updated: 2025/05/16 01:56:17 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	rotate(t_stack *s)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!s || !s->top || !s->top->next)
		return ;
	first = s->top;
	last = s->top;
	while (last->next)
		last = last->next;
	s->top = first->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_stack *a, bool print)
{
	rotate(a);
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack *b, bool print)
{
	rotate(b);
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b, bool print)
{
	rotate(a);
	rotate(b);
	if (print)
		write(1, "rr\n", 3);
}
