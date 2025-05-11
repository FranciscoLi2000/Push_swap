/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 00:49:02 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 10:10:55 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	parse_split_numbers(char **split, t_stack *a, t_stack *b)
{
	int		i;
	long	num;

	i = 0;
	while (split[i])
		i++;
	a->size = i;
	a->numbers = (int *)ft_calloc(i, sizeof(int));
	if (!a->numbers)
		return (0);
	b->numbers = (int *)ft_calloc(i, sizeof(int));
	if (!b->numbers)
	{
		free(a->numbers);
		return (0);
	}
	b->size = 0;
	i = -1;
	while (split[++i])
	{
		if (!is_valid_number(split[i]))
			return (0);
		num = ft_atoi(split[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		if (i > 0 && check_duplicates(a, (int)num, i))
			return (0);
		a->numbers[i] = (int)num;
	}
	return (1);
}

static int	free_split(char **split, int ret)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (ret);
}

static int	parse_string_arg(char *arg, t_stack *a, t_stack *b)
{
	char	**split;
	int		result;

	split = ft_split(arg, ' ');
	if (!split)
		return (0);
	if (!split[0])
		return (free_split(split, 0));
	result = parse_split_numbers(split, a, b);
	if (!result)
	{
		if (a->numbers)
			free(a->numbers);
		if (b->numbers)
			free(b->numbers);
		return (free_split(split, 0));
	}
	return (free_split(split, 1));
}

static int	parse_multiple_args(int argc, char **argv,
		t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	long	num;

	stack_a->size = argc - 1;
	stack_a->numbers = (int *)ft_calloc(stack_a->size, sizeof(int));
	if (!stack_a->numbers)
		return (0);
	stack_b->size = 0;
	stack_b->numbers = (int *)ft_calloc(stack_a->size, sizeof(int));
	if (!stack_b->numbers)
	{
		free(stack_a->numbers);
		return (0);
	}
	i = 0;
	while (i < stack_a->size)
	{
		if (!is_valid_number(argv[i + 1]))
			return (0);
		num = ft_atoi(argv[i + 1]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		if (i > 0 && check_duplicates(stack_a, (int)num, i))
			return (0);
		stack_a->numbers[i++] = (int)num;
	}
	return (1);
}

int	parse_arguments(int argc, char **argv, t_stack *a, t_stack *b)
{
	if (argc < 2)
		return (0);
	if (argc == 2 && ft_strchr(argv[1], ' '))
		return (parse_string_arg(argv[1], a, b));
	else
		return (parse_multiple_args(argc, argv, a, b));
}
