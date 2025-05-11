/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_single_arg_utils1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:55:41 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 19:44:16 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_and_validate(char **nums)
{
	int	count;

	count = 0;
	while (nums[count])
	{
		if (!is_valid_number(nums[count]))
			return (0);
		count++;
	}
	return (count);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
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

int	allocate_stacks(t_stack *a, t_stack *b, int count)
{
	a->numbers = (int *)malloc(sizeof(int) * count);
	if (!a->numbers)
		return (0);
	b->numbers = (int *)malloc(sizeof(int) * count);
	if (!b->numbers)
	{
		free(a->numbers);
		a->numbers = NULL;
		return (0);
	}
	return (1);
}

void	free_both_numbers(t_stack *a, t_stack *b)
{
	if (a->numbers)
	{
		free(a->numbers);
		a->numbers = NULL;
	}
	if (b->numbers)
	{
		free(b->numbers);
		b->numbers = NULL;
	}
}
