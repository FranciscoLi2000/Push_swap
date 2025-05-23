/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 06:28:11 by yufli             #+#    #+#             */
/*   Updated: 2025/05/18 07:34:25 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	free_split(char **split);
t_stack	*parse_single_arg(char *arg);
t_stack	*parse_multiple_args(int argc, char **argv);
bool	is_valid_integer(char *str, long *num);
void	sort(t_stack *a, t_stack *b);
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
int		find_smallest_pos(t_stack *a);
void	rotate_to_smallest(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);
int		find_largest_pos(t_stack *b);
void	quick_sort(int *arr, int low, int high);
void	assign_indices(t_stack *a);
void	sort_butterfly(t_stack *a, t_stack *b);

#endif
