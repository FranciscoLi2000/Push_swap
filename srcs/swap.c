/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 07:25:26 by yufli             #+#    #+#             */
/*   Updated: 2025/05/18 07:27:43 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	swap_top_two(t_stack *stack)
{
	int	temp;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	temp = stack->top->data;
	stack->top->data = stack->top->next->data;
	stack->top->next->data = temp;
	temp = stack->top->index;
	stack->top->index = stack->top->next->index;
	stack->top->next->index = temp;
}

void	sa(t_stack *a)
{
	swap_top_two(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	swap_top_two(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap_top_two(a);
	swap_top_two(b);
	write(1, "ss\n", 3);
}
