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
		sort_insertion(a);
	else if (a->size <= 60)
		sort_chunks(a, b, 3);
	else if (a->size <= 150)
		sort_chunks(a, b, 8);
	else
		sort_radix(a, b);
}

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	if (argc < 2)
	{
		printf("Usage: %s <num1 num2 ...> OR %s \"1 2 3\"\n", argv[0], argv[0]);
		return (1);
	}
	if (argc == 2 && ft_strchr(argv[1], ' '))
		a = parse_single_arg(argv[1]);
	else
		a = parse_multiple_args(argc, argv);

	if (!a)
	{
		fprintf(stderr, "Error: Failed to create stack\n");
		return (1);
	}

	if (is_sorted(a))
	{
		printf("Stack is already sorted, nothing to do.\n");
		print_stack(a, "A");
		stack_clear(a);
		free(a);
		return (0);
	}

	b = stack_init();
	if (!b)
	{
		fprintf(stderr, "Error: Failed to create stack B\n");
		stack_clear(a);
		free(a);
		return (1);
	}
	print_stack(a, "A before sort");
	print_stack(b, "B before sort");

	selection_sort(a, b);

	print_stack(a, "A after sort");
	print_stack(b, "B after sort");

	stack_clear(a);
	stack_clear(b);
	free(a);
	free(b);

	return (0);
}
