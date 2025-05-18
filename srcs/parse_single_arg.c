#include "push_swap.h"

/*
** Parses a single argument containing space-separated integers
** Returns a stack with the parsed integers, or NULL if an error occurs
*/
t_stack	*parse_single_arg(char *arg)
{
	t_stack	*stack;
	char	**split;
	int		i;
	long	num;

	stack = stack_init();
	if (!stack)
		return (NULL);
	split = ft_split(arg, ' ');
	if (!split)
	{
		free(stack);
		return (NULL);
	}
	i = 0;
	while (split[i])
		i++;
	// Process in reverse order to maintain the original order in the stack
	while (--i >= 0)
	{
		if (!is_valid_integer(split[i], &num))
		{
			free_split(split);
			stack_clear(stack);
			free(stack);
			return (NULL);
		}
		if (!stack_push(stack, (int)num))
		{
			free_split(split);
			stack_clear(stack);
			free(stack);
			return (NULL);
		}
	}
	free_split(split);
	return (stack);
}
