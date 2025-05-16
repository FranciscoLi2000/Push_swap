/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:32:18 by yufli             #+#    #+#             */
/*   Updated: 2025/05/16 01:49:42 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*stack_init(void)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->top = NULL;
	s->size = 0;
	return (s);
}

bool	stack_push(t_stack *s, int value)
{
	t_stack_node	*new_node;

	if (!s)
		return (false);
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return (false);
	new_node->data = value;
	new_node->next = s->top;
	s->top = new_node;
	s->size++;
	return (true);
}

bool	stack_pop(t_stack *s, int *value)
{
	t_stack_node	*tmp;

	if (!s || !s->top)
		return (false);
	tmp = s->top;
	*value = tmp->data;
	s->top = s->top->next;
	free(tmp);
	s->size--;
	return (true);
}

void	stack_clear(t_stack *s)
{
	t_stack_node	*tmp;

	if (!s)
		return ;
	while (s->top)
	{
		tmp = s->top;
		s->top = s->top->next;
		free(tmp);
	}
	s->size = 0;
}
