/* 
 * PUSH_SWAP MAIN PROGRAM
 * 
 * This file contains the main function for the push_swap program,
 * including a test framework to verify the implementation.
 */

#include "push_swap.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*
 * Generate an array of random integers without duplicates
 */
static int	*generate_random_array(int size)
{
	int	*array;
	int	i;
	int	j;
	int	random_value;
	int	is_duplicate;

	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return NULL;
	// Seed the random number generator
	srand(time(NULL));
	// Generate unique random values
	i = 0;
	while (i < size)
	{
		random_value = rand() % (size * 10) - (size * 5);  // Range: -5*size to 5*size
		// Check for duplicates
		is_duplicate = 0;
		j = 0;
		while (j < i)
		{
			if (array[j] == random_value)
			{
				is_duplicate = 1;
				break ;
			}
			j++;
		}
		if (!is_duplicate)
		{
			array[i] = random_value;
			i++;
		}
	}
	return (array);
}

/*
 * Generate command line arguments from an integer array
 */
static char	**generate_args_from_array(int *array, int size)
{
	char	**args;
	int		i;
	char	buffer[20];
	// Allocate memory for arguments array (size + 1 for program name)
	args = (char **)malloc(sizeof(char *) * (size + 2));
	if (!args)
		return NULL;
	// First argument is program name (placeholder)
	args[0] = strdup("push_swap");
	if (!args[0])
	{
		free(args);
		return NULL;
	}
	i = 0;
	while (i < size)
	{
		sprintf(buffer, "%d", array[i]);
		args[i + 1] = strdup(buffer);
		if (!args[i + 1])
		{
			// Free all previously allocated memory
			while (i >= 0)
			{
				free(args[i]);
				i--;
			}
			free(args[0]);
			free(args);
			return NULL;
		}
		i++;
	}
	args[size + 1] = NULL;
	return args;
}

/*
 * Free allocated command line arguments
 */
static void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

/*
 * Run the full push_swap algorithm with the given parameters
 * and return the number of operations used
 */
static int run_push_swap_test(int size, bool debug)
{
    t_context *ctx;
    int *array;
    char **args;
    int op_count;
    
    // Generate random input
    array = generate_random_array(size);
    if (!array)
    {
        printf("Error: Failed to generate random array\n");
        return -1;
    }
    
    // Create command line arguments
    args = generate_args_from_array(array, size);
    if (!args)
    {
        printf("Error: Failed to generate arguments\n");
        free(array);
        return -1;
    }
    
    // Initialize context
    ctx = init_context();
    if (!ctx)
    {
        printf("Error: Failed to initialize context\n");
        free_args(args);
        free(array);
        return -1;
    }
    
    // Set debug mode if requested
    ctx->debug = debug;
    
    // Parse arguments
    if (!parse_arguments(ctx, size + 1, args))
    {
        printf("Error: Failed to parse arguments\n");
        cleanup_context(ctx);
        free_args(args);
        free(array);
        return -1;
    }
    
    // Print initial state if in debug mode
    if (debug)
    {
        printf("Initial state:\n");
        print_stacks(ctx);
    }
    
    // Sort the stack
    sort(ctx);
    
    // Get the number of operations used
    op_count = ctx->counter.total;
    
    // Verify the result
    if (!is_stack_sorted(ctx->stack_a) || ctx->stack_b != NULL)
    {
        printf("Error: Sorting failed\n");
        cleanup_context(ctx);
        free_args(args);
        free(array);
        return -1;
    }
    
    // Print final state if in debug mode
    if (debug)
    {
        printf("Final state:\n");
        print_stacks(ctx);
        printf("Operations used: %d\n", op_count);
    }
    
    // Clean up
    cleanup_context(ctx);
    free_args(args);
    free(array);
    
    return op_count;
}

/*
 * Run performance tests with different input sizes
 */
static void run_performance_tests(void)
{
    int sizes[] = {5, 10, 20, 50, 100, 500};
    int tests_per_size = 5;
    int i, j, ops, total_ops;
    double avg_ops;
    
    printf("\n========= PERFORMANCE TESTS =========\n");
    printf("Running %d tests for each size...\n\n", tests_per_size);
    
    for (i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++)
    {
        total_ops = 0;
        
        printf("Testing size %d:\n", sizes[i]);
        
        for (j = 0; j < tests_per_size; j++)
        {
            ops = run_push_swap_test(sizes[i], false);
            if (ops < 0)
            {
                printf("  Test %d: Failed\n", j + 1);
                continue;
            }
            
            printf("  Test %d: %d operations\n", j + 1, ops);
            total_ops += ops;
        }
        
        if (total_ops > 0)
        {
            avg_ops = (double)total_ops / tests_per_size;
            printf("  Average: %.2f operations\n", avg_ops);
            
            if (sizes[i] == 100 && avg_ops <= 700)
                printf("  PASSED: Average under 700 operations for 100 elements\n");
            else if (sizes[i] == 100)
                printf("  FAILED: Average over 700 operations for 100 elements\n");
            
            if (sizes[i] == 500 && avg_ops <= 5500)
                printf("  PASSED: Average under 5500 operations for 500 elements\n");
            else if (sizes[i] == 500)
                printf("  FAILED: Average over 5500 operations for 500 elements\n");
        }
        
        printf("\n");
    }
}

