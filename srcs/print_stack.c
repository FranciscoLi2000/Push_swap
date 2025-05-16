/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 00:27:16 by yufli             #+#    #+#             */
/*   Updated: 2025/05/16 03:22:50 by yufli            ###   ########.fr       */
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
