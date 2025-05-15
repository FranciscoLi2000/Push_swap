# Nivel 2: Algoritmos y Estructuras de Datos

## Push_swap

### Project Description

Push_swap is a 42 School project about sorting algorithms and stack manipulation. The goal is to sort a stack of integers using a limited set of operations with the goal of using as few operations as possible.

Compilation
	`make`

### Usage to test

./push_swap 2 1 3 6 5 8

./push_swap "2 1 3 6 5 8"

ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG

### Available Operations

sa: swap a - swap the first 2 elements at the top of stack a
sb: swap b - swap the first 2 elements at the top of stack b
ss: sa and sb at the same time
pa: push a - take the first element at the top of b and put it at the top of a
pb: push b - take the first element at the top of a and put it at the top of b
ra: rotate a - shift up all elements of stack a by 1
rb: rotate b - shift up all elements of stack b by 1
rr: ra and rb at the same time
rra: reverse rotate a - shift down all elements of stack a by 1
rrb: reverse rotate b - shift down all elements of stack b by 1
rrr: rra and rrb at the same time

### Algorithm

The sorting strategy depends on the number of elements:

For 2 elements: simple comparison and swap if needed
For 3 elements: optimized algorithm with a maximum of 2 operations
For 4-5 elements: push smallest elements to stack B, sort remaining 3, then push back
For 6-20 elements: insertion sort algorithm
For 21-60 elements: chunk sort with 3 chunks
For 61-100 elements: chunk sort with 5 chunks
For 100+ elements: radix sort using binary representation

### Performance

For 100 random integers: less than 700 operations
For 500 random integers: less than 5500 operations
