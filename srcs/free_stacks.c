/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:19:50 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 15:06:51 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_stack *a, t_stack *b)
{
	if (a)
	{
		if (a->numbers)
			free(a->numbers);
		free(a);
	}
	if (b)
	{
		if (b->numbers)
			free(b->numbers);
		free(b);
	}
}

int	clean_exit(t_stack *a, t_stack *b)
{
	free_stacks(a, b);
	return (0);
}

int	is_sorted(t_stack *a)
{
	int	i;

	if (a->size <= 1)
		return (1);
	i = 0;
	while (i < a->size - 1)
	{
		if (a->numbers[i] > a->numbers[i + 1])
			return (0);
		i++;
	}
	return (1);
}
