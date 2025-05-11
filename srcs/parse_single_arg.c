/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_single_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:10:39 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 19:43:41 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_single_arg(char *str, t_stack *a, t_stack *b)
{
	char	**nums;
	int		count;

	nums = ft_split(str, ' ');
	if (!nums || !nums[0])
	{
		if (nums)
			free_split(nums);
		return (0);
	}
	count = count_and_validate(nums);
	if (count <= 0 || !allocate_stacks(a, b, count)
		|| !fill_stack_a(nums, a, b, count))
	{
		free_split(nums);
		return (0);
	}
	a->size = count;
	b->size = 0;
	free_split(nums);
	return (count);
}
