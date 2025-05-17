/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:08:54 by yufli             #+#    #+#             */
/*   Updated: 2025/05/17 19:34:56 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>

typedef struct s_stack_node
{
	int					data;
	int					index;
	struct s_stack_node	*next;
}	t_stack_node;

typedef struct s_stack
{
	t_stack_node	*top;
	int				size;
}	t_stack;

t_stack	*stack_init(void);
bool	stack_push(t_stack *s, int value);
bool	stack_pop(t_stack *s, int *value);
void	stack_clear(t_stack *s);
bool	stack_is_empty(const t_stack *s);
int		stack_size(const t_stack *s);
void	print_stack(const t_stack *s, const char *name);
bool	check_duplicate(const t_stack *s);
bool	is_sorted(const t_stack *s);
void	pa(t_stack *a, t_stack *b, bool print);
void	pb(t_stack *a, t_stack *b, bool print);
void	sa(t_stack *a, bool print);
void	sb(t_stack *b, bool print);
void	ss(t_stack *a, t_stack *b, bool print);
void	ra(t_stack *a, bool print);
void	rb(t_stack *b, bool print);
void	rr(t_stack *a, t_stack *b, bool print);
void	rra(t_stack *a, bool print);
void	rrb(t_stack *b, bool print);
void	rrr(t_stack *a, t_stack *b, bool print);
char	**ft_split(char const *s, char c);
t_stack	*parse_single_arg(const char *arg);
t_stack	*parse_multiple_args(int argc, char **argv);
bool	is_valid_number(const char *str, int *num);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
