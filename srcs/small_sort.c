/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:07:43 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 21:28:20 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->numbers[0] > a->numbers[1])
		sa(a);
}

void	sort_three(t_stack *a)
{
	if (a->numbers[0] > a->numbers[1] && a->numbers[1] < a->numbers[2]
		&& a->numbers[0] < a->numbers[2])
		sa(a);
	else if (a->numbers[0] > a->numbers[1] && a->numbers[1] > a->numbers[2])
	{
		sa(a);
		rra(a);
	}
	else if (a->numbers[0] > a->numbers[1] && a->numbers[1] < a->numbers[2]
		&& a->numbers[0] > a->numbers[2])
		ra(a);
	else if (a->numbers[0] < a->numbers[1] && a->numbers[1] > a->numbers[2]
		&& a->numbers[0] < a->numbers[2])
	{
		sa(a);
		ra(a);
	}
	else if (a->numbers[0] < a->numbers[1] && a->numbers[1] > a->numbers[2]
		&& a->numbers[0] > a->numbers[2])
		rra(a);
}

void	small_sort(t_stack *a, t_stack *b)
{
	(void)b;
	if (a->size <= 1)
		return ;
	if (a->size == 2)
	{
		if (a->numbers[0] > a->numbers[1])
			sa(a);
		return ;
	}
	sort_three(a);
}
