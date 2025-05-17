/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 00:40:51 by yufli             #+#    #+#             */
/*   Updated: 2025/05/16 15:46:02 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *a, t_stack *b)
{
	if (!a || a->size <= 1 || is_sorted(a))
		return ;
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_five(a);
	else if (a->size <= 20)
		sort_insertion(a, b);
	else if (a->size <= 60)
		sort_chunks(a, b, 3);
	else if (a->size <= 150)
		sort_chunks(a, b, 8);
	else
		sort_radix(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	if (argc == 2 && ft_strchr(argv[1], ' '))
		a = parse_single_arg(argv[1]);
	else
		a = parse_multiple_args(argc, argv);
	if (!a || check_duplicate(a))
	{
		write(2, "Error\n", 6);
		stack_clear(a);
		free(a);
		return (1);
	}
	if (is_sorted(a))
	{
		write(2, "Error\n", 6);
		stack_clear(a);
		free(a);
		return (0);
	}
	b = stack_init();
	if (!b)
	{
		write(2, "Error\n", 6);
		stack_clear(a);
		free(a);
		return (1);
	}
	sort(a, b);
	stack_clear(a);
	stack_clear(b);
	free(a);
	free(b);
	return (0);
}
