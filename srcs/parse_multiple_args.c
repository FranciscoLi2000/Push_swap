#include "push_swap.h"

/*
** Parses multiple arguments as integers
** Returns a stack with the parsed integers, or NULL if an error occurs
*/
t_stack	*parse_multiple_args(int argc, char **argv)
{
	t_stack	*stack;
	int		i;
	long	num;

	stack = stack_init();
	if (!stack)
		return (NULL);
	// Process in reverse order to maintain the original order in the stack
	i = argc;
	while (--i > 0)
	{
		if (!is_valid_integer(argv[i], &num))
		{
			stack_clear(stack);
			free(stack);
			return (NULL);
		}
		if (!stack_push(stack, (int)num))
		{
			stack_clear(stack);
			free(stack);
			return (NULL);
		}
	}
	return (stack);
}
