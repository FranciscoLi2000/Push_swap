/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_single_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 03:04:08 by yufli             #+#    #+#             */
/*   Updated: 2025/05/16 03:17:14 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

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

bool	is_valid_number(const char *str, int *num)
{
	int	val;

	val = atoi(str);
	if (val > INT_MAX || val < INT_MIN)
		return (false);
	*num = val;
	return (true);
}

t_stack	*parse_single_arg(const char *arg)
{
	t_stack	*s;
	char	**tokens;
	int		i;
	int		num;

	s = stack_init();
	if (!s)
		return (NULL);
	tokens = ft_split(arg, ' ');
	if (!tokens)
	{
		free(s);
		return (NULL);
	}
	i = 0;
	while (tokens[i])
	{
		if (!is_valid_number(tokens[i], &num))
		{
			fprintf(stderr, "Error: Invalid number '%s'\n", tokens[i]);
			free_split_result(tokens);
			stack_clear(s);
			free(s);
			return (NULL);
		}
		if (!stack_push(s, num))
		{
			free_split_result(tokens);
			stack_clear(s);
			free(s);
			return (NULL);
		}
		i++;
	}
	free_split_result(tokens);
	return (s);
}
