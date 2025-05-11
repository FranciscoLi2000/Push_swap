/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 00:18:57 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 10:14:21 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	count_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((size - 1) >> max_bits != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bits;
	int	size;
	int	i;
	int	j;
	int	num;

	size = stack_a->size;
	max_bits = count_max_bits(size);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			num = stack_a->numbers[0];
			if (((num >> i) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			j++;
		}
		while (stack_b->size > 0)
			pa(stack_a, stack_b);
		i++;
	}
}
