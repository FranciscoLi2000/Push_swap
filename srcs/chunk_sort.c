/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:43:08 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 19:39:59 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min_max(t_stack *a, int *min, int *max)
{
	int	i;

	*min = a->numbers[0];
	*max = a->numbers[0];
	i = 1;
	while (i < a->size)
	{
		if (a->numbers[i] < *min)
			*min = a->numbers[i];
		if (a->numbers[i] > *max)
			*max = a->numbers[i];
		i++;
	}
}

int	get_num_chunks(int size)
{
	if (size <= 100)
		return (5);
	else
		return (11);
}

void	process_chunk(t_stack *a, t_stack *b, t_chunk chunk)
{
	int	i;
	int	j;

	j = 0;
	i = a->size;
	while (j < i)
	{
		if (a->numbers[0] >= chunk.start && a->numbers[0] < chunk.end)
			pb(a, b);
		else
			ra(a);
		j++;
	}
}

int	find_max_position(t_stack *b)
{
	int	max;
	int	max_pos;
	int	i;

	max = b->numbers[0];
	max_pos = 0;
	i = 1;
	while (i < b->size)
	{
		if (b->numbers[i] > max)
		{
			max = b->numbers[i];
			max_pos = i;
		}
		i++;
	}
	return (max_pos);
}
