/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_single_arg_utils2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:00:07 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 21:28:01 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fill_stack_a(char **nums, t_stack *a, t_stack *b, int count)
{
	int		i;
	long	num;

	i = 0;
	while (i < count)
	{
		num = ft_strtol(nums[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			free_both_numbers(a, b);
			return (0);
		}
		if (has_duplicate(a, (int)num, i))
		{
			free_both_numbers(a, b);
			return (0);
		}
		a->numbers[i] = (int)num;
		i++;
	}
	return (1);
}

long	ft_strtol(char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

int	has_duplicate(t_stack *a, int num, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (a->numbers[i] == num)
			return (1);
		i++;
	}
	return (0);
}
