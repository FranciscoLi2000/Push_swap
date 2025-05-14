/* 
 * PUSH_SWAP DATA STRUCTURES
 * 
 * This implementation provides the core data structures and operations
 * needed for the push_swap project - a program that sorts integers
 * using two stacks and a limited set of operations.
 */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

/*
 * Stack node structure
 * Each node contains an integer value and a pointer to the next node
 */
typedef struct s_stack
{
	int		value;
	struct s_stack	*next;
}	t_stack;

/*
 * Operations counter structure
 * Used to keep track of how many operations have been performed
 */
typedef struct s_counter
{
	int	sa;     // swap a
	int	sb;     // swap b
	int	ss;     // swap both
	int	pa;     // push to a
	int	pb;     // push to b
	int	ra;     // rotate a
	int	rb;     // rotate b
	int	rr;     // rotate both
	int	rra;    // reverse rotate a
	int	rrb;    // reverse rotate b
	int	rrr;    // reverse rotate both
	int	total;  // total operations
}	t_counter;

/*
 * Program context structure
 * Centralizes all program data in one structure
 */
typedef struct s_context
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_counter	counter;
	int			size_a;
	int			size_b;
	int			*sorted;    // Array of sorted values for reference
	int			total_size; // Original size of stack_a
	bool		debug;      // Flag for debug output mode
}	t_context;

/*
 * Stack operations prototypes
 */
t_stack	*stack_new_node(int value);	// Create a new node with the given value
void	stack_push(t_stack **stack, t_stack *new_node);	// Add a node to the head of the stack
t_stack	*stack_pop(t_stack **stack);	// Remove and return the top node from the stack

// Get the value of the node at the given position (0-indexed)
int		stack_get(t_stack *stack, int position);

t_stack	*stack_last(t_stack *stack);	// Get the last node in the stack
int		stack_size(t_stack *stack);	// Get the size of the stack
bool	is_stack_sorted(t_stack *stack);	// Check if the stack is sorted in ascending order
void	stack_free(t_stack **stack);	// Free the entire stack

/*
 * Push_swap operations prototypes
 * These implement the required operations for the push_swap assignment
 */
// sa: Swap the first two elements of stack A
void	op_sa(t_context *ctx, bool print);

// sb: Swap the first two elements of stack B
void	op_sb(t_context *ctx, bool print);

// ss: sa and sb at the same time
void	op_ss(t_context *ctx, bool print);

// pa: Push the first element of stack B to stack A
void	op_pa(t_context *ctx, bool print);

// pb: Push the first element of stack A to stack B
void	op_pb(t_context *ctx, bool print);

// ra: Rotate stack A (first element becomes last)
void	op_ra(t_context *ctx, bool print);

// rb: Rotate stack B (first element becomes last)
void	op_rb(t_context *ctx, bool print);

// rr: ra and rb at the same time
void	op_rr(t_context *ctx, bool print);

// rra: Reverse rotate stack A (last element becomes first)
void	op_rra(t_context *ctx, bool print);

// rrb: Reverse rotate stack B (last element becomes first)
void	op_rrb(t_context *ctx, bool print);

// rrr: rra and rrb at the same time
void	op_rrr(t_context *ctx, bool print);

/*
 * Context management functions
 */
// Initialize the program context
t_context	*init_context(void);

// Clean up and free all resources
void	cleanup_context(t_context *ctx);

/*
 * Parser and validation functions
 */
// Parse command line arguments into stack A
bool	parse_arguments(t_context *ctx, int argc, char **argv);

// Check for duplicates in stack A
bool	has_duplicates(t_stack *stack);

// Check if a string is a valid integer
bool	is_valid_integer(const char *str);

// Print error message and exit
void	error_exit(t_context *ctx);

/*
 * Algorithm functions (implementation will depend on your sorting strategy)
 */
// Sort 2 elements
void	sort_two(t_context *ctx);

// Sort 3 elements
void	sort_three(t_context *ctx);

// Sort 5 elements
void	sort_five(t_context *ctx);

// Sort any number of elements
void	sort(t_context *ctx);

/*
 * Utility functions
 */

// Print current state of stacks (for debugging)
void	print_stacks(t_context *ctx);

// Find minimum value in stack
int		find_min(t_stack *stack);

// Find maximum value in stack
int		find_max(t_stack *stack);

// Find position of a value in stack
int		find_position(t_stack *stack, int value);

// Calculate how many moves needed to bring a position to the top
int		calculate_moves(int position, int stack_size);

#endif
