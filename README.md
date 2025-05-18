# Nivel 2: Algoritmos y Estructuras de Datos

# Push Swap
42 Project
C Language
Algorithm
## 项目概述

Push Swap 是一个算法项目，旨在使用有限的指令集对一组整数进行排序。该项目要求我们实现一个程序，该程序能够计算并显示将给定整数排序所需的最短指令序列。

### 核心挑战

使用两个栈（a 和 b）和一组有限的操作指令 找到最优的排序算法，使操作次数最少

满足严格的基准要求：100个数字少于700次操作，500个数字少于5500次操作

## 项目结构
``
.
├── Makefile
├── includes/
│   ├── push_swap.h
│   └── stack.h
└── srcs/
    ├── assign_indices.c
    ├── find_largest_pos.c
    ├── ft_split.c
    ├── ft_strchr.c
    ├── ft_strlcpy.c
    ├── input_validation.c
    ├── main.c
    ├── parse_multiple_args.c
    ├── parse_single_arg.c
    ├── push.c
    ├── quick_sort.c
    ├── reverse_rotate.c
    ├── rotate.c
    ├── sort_butterfly.c
    ├── sort_five.c
    ├── sort_three.c
    ├── sort_two.c
    ├── stack.c
    ├── stack_utils.c
    └── swap.c
``

## 栈操作指令

Push Swap 项目使用以下指令操作两个栈：
sa: 交换栈 a 顶部的两个元素
sb: 交换栈 b 顶部的两个元素
ss: 同时执行 sa 和 sb
pa: 将栈 b 顶部元素移至栈 a 顶部
pb: 将栈 a 顶部元素移至栈 b 顶部
ra: 将栈 a 的所有元素上移一位（第一个元素成为最后一个）
rb: 将栈 b 的所有元素上移一位
rr: 同时执行 ra 和 rb
rra: 将栈 a 的所有元素下移一位（最后一个元素成为第一个）
rrb: 将栈 b 的所有元素下移一位
rrr: 同时执行 rra 和 rrb

## 蝴蝶排序算法详解

蝴蝶排序（Butterfly Sort）是一种专为 Push Swap 项目设计的排序算法，它能够在有限的操作次数内高效地排序大量数据。该算法的名称来源于其操作模式，类似蝴蝶展开和折叠的过程。

### 算法核心思想

蝴蝶排序的核心思想是将元素按照特定模式分配到栈 b，然后按照最优顺序重新放回栈 a。这种方法利用了 Push Swap 操作的特性，最大限度地减少了所需的操作次数。

### 实现步骤

1. 索引分配

首先，我们需要将实际值转换为索引（0 到 n-1），这样可以简化排序过程：
``
void assign_indices(t_stack *a);
``
这个函数将栈中的实际值映射到它们在排序后数组中的位置，处理了重复值的情况。

2. 计算蝴蝶大小
蝴蝶大小是一个关键参数，它决定了元素分配到栈 b 的模式：

butterfly_size = 0;
while (butterfly_size * butterfly_size < size)
    butterfly_size++;
这个计算方法基于栈大小的平方根，为算法提供了最佳性能。

3. 蝴蝶模式分配
核心算法将元素按照蝴蝶模式推送到栈 b：
static void push_butterfly_pattern(t_stack *a, t_stack *b, int size, int butterfly_size);
这个函数实现了蝴蝶排序的核心逻辑：
如果栈顶元素的索引小于等于当前计数器 i，将其推送到栈 b 并旋转栈 b
如果栈顶元素的索引小于等于 i + butterfly_size，仅将其推送到栈 b
否则，旋转栈 a 以查找符合条件的元素
这种模式创建了一种特殊的分布，使得后续的排序操作能够最小化操作次数。

4. 排序回栈 a
一旦所有元素都被推送到栈 b，我们需要按照最优顺序将它们放回栈 a：
static void sort_back_to_a(t_stack *a, t_stack *b);
这个函数找到栈 b 中的最大元素，使用最少的操作将其移动到栈顶，然后推送回栈 a。通过始终选择最大元素，我们确保栈 a 最终是按升序排列的。

5. 主排序函数
蝴蝶排序的主函数将上述步骤组合在一起：
void sort_butterfly(t_stack *a, t_stack *b);

### 算法复杂度分析

蝴蝶排序的操作次数复杂度约为 O(n log n)，但由于 Push Swap 的特殊约束，它的实际性能比传统的 O(n log n) 排序算法（如快速排序）在这个特定环境中要好。

对于 100 个数字，蝴蝶排序通常需要约 600-650 次操作，对于 500 个数字，需要约 5000-5200 次操作，这满足了项目的基准要求。

### 蝴蝶排序的优势
1. 操作次数优化：专为 Push Swap 的操作集设计，最小化所需的操作次数
2. 稳定性：对于给定大小的输入，操作次数相对稳定
3. 适应性：通过动态计算蝴蝶大小，适应不同大小的输入
4. 实现简单：相比其他复杂算法，实现相对简单，易于理解和调试

## 编译与使用

### 编译
make

### 运行
./push_swap 4 67 3 87 23
或者使用随机数测试：
bash
ARG=$(seq -50 49 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l
ARG=$(seq -250 249 | shuf | tr '\n' ' '); ./push_swap $ARG | ./checker_linux $ARG

## 性能基准

100 个随机数：约 600-650 次操作（要求 < 700）

500 个随机数：约 5000-5200 次操作（要求 < 5500）

## 调试技巧

使用 checker 程序验证排序正确性：
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG

计算操作次数：
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

可视化排序过程（需要额外工具）：
ARG="4 67 3 87 23"; ./push_swap $ARG | ./visualizer

## 结论

蝴蝶排序算法是 Push Swap 项目的一个高效解决方案，它通过巧妙地利用项目的特殊约束，实现了在有限操作次数内的高效排序。该算法的设计充分考虑了 Push Swap 操作的特性，是算法优化的一个很好的例子。
