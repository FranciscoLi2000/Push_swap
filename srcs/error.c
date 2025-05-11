/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 00:27:41 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 10:16:29 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
}

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->numbers)
		free(stack_a->numbers);
	if (stack_b->numbers)
		free(stack_b->numbers);
}
