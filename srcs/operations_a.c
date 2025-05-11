/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 23:46:01 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 10:11:32 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack *stack_a)
{
	int	temp;

	if (stack_a->size < 2)
		return ;
	temp = stack_a->numbers[0];
	stack_a->numbers[0] = stack_a->numbers[1];
	stack_a->numbers[1] = temp;
	ft_putstr_fd("sa\n", 1);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (stack_b->size == 0)
		return ;
	i = stack_a->size;
	while (i > 0)
	{
		stack_a->numbers[i] = stack_a->numbers[i - 1];
		i--;
	}
	stack_a->numbers[0] = stack_b->numbers[0];
	stack_a->size++;
	i = 0;
	while (i < stack_b->size - 1)
	{
		stack_b->numbers[i] = stack_b->numbers[i + 1];
		i++;
	}
	stack_b->size--;
	ft_putstr_fd("pa\n", 1);
}

void	ra(t_stack *stack_a)
{
	int	temp;
	int	i;

	if (stack_a->size < 2)
		return ;
	temp = stack_a->numbers[0];
	i = 0;
	while (i < stack_a->size - 1)
	{
		stack_a->numbers[i] = stack_a->numbers[i + 1];
		i++;
	}
	stack_a->numbers[stack_a->size - 1] = temp;
	ft_putstr_fd("ra\n", 1);
}

void	rra(t_stack *stack_a)
{
	int	temp;
	int	i;

	if (stack_a->size < 2)
		return ;
	temp = stack_a->numbers[stack_a->size - 1];
	i = stack_a->size - 1;
	while (i > 0)
	{
		stack_a->numbers[i] = stack_a->numbers[i - 1];
		i--;
	}
	stack_a->numbers[0] = temp;
	ft_putstr_fd("rra\n", 1);
}
