/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 00:02:42 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 19:16:01 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sb(t_stack *b)
{
	int	temp;

	if (b->size < 2)
		return ;
	temp = b->numbers[0];
	b->numbers[0] = b->numbers[1];
	b->numbers[1] = temp;
	ft_putstr_fd("sb\n", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	int	i;

	if (a->size == 0)
		return ;
	i = b->size;
	while (i > 0)
	{
		b->numbers[i] = b->numbers[i - 1];
		i--;
	}
	b->numbers[0] = a->numbers[0];
	b->size++;
	i = 0;
	while (i < a->size - 1)
	{
		a->numbers[i] = a->numbers[i + 1];
		i++;
	}
	a->size--;
	ft_putstr_fd("pb\n", 1);
}

void	rb(t_stack *b)
{
	int	temp;
	int	i;

	if (b->size < 2)
		return ;
	temp = b->numbers[0];
	i = 0;
	while (i < b->size - 1)
	{
		b->numbers[i] = b->numbers[i + 1];
		i++;
	}
	b->numbers[b->size - 1] = temp;
	ft_putstr_fd("rb\n", 1);
}

void	rrb(t_stack *b)
{
	int	temp;
	int	i;

	if (b->size < 2)
		return ;
	temp = b->numbers[b->size - 1];
	i = b->size - 1;
	while (i > 0)
	{
		b->numbers[i] = b->numbers[i - 1];
		i--;
	}
	b->numbers[0] = temp;
	ft_putstr_fd("rrb\n", 1);
}
