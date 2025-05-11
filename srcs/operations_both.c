/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_both.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 00:11:04 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 10:12:56 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;

	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	temp = stack_a->numbers[0];
	stack_a->numbers[0] = stack_a->numbers[1];
	stack_a->numbers[1] = temp;
	temp = stack_b->numbers[0];
	stack_b->numbers[0] = stack_b->numbers[1];
	stack_b->numbers[1] = temp;
	ft_putstr_fd("ss\n", 1);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;
	int	i;

	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	temp = stack_a->numbers[0];
	i = 0;
	while (i < stack_a->size - 1)
	{
		stack_a->numbers[i] = stack_a->numbers[i + 1];
		i++;
	}
	stack_a->numbers[stack_a->size - 1] = temp;
	temp = stack_b->numbers[0];
	i = 0;
	while (i < stack_b->size - 1)
	{
		stack_b->numbers[i] = stack_b->numbers[i + 1];
		i++;
	}
	stack_b->numbers[stack_b->size - 1] = temp;
	ft_putstr_fd("rr\n", 1);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;
	int	i;

	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	temp = stack_a->numbers[stack_a->size - 1];
	i = stack_a->size - 1;
	while (i > 0)
	{
		stack_a->numbers[i] = stack_a->numbers[i - 1];
		i--;
	}
	stack_a->numbers[0] = temp;
	temp = stack_b->numbers[stack_b->size - 1];
	i = stack_b->size - 1;
	while (i > 0)
	{
		stack_b->numbers[i] = stack_b->numbers[i - 1];
		i--;
	}
	stack_b->numbers[0] = temp;
	ft_putstr_fd("rrr\n", 1);
}
