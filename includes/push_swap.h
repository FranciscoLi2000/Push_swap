/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 23:37:53 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 02:27:14 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack	/* 定义栈结构 */
{
	int	*numbers;	/* 存储整数的数组 */
	int	size;		/* 栈中元素数量 */
}	t_stack;

/* 基本操作函数 */
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

/* 排序函数 */
void	sort_stack(t_stack *stack_a, t_stack *stack_b);
void	sort_two(t_stack *stack);
void	sort_three(t_stack *stack);
void	sort_five_or_less(t_stack *stack_a, t_stack *stack_b);
void	radix_sort(t_stack *stack_a, t_stack *stack_b);

/* 辅助函数 */
int		ft_is_sorted(t_stack *stack);
void	convert_to_indices(t_stack *stack);
long	ft_strtol(const char *str);
int		is_valid_number(char *str);
int		check_duplicates(t_stack *stack, int num, int index);
void	print_error(void);
void	free_stacks(t_stack *stack_a, t_stack *stack_b);
int		parse_arguments(int argc, char **argv, t_stack *a, t_stack *b);

#endif
