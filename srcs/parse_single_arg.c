#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

/*
 * Free the memory allocated by ft_split
 */
static void	free_split_args(char **split_args)
{
	int	i;

	i = 0;
	while (split_args[i])
	{
		free(split_args[i]);
		i++;
	}
	free(split_args);
}

/*
 * Parse a single string argument containing multiple space-separated numbers
 * This handles cases like: ./push_swap "1 2 3"
 */
bool	parse_single_arg(t_context *ctx, int argc, char **argv)
{
	char	**split_args;
	char	**new_argv;
	int		num_args;
	int		i;
	bool	result;

	if (!ctx || argc != 2 || !argv[1])
		return (false);
	// Split the string into an array of strings
	split_args = ft_split(argv[1], ' ');
	if (!split_args)
		return (false);
	// Count the number of arguments
	num_args = 0;
	while (split_args[num_args])
		num_args++;
	// If no arguments were found, return false
	if (num_args == 0)
	{
		free_split_args(split_args);
		return (false);
	}
	new_argv = (char **)malloc(sizeof(char *) * (num_args + 2));
	if (!new_argv)
	{
		free_split_args(split_args);
		return (false);
	}
	// Copy the program name
	new_argv[0] = argv[0];
	i = 0;
	while (i < num_args)
	{
		new_argv[i + 1] = split_args[i];
		i++;
	}
	new_argv[num_args + 1] = NULL;
	// Parse the arguments using our standard function
	result = parse_arguments(ctx, num_args + 1, new_argv);
	// Free the new_argv array but not its contents
	free(new_argv);
	// Free the split_args array and its contents
	free_split_args(split_args);
	return (result);
}
