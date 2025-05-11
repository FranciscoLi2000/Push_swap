/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 00:30:15 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 02:33:49 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc == 1)
		return (0);
	if (!parse_arguments(argc, argv, &stack_a, &stack_b))
	{
		print_error();
		return (1);
	}
	if (stack_a.size == 0)
	{
		free_stacks(&stack_a, &stack_b);
		return (0);
	}
	if (!ft_is_sorted(&stack_a))
		sort_stack(&stack_a, &stack_b);
	free_stacks(&stack_a, &stack_b);
	return (0);
}
