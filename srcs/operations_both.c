/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_both.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 00:11:04 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 19:18:36 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ss(t_stack *a, t_stack *b)
{
	int	temp;

	if (a->size < 2 || b->size < 2)
		return ;
	temp = a->numbers[0];
	a->numbers[0] = a->numbers[1];
	a->numbers[1] = temp;
	temp = b->numbers[0];
	b->numbers[0] = b->numbers[1];
	b->numbers[1] = temp;
	ft_putstr_fd("ss\n", 1);
}

void	rr(t_stack *a, t_stack *b)
{
	int	temp;
	int	i;

	if (a->size < 2 || b->size < 2)
		return ;
	temp = a->numbers[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->numbers[i] = a->numbers[i + 1];
		i++;
	}
	a->numbers[a->size - 1] = temp;
	temp = b->numbers[0];
	i = 0;
	while (i < b->size - 1)
	{
		b->numbers[i] = b->numbers[i + 1];
		i++;
	}
	b->numbers[b->size - 1] = temp;
	ft_putstr_fd("rr\n", 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	int	temp;
	int	i;

	if (a->size < 2 || b->size < 2)
		return ;
	temp = a->numbers[a->size - 1];
	i = a->size - 1;
	while (i > 0)
	{
		a->numbers[i] = a->numbers[i - 1];
		i--;
	}
	a->numbers[0] = temp;
	temp = b->numbers[b->size - 1];
	i = b->size - 1;
	while (i > 0)
	{
		b->numbers[i] = b->numbers[i - 1];
		i--;
	}
	b->numbers[0] = temp;
	ft_putstr_fd("rrr\n", 1);
}
