/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:27:20 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 19:49:14 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_sort(t_stack *a, t_stack *b)
{
	if (a->size <= 3)
		small_sort(a, b);
	else if (a->size <= 5)
		five_sort(a, b);
	else
		chunk_sort(a, b);
}

void	init_stacks(t_stack **a, t_stack **b)
{
	*a = malloc(sizeof(t_stack));
	*b = malloc(sizeof(t_stack));
	if (!*a || !*b)
	{
		if (*a)
			free(*a);
		if (*b)
			free(*b);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	(*a)->numbers = NULL;
	(*a)->size = 0;
	(*b)->numbers = NULL;
	(*b)->size = 0;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	init_stacks(&a, &b);
	if (argc == 2)
	{
		if (parse_single_arg(argv[1], a, b) == 0)
			return (error_exit(a, b));
	}
	else
	{
		if (parse_multiple_args(argc, argv, a, b) == 0)
			return (error_exit(a, b));
	}
	if (is_sorted(a))
		return (clean_exit(a, b));
	execute_sort(a, b);
	free_stacks(a, b);
	return (0);
}
