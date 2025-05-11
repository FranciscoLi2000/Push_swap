/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 23:46:01 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 19:13:21 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack *a)
{
	int	temp;

	if (a->size < 2)
		return ;
	temp = a->numbers[0];
	a->numbers[0] = a->numbers[1];
	a->numbers[1] = temp;
	ft_putstr_fd("sa\n", 1);
}

void	pa(t_stack *a, t_stack *b)
{
	int	i;

	if (b->size == 0)
		return ;
	i = a->size;
	while (i > 0)
	{
		a->numbers[i] = a->numbers[i - 1];
		i--;
	}
	a->numbers[0] = b->numbers[0];
	a->size++;
	i = 0;
	while (i < b->size - 1)
	{
		b->numbers[i] = b->numbers[i + 1];
		i++;
	}
	b->size--;
	ft_putstr_fd("pa\n", 1);
}

void	ra(t_stack *a)
{
	int	temp;
	int	i;

	if (a->size < 2)
		return ;
	temp = a->numbers[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->numbers[i] = a->numbers[i + 1];
		i++;
	}
	a->numbers[a->size - 1] = temp;
	ft_putstr_fd("ra\n", 1);
}

void	rra(t_stack *a)
{
	int	temp;
	int	i;

	if (a->size < 2)
		return ;
	temp = a->numbers[a->size - 1];
	i = a->size - 1;
	while (i > 0)
	{
		a->numbers[i] = a->numbers[i - 1];
		i--;
	}
	a->numbers[0] = temp;
	ft_putstr_fd("rra\n", 1);
}
