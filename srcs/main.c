/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 06:38:45 by yufli             #+#    #+#             */
/*   Updated: 2025/05/18 06:42:44 by yufli            ###   ########.fr       */
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
		sort_five(a, b);
	else
		sort_butterfly(a, b);
}

static int	handle_error(t_stack *a, t_stack *b)
{
	write(2, "Error\n", 6);
	if (a)
	{
		stack_clear(a);
		free(a);
	}
	if (b)
	{
		stack_clear(b);
		free(b);
	}
	return (1);
}

static int	exit_clean(t_stack *a, t_stack *b)
{
	if (a)
	{
		stack_clear(a);
		free(a);
	}
	if (b)
	{
		stack_clear(b);
		free(b);
	}
	return (0);
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
		return (handle_error(a, NULL));
	if (is_sorted(a))
		return (exit_clean(a, NULL));
	b = stack_init();
	if (!b)
		return (handle_error(a, NULL));
	sort(a, b);
	return (exit_clean(a, b));
}
