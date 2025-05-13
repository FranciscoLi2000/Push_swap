#include "push_swap.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i]) // 只有符号的情况
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicate(t_stack *stack, int num)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->value == num)
			return (1);
		current = current->next;
	}
	return (0);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	add_node_to_stack(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	new_node->value = value;
	new_node->prev = NULL;
	new_node->next = stack->top;
	if (stack->top)
		stack->top->prev = new_node;
	else
		stack->bottom = new_node; // 第一个节点
	stack->top = new_node;
	stack->size++;
}

int	parse_single_arg(char *str, t_stack *a, t_stack *b)
{
	char	**split;
	int		i;
	long	num;

	split = ft_split(str, ' ');
	if (!split)
		return (error_exit(a, b), 0); // 分割失败
	i = 0;
	while (split[i])
	{
		if (!is_valid_number(split[i]))
			return (free_split(split), error_exit(a, b), 0);
		num = ft_strtol(split[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (free_split(split), error_exit(a, b), 0);
		if (check_duplicate(a, (int)num))
			return (free_split(split), error_exit(a, b), 0);
		add_node_to_stack(a, (int)num);
		i++;
	}
	free_split(split);
	return (1); // 成功解析
}
