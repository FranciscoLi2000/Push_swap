/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 00:27:41 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 02:31:16 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
}

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->numbers)
		free(stack_a->numbers);
	if (stack_b->numbers)
		free(stack_b->numbers);
}
