#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		parse_result;

	if (argc == 1)
		return (0);  // 没有参数直接退出
	// 初始化堆栈结构
	init_stacks(&a, &b);
	if (!a || !b)
		return (error_exit(a, b));
	if (argc == 2)
		parse_result = parse_single_arg(argv[1], a, b);
	else
		parse_result = parse_multiple_args(argc, argv, a, b);
	if (parse_result == 0)
		return (error_exit(a, b));
	if (is_sorted(a))
	{
		clean_exit(a, b);
		return (0);
	}
	// 执行排序
	execute_sort(a, b);
	// 清理资源
	free_stacks(a, b);
	return (0);
}
