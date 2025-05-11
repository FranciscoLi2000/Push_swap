/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:36:04 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 21:27:14 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int	*numbers;
	int	size;
}	t_stack;

typedef struct s_chunk
{
	int	min;
	int	size;
	int	total;
	int	current;
	int	start;
	int	end;
}	t_chunk;

void	find_min_max(t_stack *a, int *min, int *max);
int		get_num_chunks(int size);
void	process_chunk(t_stack *a, t_stack *b, t_chunk chunk);
int		find_max_position(t_stack *b);
void	move_max_to_top(t_stack *b);
void	empty_stack_b(t_stack *a, t_stack *b);
void	init_chunk_params(t_stack *a, t_chunk *chunk);
void	update_chunk_limits(t_chunk *chunk);
void	chunk_sort(t_stack *a, t_stack *b);
int		error_exit(t_stack *a, t_stack *b);
int		find_min_position(t_stack *a);
void	move_min_to_top(t_stack *a);
void	five_sort(t_stack *a, t_stack *b);
void	free_stacks(t_stack *a, t_stack *b);
int		clean_exit(t_stack *a, t_stack *b);
int		is_sorted(t_stack *a);
void	execute_sort(t_stack *a, t_stack *b);
void	init_stacks(t_stack **a, t_stack **b);
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
int		fill_stack_from_argv(char **av, t_stack *a, t_stack *b, int cnt);
int		parse_multiple_args(int argc, char **argv, t_stack *a, t_stack *b);
int		parse_single_arg(char *str, t_stack *a, t_stack *b);
int		count_and_validate(char **nums);
int		is_valid_number(char *str);
int		allocate_stacks(t_stack *a, t_stack *b, int count);
void	free_both_numbers(t_stack *a, t_stack *b);
int		fill_stack_a(char **nums, t_stack *a, t_stack *b, int count);
long	ft_strtol(char *str);
int		has_duplicate(t_stack *a, int num, int pos);
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	small_sort(t_stack *a, t_stack *b);
void	free_split(char **split);

#endif
