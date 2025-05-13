#include "push_swap.h"

int	parse_multiple_args(int argc, char **argv, t_stack *a, t_stack *b)
{
	int		i;
	long	num;

	i = 1; // 跳过程序名(argv[0])
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (error_exit(a, b), 0);
		num = ft_strtol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (error_exit(a, b), 0);
		if (check_duplicate(a, (int)num))
			return (error_exit(a, b), 0);
		add_node_to_stack(a, (int)num);
		i++;
	}
	return (1); // 成功解析
}