/*
 * Test specific sorting cases
 */
static void test_specific_cases(void)
{
    t_context *ctx;
    
    printf("\n========= SPECIFIC CASES =========\n");
    
    // Case 1: Already sorted
    {
        int sorted[] = {1, 2, 3, 4, 5};
        int size = sizeof(sorted) / sizeof(sorted[0]);
        char **args = generate_args_from_array(sorted, size);
        
        printf("Test: Already sorted array\n");
        
        ctx = init_context();
        if (!ctx || !args || !parse_arguments(ctx, size + 1, args))
        {
            printf("  Failed to initialize test\n\n");
        }
        else
        {
            sort(ctx);
            printf("  Operations: %d (Expected: 0)\n", ctx->counter.total);
            printf("  Result: %s\n\n", 
                   (ctx->counter.total == 0 && is_stack_sorted(ctx->stack_a)) ? "PASSED" : "FAILED");
            
            cleanup_context(ctx);
        }
        
        if (args)
            free_args(args);
    }
    
    // Case 2: Reverse sorted
    {
        int reverse[] = {5, 4, 3, 2, 1};
        int size = sizeof(reverse) / sizeof(reverse[0]);
        char **args = generate_args_from_array(reverse, size);
        
        printf("Test: Reverse sorted array\n");
        
        ctx = init_context();
        if (!ctx || !args || !parse_arguments(ctx, size + 1, args))
        {
            printf("  Failed to initialize test\n\n");
        }
        else
        {
            sort(ctx);
            printf("  Operations: %d\n", ctx->counter.total);
            printf("  Result: %s\n\n", is_stack_sorted(ctx->stack_a) ? "PASSED" : "FAILED");
            
            cleanup_context(ctx);
        }
        
        if (args)
            free_args(args);
    }
    
    // Case 3: Small array with 3 elements
    {
        int small[] = {2, 1, 3};
        int size = sizeof(small) / sizeof(small[0]);
        char **args = generate_args_from_array(small, size);
        
        printf("Test: Small array (3 elements)\n");
        
        ctx = init_context();
        if (!ctx || !args || !parse_arguments(ctx, size + 1, args))
        {
            printf("  Failed to initialize test\n\n");
        }
        else
        {
            sort(ctx);
            printf("  Operations: %d (Expected: ≤ 2)\n", ctx->counter.total);
            printf("  Result: %s\n\n", 
                   (ctx->counter.total <= 2 && is_stack_sorted(ctx->stack_a)) ? "PASSED" : "FAILED");
            
            cleanup_context(ctx);
        }
        
        if (args)
            free_args(args);
    }
}

/*
 * Main function for testing push_swap implementation
 */
int	main(int argc, char **argv)
{
	t_context	*ctx;
	int	op_count;
	// If arguments are provided, run the actual program
	if (argc > 1)
	{
		ctx = init_context();
		if (!ctx)
		{
			write(2, "Error\n", 6);
			return 1;
		}
		if (!parse_arguments(ctx, argc, argv))
		{
			write(2, "Error\n", 6);
			cleanup_context(ctx);
			return 1;
		}
		// Check if already sorted
		if (!is_stack_sorted(ctx->stack_a))
		{
			// Run the sorting algorithm
			sort(ctx);
		}
		// Clean up and exit
		cleanup_context(ctx);
		return 0;
	}
	// No arguments provided, run tests
	printf("PUSH_SWAP TESTER\n");
	printf("================\n\n");
	// Test with a small array in debug mode
	printf("Running debug test with 10 elements:\n");
	op_count = run_push_swap_test(10, true);
	if (op_count >= 0)
		printf("Debug test completed successfully with %d operations.\n\n", op_count);
	else
		printf("Debug test failed.\n\n");
	// Test specific cases
	test_specific_cases();
	// Run performance tests
	run_performance_tests();
	return 0;
}
