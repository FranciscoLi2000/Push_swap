/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_multiple_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 06:43:10 by yufli             #+#    #+#             */
/*   Updated: 2025/05/18 06:43:44 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*parse_multiple_args(int argc, char **argv)
{
	t_stack	*stack;
	int		i;
	long	num;

	stack = stack_init();
	if (!stack)
		return (NULL);
	i = argc;
	while (--i > 0)
	{
		if (!is_valid_integer(argv[i], &num))
		{
			stack_clear(stack);
			free(stack);
			return (NULL);
		}
		if (!stack_push(stack, (int)num))
		{
			stack_clear(stack);
			free(stack);
			return (NULL);
		}
	}
	return (stack);
}
