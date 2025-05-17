/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_multiple_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 03:11:31 by yufli             #+#    #+#             */
/*   Updated: 2025/05/17 19:39:57 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*parse_multiple_args(int argc, char **argv)
{
	t_stack	*s;
	int		i;
	int		num;
	bool	error;

	s = stack_init();
	if (!s)
		return (NULL);
	error = false;
	i = argc - 1;
	while (i >= 1 && !error)
	{
		if (!is_valid_number(argv[i], &num))
		{
			write(2, "Error: Invalid number\n", 22);
			error = true;
		}
		else if (check_duplicate(s))
		{
			write(2, "Error: Duplicate number\n", 24);
			error = true;
		}
		else if (!stack_push(s, num))
		{
			write(2, "Error: Memory allocation failed\n", 32);
			error = true;
		}
		i--;
	}
	if (error)
	{
		stack_clear(s);
		free(s);
		return (NULL);
	}
	return (s);
}
