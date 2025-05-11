/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 00:22:14 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 02:32:22 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	*create_copy(t_stack *stack)
{
	int	*copy;
	int	i;

	copy = (int *)malloc(sizeof(int) * stack->size);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < stack->size)
	{
		copy[i] = stack->numbers[i];
		i++;
	}
	return (copy);
}

static void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	find_index(int *sorted, int value, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	convert_to_indices(t_stack *stack)
{
	int	*sorted;
	int	*original;
	int	i;

	sorted = create_copy(stack);
	if (!sorted)
		return ;
	original = create_copy(stack);
	if (!original)
	{
		free(sorted);
		return ;
	}
	sort_array(sorted, stack->size);
	i = 0;
	while (i < stack->size)
	{
		stack->numbers[i] = find_index(sorted, original[i], stack->size);
		i++;
	}
	free(sorted);
	free(original);
}
