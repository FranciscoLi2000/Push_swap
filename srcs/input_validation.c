#include "push_swap.h"

/*
** Checks if a string is a valid integer and converts it to a long
** Returns true if valid, false otherwise
** The converted value is stored in the provided pointer
*/
bool	is_valid_integer(char *str, long *num)
{
	int		i;
	int		sign;
	long	result;

	if (!str || !*str)
		return (false);
	i = 0;
	sign = 1;
	// Handle sign
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	// Check if there are digits after the sign
	if (!str[i])
		return (false);
	// Convert string to long
	result = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		result = result * 10 + (str[i] - '0');
		// Check for integer overflow
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && result * sign < INT_MIN))
			return (false);
		i++;
	}
	*num = result * sign;
	return (true);
}

/*
** Frees a NULL-terminated array of strings
*/
void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
