#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <limits.h>

typedef struct s_node
{
	int		value;      // 存储整数值
	struct s_node	*prev;    // 前一个节点
	struct s_node	*next;    // 后一个节点
}	t_node;

typedef struct s_stack
{
	t_node	*top;           // 栈顶指针
	t_node	*bottom;        // 栈底指针
	int	size;           // 栈的大小
}	t_stack;

void	execute_sort(t_stack *a, t_stack *b);  // 执行排序的主函数
int		is_sorted(t_stack *a);                // 检查栈是否已排序
int		clean_exit(t_stack *a, t_stack *b);    // 清理资源并正常退出
int	error_exit(t_stack *a, t_stack *b);    // 错误处理并退出

void	init_stacks(t_stack **a, t_stack **b); // 初始化两个堆栈
void	free_stacks(t_stack *a, t_stack *b);   // 释放堆栈内存
void	free_split(char **split);              // 释放分割后的字符串数组

int		parse_single_arg(char *str, t_stack *a, t_stack *b); // 解析单个字符串参数
int		parse_multiple_args(int argc, char **argv, t_stack *a, t_stack *b); // 解析多个参数
int		is_valid_number(char *str);           // 检查是否为有效数字
long	ft_strtol(char *str);                 // 字符串转长整型(自定义实现)
int		check_duplicate(t_stack *a, int num, int pos); // 检查是否有重复数字

void	sa(t_stack *a);       // 交换栈a顶部两个元素
void	sb(t_stack *b);       // 交换栈b顶部两个元素
void	ss(t_stack *a, t_stack *b); // 同时交换两个栈的顶部元素
void	pa(t_stack *a, t_stack *b); // 从b栈顶推一个元素到a栈顶
void	pb(t_stack *a, t_stack *b); // 从a栈顶推一个元素到b栈顶
void	ra(t_stack *a);       // 旋转栈a(顶部元素移到底部)
void	rb(t_stack *b);       // 旋转栈b(顶部元素移到底部)
void	rr(t_stack *a, t_stack *b); // 同时旋转两个栈
void	rra(t_stack *a);      // 反向旋转栈a(底部元素移到顶部)
void	rrb(t_stack *b);      // 反向旋转栈b(底部元素移到顶部)
void	rrr(t_stack *a, t_stack *b); // 同时反向旋转两个栈

void	small_sort(t_stack *a, t_stack *b);    // 小规模数据排序(2-3个元素)
void	five_sort(t_stack *a, t_stack *b);     // 5个元素的排序
void	chunk_sort_100(t_stack *a, t_stack *b); // 100个元素的分块排序
void	chunk_sort_500(t_stack *a, t_stack *b); // 500个元素的分块排序

void	normalize_stack(t_stack *a);           // 标准化栈中的值(可选)
int		find_min_position(t_stack *a);         // 找到最小值的位置
int		find_max_position(t_stack *b);         // 找到最大值的位置
void	sort_three(t_stack *a);                // 专门排序3个元素的函数

#endif
