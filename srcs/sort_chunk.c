/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:56:49 by yufli             #+#    #+#             */
/*   Updated: 2025/05/17 19:45:43 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_array(t_stack *a)
{
	int				*arr;
	t_stack_node	*node;
	int				i;

	if (!a || a->size == 0)
		return (NULL);
	arr = malloc(sizeof(int) * a->size);
	if (!arr)
		return (NULL);
	node = a->top;
	i = 0;
	while (node)
	{
		arr[i++] = node->data;
		node = node->next;
	}
	return (arr);
}

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	push_chunks(t_stack *a, t_stack *b, int *sorted, int total, int chunks)
{
	int	i;
	int	chunk_size;
	int	chunk_limit;
	int	rank;

	i = 0;
	chunk_size = total / chunks;
	chunk_limit = chunk_size;
	while (i < total)
	{
		rank = find_index_in_sorted(a->top->data, sorted, total);
		if (rank < chunk_limit)
		{
			pb(a, b, true);
			if (rank < chunk_limit - chunk_size / 2)
				rb(b, true);
			i++;
		}
		else
			ra(a, true);
		if (i >= chunk_limit && chunk_limit < total)
			chunk_limit += chunk_size;
	}
}

static void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	max;
	int	pos;

	while (!stack_is_empty(b))
	{
		max = find_max(b);
		pos = find_position(b, max);
		rotate_b_to_position(b, pos, true);
		pa(a, b, true);
	}
}

void	sort_chunks(t_stack *a, t_stack *b, int num_chunks)
{
	int	*arr;
	int	total;

	arr = stack_to_array(a);
	total = a->size;
	if (!arr)
		return ;
	sort_array(arr, total);
	push_chunks(a, b, arr, total, num_chunks);
	push_back_to_a(a, b);
	free(arr);
}
