/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 06:24:14 by yufli             #+#    #+#             */
/*   Updated: 2025/05/18 06:27:56 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack_node
{
	struct s_stack_node	*next;
	int					data;
	int					index;
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
bool	is_sorted(const t_stack *s);
bool	check_duplicate(const t_stack *s);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
