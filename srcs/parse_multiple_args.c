/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_multiple_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 03:11:31 by yufli             #+#    #+#             */
/*   Updated: 2025/05/16 14:58:17 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*parse_multiple_args(int argc, char **argv)
{
	t_stack	*s;
	int		i;
	int		num;
	bool	error;

	if (argc < 2)
	{
		fprintf(stderr, "Error: No arguments provided\n");
		return (NULL);
	}
	s = stack_init();
	if (!s)
		return (NULL);
	error = false;
	i = argc - 1;
	while (i >= 1 && !error)
	{
		if (!is_valid_number(argv[i], &num))
		{
			fprintf(stderr, "Error: Invalid number '%s'\n", argv[i]);
			error = true;
		}
		else if (check_duplicate(s, num))
		{
			fprintf(stderr, "Error: Duplicate number '%d'\n", num);
			error = true;
		}
		else if (!stack_push(s, num))
		{
			fprintf(stderr, "Error: Memory allocation failed\n");
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
