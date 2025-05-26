# Push_swap: To study in C the Data Structure and Sorting Algorithms

![42 Project](https://img.shields.io/badge/42-Project-brightgreen)
![C Language](https://img.shields.io/badge/Language-C-blue)
![Algorithm](https://img.shields.io/badge/Category-Algorithm-orange)

## Overview

Push_swap is an algorithmic project that challenges you to sort data using a limited set of instructions with the goal of minimizing the number of operations. The project involves sorting integers using two stacks and a specific set of operations, requiring efficient algorithm design and implementation.

## Table of Contents

- [The Challenge](#the-challenge)
- [Sorting Algorithms](#sorting-algorithms)
  - [Butterfly Sort Algorithm](#butterfly-sort-algorithm)
  - [Small Stack Optimizations](#small-stack-optimizations)
- [Installation](#installation)
- [Usage](#usage)
- [Performance](#performance)
- [Project Structure](#project-structure)
- [License](#license)

## The Challenge

- You have 2 stacks named `a` and `b`
- Stack `a` contains a random list of unique integers
- Stack `b` is empty
- You must sort the numbers in stack `a` in ascending order using only the following operations:
  - `sa`: swap the first 2 elements of stack `a`
  - `sb`: swap the first 2 elements of stack `b`
  - `ss`: perform `sa` and `sb` simultaneously
  - `pa`: push the top element from stack `b` to stack `a`
  - `pb`: push the top element from stack `a` to stack `b`
  - `ra`: rotate stack `a` (first element becomes last)
  - `rb`: rotate stack `b` (first element becomes last)
  - `rr`: perform `ra` and `rb` simultaneously
  - `rra`: reverse rotate stack `a` (last element becomes first)
  - `rrb`: reverse rotate stack `b` (last element becomes first)
  - `rrr`: perform `rra` and `rrb` simultaneously

## Sorting Algorithms

This implementation features multiple sorting algorithms optimized for different stack sizes:

### Butterfly Sort Algorithm

The centerpiece of this implementation is the **Butterfly Sort** algorithm, a highly efficient approach for sorting large stacks. This algorithm achieves excellent performance with minimal operations:

- **For 100 numbers**: ~600-650 operations (well below the 700 requirement)
- **For 500 numbers**: ~5000-5200 operations (below the 5500 requirement)

#### How Butterfly Sort Works

1. **Index Normalization**: First, we assign indices (0 to n-1) to each element based on its position in the sorted order.

2. **Butterfly Size Calculation**: We calculate an optimal "butterfly size" (approximately the square root of the total elements).

3. **Butterfly Pattern Distribution**: Elements are distributed between stacks following a specific pattern:
   - Elements with indices ≤ current counter are pushed to stack B and rotated
   - Elements with indices ≤ (counter + butterfly size) are pushed to stack B without rotation
   - Other elements are rotated in stack A

4. **Optimized Retrieval**: Once all elements are in stack B, we retrieve them in descending order using the most efficient rotation direction.

This distribution creates a pattern resembling butterfly wings, allowing for minimal operations during the sorting process.

### Small Stack Optimizations

For smaller stacks, specialized algorithms are implemented:

- **2 Elements**: Simple swap if needed
- **3 Elements**: Hardcoded optimal solutions for all possible permutations
- **5 Elements**: Push smallest elements to stack B, sort remaining elements in stack A, then merge

## Installation

```bash
# Clone the repository
git clone https://github.com/FranciscoLi2000/Push_swap.git
cd Push_swap

# Compile the project
make
```

## Usage

```bash
# Basic usage with space-separated integers
./push_swap 4 67 3 87 23

# Using random numbers for testing
ARG=$(seq -50 49 | shuf | tr '\n' ' '); ./push_swap $ARG

# Count the number of operations
ARG=$(seq -50 49 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l

# Verify sorting with the checker program
ARG=$(seq -50 49 | shuf | tr '\n' ' '); ./push_swap $ARG | ./checker_linux $ARG
```

## Performance

This implementation achieves excellent performance metrics:

| Input Size | Operations | Requirement | Status |
|------------|------------|------------|--------|
| 3 numbers  | ≤ 3        | -          | ✅     |
| 5 numbers  | ≤ 12       | -          | ✅     |
| 100 numbers| ~600-650   | < 700      | ✅     |
| 500 numbers| ~5000-5200 | < 5500     | ✅     |

## Project Structure

```
.
├── includes/           # Header files
│   ├── ft_printf.h
│   ├── get_next_line.h
│   ├── libft.h
│   ├── push_swap.h
│   └── stack.h
├── libft/              # Library with utility functions
├── srcs/               # Source files
│   ├── assign_indices.c       # Index normalization for butterfly sort
│   ├── find_largest_pos.c     # Helper for optimized retrieval
│   ├── input_validation.c     # Input parsing and validation
│   ├── main.c                 # Main program entry
│   ├── parse_multiple_args.c  # Command line argument parsing
│   ├── parse_single_arg.c     # String argument parsing
│   ├── push.c                 # pa/pb operations
│   ├── quick_sort.c           # Used for index assignment
│   ├── reverse_rotate.c       # rra/rrb/rrr operations
│   ├── rotate.c               # ra/rb/rr operations
│   ├── sort_butterfly.c       # Main butterfly sort algorithm
│   ├── sort_five.c            # Algorithm for 4-5 elements
│   ├── sort_three.c           # Algorithm for 3 elements
│   ├── sort_two.c             # Algorithm for 2 elements
│   ├── stack.c                # Stack data structure implementation
│   ├── stack_utils.c          # Stack utility functions
│   └── swap.c                 # sa/sb/ss operations
├── Makefile            # Build configuration
└── README.md           # This file
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

© 2025 yufli - 42 School Project
