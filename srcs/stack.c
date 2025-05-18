/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 07:21:38 by yufli             #+#    #+#             */
/*   Updated: 2025/05/18 07:23:09 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

bool	stack_push(t_stack *s, int value)
{
	t_stack_node	*new_node;

	if (!s)
		return (false);
	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		return (false);
	new_node->data = value;
	new_node->index = 0;
	new_node->next = s->top;
	s->top = new_node;
	s->size++;
	return (true);
}

bool	stack_pop(t_stack *s, int *value)
{
	t_stack_node	*temp;

	if (!s || !s->top)
		return (false);
	*value = s->top->data;
	temp = s->top;
	s->top = s->top->next;
	free(temp);
	s->size--;
	return (true);
}

void	stack_clear(t_stack *s)
{
	t_stack_node	*current;
	t_stack_node	*next;

	if (!s)
		return ;
	current = s->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	s->top = NULL;
	s->size = 0;
}
