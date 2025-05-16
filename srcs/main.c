/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 00:40:51 by yufli             #+#    #+#             */
/*   Updated: 2025/05/16 03:23:48 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	main(int argc, char **argv) 
{
	t_stack	*a;

	if (argc < 2)
	{
		printf("Usage:\n");
		printf("  Single argument: %s \"1 2 3\"\n", argv[0]);
		printf("  Multiple arguments: %s 1 2 3\n", argv[0]);
		return (1);
	}
	a = stack_init();
	if (argc == 2 && ft_strchr(argv[1], ' '))
		a = parse_single_arg(argv[1]);
	else
		a = parse_multiple_args(argc, argv);
	if (!a)
		return (1);
	print_stack(a, "Stack A");
	stack_clear(a);
	free(a);
	return (0);
}
