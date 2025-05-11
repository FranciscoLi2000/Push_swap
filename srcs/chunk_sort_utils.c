/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:51:30 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 19:48:34 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_max_to_top(t_stack *b)
{
	int	max_pos;

	max_pos = find_max_position(b);
	if (max_pos <= b->size / 2)
	{
		while (max_pos > 0)
		{
			rb(b);
			max_pos--;
		}
	}
	else
	{
		while (max_pos < b->size)
		{
			rrb(b);
			max_pos++;
		}
	}
}

void	empty_stack_b(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		move_max_to_top(b);
		pa(a, b);
	}
}

void	init_chunk_params(t_stack *a, t_chunk *chunk)
{
	int	min;
	int	max;
	int	num_chunks;

	find_min_max(a, &min, &max);
	num_chunks = get_num_chunks(a->size);
	chunk->min = min;
	chunk->size = (max - min + 1) / num_chunks + 1;
	chunk->total = num_chunks;
	chunk->current = 0;
}

void	update_chunk_limits(t_chunk *chunk)
{
	chunk->start = chunk->min + chunk->current * chunk->size;
	chunk->end = chunk->min + (chunk->current + 1) * chunk->size;
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	t_chunk	chunk;

	init_chunk_params(a, &chunk);
	while (chunk.current < chunk.total)
	{
		update_chunk_limits(&chunk);
		process_chunk(a, b, chunk);
		empty_stack_b(a, b);
		chunk.current++;
	}
}
