/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 00:27:16 by yufli             #+#    #+#             */
/*   Updated: 2025/05/16 15:19:17 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

bool	stack_is_empty(const t_stack *s)
{
	return (!s || !s->top);
}

int	stack_size(const t_stack *s)
{
	if (!s)
		return (0);
	return (s->size);
}

bool	check_duplicate(const t_stack *s)
{
	t_stack_node	*node;

	node = s->top;
	while (node)
	{
		if (node->data == node->next->data)
			return (true);
		node = node->next;
	}
	return (false);
}

bool	is_sorted(const t_stack *s)
{
	t_stack_node	*curr;

	if (!s || !s->top)
		return (true);
	curr = s->top;
	while (curr->next)
	{
		if (curr->data > curr->next->data)
			return (false);
		curr = curr->next;
	}
	return (true);
}

void	print_stack(const t_stack *s, const char *name)
{
	t_stack_node	*current;

	printf("%s: ", name);
	if (!s || !s->top)
	{
		printf("(empty)\n");
		return ;
	}
	current = s->top;
	while (current)
	{
		printf("%d", current->data);
		if (current->next)
			printf(" -> ");
		current = current->next;
	}
	printf(" (size: %d)\n", s->size);
}
