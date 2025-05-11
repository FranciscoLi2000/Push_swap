#!/bin/bash

# 定义颜色代码
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
MAGENTA='\033[0;35m'
CYAN='\033[0;36m'
BOLD='\033[1m'
RESET='\033[0m'

# 定义符号
CHECK_MARK="${GREEN}✓${RESET}"
CROSS_MARK="${RED}✗${RESET}"
ARROW="${YELLOW}→${RESET}"

# 程序路径
PUSH_SWAP="./push_swap"
CHECKER="./checker_linux"

# 打印标题
print_header() {
    echo -e "\n${BOLD}${BLUE}=== $1 ===${RESET}"
}

# 打印子标题
print_subheader() {
    echo -e "\n${BOLD}${CYAN}== $1 ==${RESET}"
}

# 打印测试项
print_test() {
    echo -e "${MAGENTA}▶ $1:${RESET}"
}

# 打印结果
print_result() {
    local status=$1
    local message=$2
    if [ "$status" == "pass" ]; then
        echo -e "  ${CHECK_MARK} $message"
    else
        echo -e "  ${CROSS_MARK} $message"
    fi
}

# 打印操作数据
print_operations() {
    local ops=$1
    local limit=$2
    echo -e "  ${ARROW} 操作次数: ${BOLD}$ops${RESET}"
    
    if [ -z "$limit" ]; then
        return
    fi
    
    if [ "$ops" -le "$limit" ]; then
        echo -e "  ${CHECK_MARK} 在限制范围内 (≤$limit)"
    else
        echo -e "  ${CROSS_MARK} 超出限制 (>$limit)"
    fi
}

# 执行测试并打印结果
run_test() {
    local description=$1
    local args=$2
    local limit=$3
    
    print_test "$description"
    
    # 运行push_swap并计算操作次数
    local ops=$($PUSH_SWAP $args | wc -l | tr -d ' ')
    
    # 检查排序结果
    local result="$($PUSH_SWAP $args | $CHECKER $args 2>/dev/null)"
    
    if [ "$result" == "OK" ] || [ -z "$result" -a "$ops" -eq 0 ]; then
        print_result "pass" "排序正确"
    else
        print_result "fail" "排序失败: $result"
    fi
    
    print_operations "$ops" "$limit"
    echo ""
}

# 执行错误测试
run_error_test() {
    local description=$1
    local args=$2
    local expected_error=$3
    
    print_test "$description"
    
    # 运行push_swap并捕获错误输出
    local error=$($PUSH_SWAP $args 2>&1 1>/dev/null)
    
    if [[ "$error" == *"$expected_error"* ]]; then
        print_result "pass" "正确显示错误信息"
    else
        print_result "fail" "错误信息不正确: $error"
    fi
    echo ""
}

# 开始测试
echo -e "${BOLD}${GREEN}===== Push_swap 测试脚本 =====${RESET}"
echo -e "${YELLOW}开始时间: $(date)${RESET}"

# 基本功能测试
print_header "基本功能测试"

print_subheader "空输入和单一元素"
run_test "无参数" "" ""
run_test "单一元素" "42" ""

print_subheader "已排序数据"
run_test "3个数字 (已排序)" "1 2 3" ""
run_test "5个数字 (已排序)" "1 2 3 4 5" ""
run_test "10个数字 (已排序)" "1 2 3 4 5 6 7 8 9 10" ""

print_subheader "逆序数据"
run_test "3个数字 (逆序)" "3 2 1" "3"
run_test "5个数字 (逆序)" "5 4 3 2 1" "12"

# 错误处理测试
print_header "错误处理测试"

run_error_test "非数字输入" "1 2 a 3" "Error"
run_error_test "超出整数范围" "2147483648" "Error"
run_error_test "负超出整数范围" "-2147483649" "Error"
run_error_test "重复数字" "1 2 2 3" "Error"

# 小规模数据测试
print_header "小规模数据测试"

print_subheader "2个数字"
run_test "需要交换" "2 1" "1"
run_test "已排序" "1 2" ""

print_subheader "3个数字"
run_test "案例 1 (2 1 0)" "2 1 0" "3"
run_test "案例 2 (2 0 1)" "2 0 1" "3"
run_test "案例 3 (1 0 2)" "1 0 2" "3"
run_test "案例 4 (1 2 0)" "1 2 0" "3"
run_test "案例 5 (0 1 2)" "0 1 2" ""
run_test "案例 6 (0 2 1)" "0 2 1" "3"

