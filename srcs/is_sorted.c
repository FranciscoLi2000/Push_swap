#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || stack->size <= 1)
		return (1);  // 空栈或单元素栈视为已排序
	current = stack->top;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (0);  // 发现逆序对
		current = current->next;
	}
	return (1);  // 全部元素按升序排列
}

long	ft_strtol(const char *str)
{
	long	result;
	int		sign;
	int		digit;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		digit = *str - '0';
		if (sign == 1)
		{
			if (result > (LONG_MAX - digit) / 10)
				return (LONG_MAX); // 返回溢出标记
		}
		else
		{
			if (result < (LONG_MIN + digit) / 10)
				return (LONG_MIN); // 返回溢出标记
		}
		result = result * 10 + sign * digit;
		str++;
	}
	return (result);
}
