# Nivel 2: Algoritmos y Estructuras de Datos

# Push_swap

## Project Overview

The Push Swap project is an algorithmic challenge that requires sorting a stack of integers using a limited set of operations. The goal is to implement a program that calculates and displays the shortest sequence of operations to sort the stack.

## Key Components Implemented

1. **Stack Data Structure**

Implemented using a linked list

Basic operations: push, pop, clear, is_empty, size

2. **Stack Operations**

sa, sb, ss: Swap the top two elements

pa, pb: Push from one stack to another

ra, rb, rr: Rotate up (first becomes last)

rra, rrb, rrr: Reverse rotate (last becomes first)

3. **Input Parsing and Validation**

Handling multiple arguments

Handling a single argument with space-separated integers

Validating integers and checking for duplicates

4. **Sorting Algorithms**

Small stack sorting (2-3 elements)

Medium stack sorting (up to 5 elements)

Insertion sort for stacks up to 20 elements

Chunk method for larger stacks

5. **Optimization Strategies**

Indexing elements based on sorted order

Cost calculation for operations

Greedy approach for choosing operations

Using combined operations when possible

## Project Requirements

Sort 100 random numbers in fewer than 700 operations for minimal validation

Sort 500 random numbers in fewer than 5500 operations for maximum validation

## Implementation Structure

The implementation follows a modular approach:

1. **Stack Implementation**: Basic data structure and operations

2. **Push Swap Operations**: Implementation of required operations

3. **Input Parsing**: Handling and validating input arguments

4. **Sorting Algorithms**: Different algorithms based on stack size

5. **Main Program**: Orchestrating the sorting process

## Next Steps

1. **Testing**: Test the implementation with various inputs

2. **Optimization**: Fine-tune the algorithms to meet benchmark requirements

3. **Bonus Part**: Implement the checker program if desired

## Conclusion

The Push Swap project is a challenging algorithmic problem that requires careful implementation and optimization. By following the step-by-step guide provided, you should be able to implement a solution that meets the project requirements.

Remember to adhere to the 42 norminette coding standards throughout your implementation, and focus on optimizing your sorting algorithms to meet the benchmark requirements.
