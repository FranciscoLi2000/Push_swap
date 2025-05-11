/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 00:02:42 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 10:12:15 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sb(t_stack *stack_b)
{
	int	temp;

	if (stack_b->size < 2)
		return ;
	temp = stack_b->numbers[0];
	stack_b->numbers[0] = stack_b->numbers[1];
	stack_b->numbers[1] = temp;
	ft_putstr_fd("sb\n", 1);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (stack_a->size == 0)
		return ;
	i = stack_b->size;
	while (i > 0)
	{
		stack_b->numbers[i] = stack_b->numbers[i - 1];
		i--;
	}
	stack_b->numbers[0] = stack_a->numbers[0];
	stack_b->size++;
	i = 0;
	while (i < stack_a->size - 1)
	{
		stack_a->numbers[i] = stack_a->numbers[i + 1];
		i++;
	}
	stack_a->size--;
	ft_putstr_fd("pb\n", 1);
}

void	rb(t_stack *stack_b)
{
	int	temp;
	int	i;

	if (stack_b->size < 2)
		return ;
	temp = stack_b->numbers[0];
	i = 0;
	while (i < stack_b->size - 1)
	{
		stack_b->numbers[i] = stack_b->numbers[i + 1];
		i++;
	}
	stack_b->numbers[stack_b->size - 1] = temp;
	ft_putstr_fd("rb\n", 1);
}

void	rrb(t_stack *stack_b)
{
	int	temp;
	int	i;

	if (stack_b->size < 2)
		return ;
	temp = stack_b->numbers[stack_b->size - 1];
	i = stack_b->size - 1;
	while (i > 0)
	{
		stack_b->numbers[i] = stack_b->numbers[i - 1];
		i--;
	}
	stack_b->numbers[0] = temp;
	ft_putstr_fd("rrb\n", 1);
}
