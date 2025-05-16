/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 00:15:56 by yufli             #+#    #+#             */
/*   Updated: 2025/05/16 02:01:47 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	reverse_rotate(t_stack *s)
{
	t_stack_node	*second_last;
	t_stack_node	*last;

	if (!s || !s->top || !s->top->next)
		return ;
	second_last = s->top;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	last->next = s->top;
	s->top = last;
	second_last->next = NULL;
}

void	rra(t_stack *a, bool print)
{
	reverse_rotate(a);
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *b, bool print)
{
	reverse_rotate(b);
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print)
		write(1, "rrr\n", 4);
}
