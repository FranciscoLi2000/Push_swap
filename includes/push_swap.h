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
# include "libft.h"

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
	t_stack		*stack_a;
	t_stack		*stack_b;
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
t_stack	*stack_new_node(int value);
void	stack_push(t_stack **stack, t_stack *new_node);
t_stack	*stack_pop(t_stack **stack);
int		stack_get(t_stack *stack, int position);
t_stack	*stack_last(t_stack *stack);
int		stack_size(t_stack *stack);
bool	is_stack_sorted(t_stack *stack);
void	stack_free(t_stack **stack);

/*
 * Push_swap operations prototypes
 */
void	op_sa(t_context *ctx, bool print);
void	op_sb(t_context *ctx, bool print);
void	op_ss(t_context *ctx, bool print);
void	op_pa(t_context *ctx, bool print);
void	op_pb(t_context *ctx, bool print);
void	op_ra(t_context *ctx, bool print);
void	op_rb(t_context *ctx, bool print);
void	op_rr(t_context *ctx, bool print);
void	op_rra(t_context *ctx, bool print);
void	op_rrb(t_context *ctx, bool print);
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
bool		parse_arguments(t_context *ctx, int argc, char **argv);
bool		parse_single_arg(t_context *ctx, int argc, char **argv);
bool		has_duplicates(t_stack *stack);
bool		is_valid_integer(const char *str);
void		error_exit(t_context *ctx);

/*
 * Sorting algorithms
 */
void		sort_two(t_context *ctx);
void		sort_three(t_context *ctx);
void		sort_five(t_context *ctx);
void		sort_insertion(t_context *ctx);
void		sort_chunks(t_context *ctx, int chunks);
void		sort_radix(t_context *ctx);
void		sort(t_context *ctx);

/*
 * Utility functions
 */
void		print_stacks(t_context *ctx);
int			find_min(t_stack *stack);
int			find_max(t_stack *stack);
int			find_position(t_stack *stack, int value);
int			calculate_moves(int position, int stack_size);
int			*create_sorted_array(t_context *ctx);
void		normalize_values(t_context *ctx, int *sorted);
bool		has_chunk_elements(t_context *ctx, int *sorted, int start, int end);
int			find_best_chunk_element(t_context *ctx, int *sorted, int start, int end);
void		move_element_to_top(t_context *ctx, int pos);

#endif
