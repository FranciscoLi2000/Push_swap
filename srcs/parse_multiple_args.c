/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_multiple_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 03:11:31 by yufli             #+#    #+#             */
/*   Updated: 2025/05/16 03:14:45 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*parse_multiple_args(int argc, char **argv)
{
	t_stack	*s;
	int		i;
	int		num;

	s = stack_init();
	if (!s)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i], &num))
		{
			fprintf(stderr, "Error: Invalid number '%s'\n", argv[i]);
			stack_clear(s);
			free(s);
			return (NULL);
		}
		if (!stack_push(s, num))
		{
			stack_clear(s);
			free(s);
			return (NULL);
		}
	}
	return (s);
}
