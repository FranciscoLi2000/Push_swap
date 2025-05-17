/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:08:54 by yufli             #+#    #+#             */
/*   Updated: 2025/05/17 19:45:03 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_five(t_stack *a);
void	sort_insertion(t_stack *a, t_stack *b);
int		*stack_to_array(t_stack *a);
void	sort_array(int *arr, int size);
int		find_index_in_sorted(int value, int *sorted, int size);
int		find_max(t_stack *s);
int		find_position(t_stack *s, int value);
void	rotate_b_to_position(t_stack *b, int pos, bool print);
void	push_chunks(t_stack *a, t_stack *b, int *sorted, int total, int chunks);
void	sort_chunks(t_stack *a, t_stack *b, int num_chunks);
void	sort_radix(t_stack *a, t_stack *b);
void	sort(t_stack *a, t_stack *b);

#endif
