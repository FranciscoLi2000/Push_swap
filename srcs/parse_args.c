/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 00:49:02 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 02:40:18 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* srcs/parse_args.c */
#include "../includes/push_swap.h"

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

static int	count_numbers(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_whitespace(str[i]))
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && !is_whitespace(str[i]))
				i++;
		}
	}
	return (count);
}

static char	*get_next_number(char *str, char **num_end)
{
	while (*str && is_whitespace(*str))
		str++;
	if (!*str)
		return (NULL);
	*num_end = str;
	while (**num_end && !is_whitespace(**num_end))
		(*num_end)++;
	return (str);
}

static int	parse_number(char *start, char *end, int *result)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (*start == '-' || *start == '+')
	{
		if (*start == '-')
			sign = -1;
		start++;
	}
	if (start == end || *start < '0' || *start > '9')
		return (0);
	while (start < end)
	{
		if (*start < '0' || *start > '9')
			return (0);
		num = num * 10 + (*start - '0');
		if ((sign == 1 && num > INT_MAX)
		|| (sign == -1 && (long unsigned int)num > 2147483648UL))
			return (0);
		start++;
	}
	*result = (int)(num * sign);
	return (1);
}

static int	fill_stack_from_string(char *arg, t_stack *stack_a)
{
	int		i;
	char	*ptr;
	char	*num_end;
	int		num;

	i = 0;
	ptr = arg;
	while (i < stack_a->size)
	{
		ptr = get_next_number(ptr, &num_end);
		if (!ptr)
			break ;
		if (!parse_number(ptr, num_end, &num))
			return (0);
		if (i > 0 && check_duplicates(stack_a, num, i))
			return (0);
		stack_a->numbers[i++] = num;
		ptr = num_end;
	}
	return (1);
}

static int	parse_string_arg(char *arg, t_stack *stack_a, t_stack *stack_b)
{
	int		count;

	count = count_numbers(arg);
	if (count == 0)
		return (0);
	stack_a->size = count;
	stack_a->numbers = (int *)malloc(sizeof(int) * count);
	if (!stack_a->numbers)
		return (0);
	stack_b->numbers = (int *)malloc(sizeof(int) * count);
	if (!stack_b->numbers)
	{
		free(stack_a->numbers);
		return (0);
	}
	stack_b->size = 0;
	if (!fill_stack_from_string(arg, stack_a))
	{
		free(stack_a->numbers);
		free(stack_b->numbers);
		return (0);
	}
	return (1);
}

static int	parse_multiple_args(int argc, char **argv,
		t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	long	num;

	stack_a->size = argc - 1;
	stack_a->numbers = (int *)malloc(sizeof(int) * stack_a->size);
	if (!stack_a->numbers)
		return (0);
	stack_b->size = 0;
	stack_b->numbers = (int *)malloc(sizeof(int) * stack_a->size);
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
		num = ft_strtol(argv[i + 1]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		if (i > 0 && check_duplicates(stack_a, (int)num, i))
			return (0);
		stack_a->numbers[i++] = (int)num;
	}
	return (1);
}

int	parse_arguments(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	if (argc < 2)
		return (0);
	if (argc == 2 && count_numbers(argv[1]) > 1)
		return (parse_string_arg(argv[1], stack_a, stack_b));
	else
		return (parse_multiple_args(argc, argv, stack_a, stack_b));
}
