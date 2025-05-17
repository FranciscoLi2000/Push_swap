/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_single_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 03:04:08 by yufli             #+#    #+#             */
/*   Updated: 2025/05/17 19:50:41 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

bool	is_valid_number(const char *str, int *num)
{
	char	*end;
	long	val;

	if (!str || !*str)
		return (false);
	val = strtol(str, &end, 10);
	if (*end != '\0' || val > INT_MAX || val < INT_MIN)
		return (false);
	*num = (int)val;
	return (true);
}

static void	free_split_result(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

t_stack	*parse_single_arg(const char *arg)
{
	t_stack	*s;
	char	**tokens;
	bool	error;
	int		num;
	int		i;

	if (!arg || !*arg)
	{
		fprintf(stderr, "Error: Empty input\n");
		return (NULL);
	}
	s = stack_init();
	if (!s)
		return (NULL);
	tokens = ft_split(arg, ' ');
	if (!tokens)
	{
		stack_clear(s);
		free(s);
		return (NULL);
	}
	error = false;
	i = 0;
	while (tokens[i] && !error)
	{
		if (!is_valid_number(tokens[i], &num))
		{
			fprintf(stderr, "Error: Invalid number '%s'\n", tokens[i]);
			error = true;
		}
		else if (check_duplicate(s))
		{
			fprintf(stderr, "Error: Duplicate number '%d'\n", num);
			error = true;
		}
		else if (!stack_push(s, num))
		{
			fprintf(stderr, "Error: Memory allocation failed\n");
			error = true;
		}
		i++;
	}
	free_split_result(tokens);
	if (error)
	{
		stack_clear(s);
		free(s);
		return (NULL);
	}
	return (s);
}
