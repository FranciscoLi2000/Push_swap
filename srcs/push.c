/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 06:46:41 by yufli             #+#    #+#             */
/*   Updated: 2025/05/18 06:47:44 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	pa(t_stack *a, t_stack *b)
{
	t_stack_node	*temp;

	if (!a || !b || !b->top)
		return ;
	temp = b->top;
	b->top = b->top->next;
	b->size--;
	temp->next = a->top;
	a->top = temp;
	a->size++;
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	t_stack_node	*temp;

	if (!a || !b || !a->top)
		return ;
	temp = a->top;
	a->top = a->top->next;
	a->size--;
	temp->next = b->top;
	b->top = temp;
	b->size++;
	write(1, "pb\n", 3);
}
