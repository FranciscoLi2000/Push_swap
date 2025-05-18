/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_single_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 06:44:46 by yufli             #+#    #+#             */
/*   Updated: 2025/05/18 06:46:05 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*free_all_and_return_null(t_stack *stack, char **split)
{
	free_split(split);
	stack_clear(stack);
	free(stack);
	return (NULL);
}

t_stack	*parse_single_arg(char *arg)
{
	t_stack	*stack;
	char	**split;
	int		i;
	long	num;

	stack = stack_init();
	if (!stack)
		return (NULL);
	split = ft_split(arg, ' ');
	if (!split)
	{
		free(stack);
		return (NULL);
	}
	i = 0;
	while (split[i])
		i++;
	while (--i >= 0)
	{
		if (!is_valid_integer(split[i], &num)
			|| !stack_push(stack, (int)num))
			return (free_all_and_return_null(stack, split));
	}
	free_split(split);
	return (stack);
}
