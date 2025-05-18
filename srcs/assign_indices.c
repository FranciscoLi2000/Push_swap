/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_indices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 07:07:01 by yufli             #+#    #+#             */
/*   Updated: 2025/05/18 07:13:40 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_array_from_stack(t_stack *a, int *arr)
{
	t_stack_node	*current;
	int				i;

	current = a->top;
	i = 0;
	while (current)
	{
		arr[i++] = current->data;
		current = current->next;
	}
}

static void	fill_positions(int *sorted, int *positions, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i > 0 && sorted[i] == sorted[i - 1])
			positions[i] = positions[i - 1];
		else
			positions[i] = i;
		i++;
	}
}

static void	assign_indices_to_stack(t_stack *a, int *sorted, int *positions)
{
	t_stack_node	*current;
	int				i;

	current = a->top;
	while (current)
	{
		i = 0;
		while (i < a->size)
		{
			if (sorted[i] == current->data)
			{
				current->index = positions[i];
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

void	assign_indices(t_stack *a)
{
	int	*sorted;
	int	*positions;

	if (!a || a->size <= 1)
		return ;
	sorted = (int *)malloc(sizeof(int) * a->size);
	positions = (int *)malloc(sizeof(int) * a->size);
	if (!sorted || !positions)
	{
		free(sorted);
		free(positions);
		return ;
	}
	fill_array_from_stack(a, sorted);
	quick_sort(sorted, 0, a->size - 1);
	fill_positions(sorted, positions, a->size);
	assign_indices_to_stack(a, sorted, positions);
	free(sorted);
	free(positions);
}