print_subheader "5个数字"
run_test "特定案例" "1 5 2 4 3" "12"
run_test "随机5个数字" "$(shuf -i 1-100 -n 5 | tr '\n' ' ')" "12"

# 中等规模数据测试
print_header "中等规模数据测试 (100个数字)"

for i in {1..3}; do
    arg=$(shuf -i 1-1000 -n 100 | tr "\n" " ")
    echo -e "${MAGENTA}▶ 测试 $i:${RESET}"
    ops=$($PUSH_SWAP $arg | wc -l | tr -d ' ')
    result=$($PUSH_SWAP $arg | $CHECKER $arg 2>/dev/null)
    
    if [ "$result" == "OK" ]; then
        print_result "pass" "排序正确"
    else
        print_result "fail" "排序失败: $result"
    fi
    
    print_operations "$ops" "700"
    
    # 评估得分
    if [ "$ops" -le 700 ]; then
        echo -e "  ${GREEN}${BOLD}评分: 优秀${RESET}"
    elif [ "$ops" -le 900 ]; then
        echo -e "  ${YELLOW}${BOLD}评分: 良好${RESET}"
    elif [ "$ops" -le 1100 ]; then
        echo -e "  ${YELLOW}${BOLD}评分: 合格${RESET}"
    else
        echo -e "  ${RED}${BOLD}评分: 需要改进${RESET}"
    fi
    echo ""
done

# 大规模数据测试
print_header "大规模数据测试 (500个数字)"

for i in {1..2}; do
    arg=$(shuf -i 1-10000 -n 500 | tr "\n" " ")
    echo -e "${MAGENTA}▶ 测试 $i:${RESET}"
    ops=$($PUSH_SWAP $arg | wc -l | tr -d ' ')
    result=$($PUSH_SWAP $arg | $CHECKER $arg 2>/dev/null)
    
    if [ "$result" == "OK" ]; then
        print_result "pass" "排序正确"
    else
        print_result "fail" "排序失败: $result"
    fi
    
    print_operations "$ops" "5500"
    
    # 评估得分
    if [ "$ops" -le 5000 ]; then
        echo -e "  ${GREEN}${BOLD}评分: 优秀${RESET}"
    elif [ "$ops" -le 5500 ]; then
        echo -e "  ${YELLOW}${BOLD}评分: 良好${RESET}"
    elif [ "$ops" -le 7000 ]; then
        echo -e "  ${YELLOW}${BOLD}评分: 合格${RESET}"
    else
        echo -e "  ${RED}${BOLD}评分: 需要改进${RESET}"
    fi
    echo ""
done

# 特殊格式输入测试
print_header "特殊格式输入测试"

run_test "引号包裹的参数" "\"1 2 3\"" ""
run_test "多个引号参数" "\"1 2\" \"3 4\"" ""

# 内存测试
print_header "内存管理测试"

print_test "简单内存测试"
leak_result=$(valgrind --leak-check=full $PUSH_SWAP 3 1 2 2>&1 | grep "no leaks are possible")
if [ -n "$leak_result" ]; then
    print_result "pass" "无内存泄漏"
else
    print_result "fail" "检测到内存泄漏"
fi
echo ""

print_test "大规模内存测试"
leak_result=$(valgrind --leak-check=full $PUSH_SWAP $(shuf -i 1-100 -n 20 | tr "\n" " ") 2>&1 | grep "no leaks are possible")
if [ -n "$leak_result" ]; then
    print_result "pass" "无内存泄漏"
else
    print_result "fail" "检测到内存泄漏"
fi
echo ""

# 边缘情况测试
print_header "边缘情况测试"

run_test "接近已排序 1" "1 3 2 4 5" ""
run_test "接近已排序 2" "2 1 3 4 5" ""
run_test "交替大小数字" "1 10 2 9 3 8 4 7 5 6" ""
run_error_test "相同负数" "-5 -5" "Error"
run_test "带加号的数字" "+42 84" ""

# 总结
print_header "测试总结"

echo -e "${BOLD}${GREEN}测试完成!${RESET}"
echo -e "${YELLOW}结束时间: $(date)${RESET}"
echo -e "\n${BOLD}记得检查测试结果并修复任何失败的测试!${RESET}"
