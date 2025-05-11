/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_multiple_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:06:44 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 19:49:38 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fill_stack_from_argv(char **av, t_stack *a, t_stack *b, int cnt)
{
	int		i;
	long	num;

	i = 0;
	while (i < cnt)
	{
		num = ft_strtol(av[i + 1]);
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

int	parse_multiple_args(int argc, char **argv, t_stack *a, t_stack *b)
{
	int	count;
	int	i;

	count = argc - 1;
	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (0);
		i++;
	}
	if (!allocate_stacks(a, b, count))
		return (0);
	if (!fill_stack_from_argv(argv, a, b, count))
	{
		free_both_numbers(a, b);
		return (0);
	}
	a->size = count;
	b->size = 0;
	return (count);
}
