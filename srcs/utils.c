/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 02:29:56 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 10:15:37 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->numbers[i] > stack->numbers[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(t_stack *stack, int num, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (stack->numbers[i] == num)
			return (1);
		i++;
	}
	return (0);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	if (stack_a->size <= 1)
		return ;
	else if (stack_a->size == 2)
		sort_two(stack_a);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size <= 5)
		sort_five_or_less(stack_a, stack_b);
	else
	{
		convert_to_indices(stack_a);
		radix_sort(stack_a, stack_b);
	}
}
