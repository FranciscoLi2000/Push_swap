#ifndef STACK_H
# define STACK_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>

typedef struct s_stack_node
{
	int			data;   // The integer value stored in this node
	int			index;  // Index for sorting purposes
	struct s_stack_node	*next;  // Pointer to the next node in the stack
}	t_stack_node;

typedef struct s_stack
{
	t_stack_node	*top;   // Pointer to the top node of the stack
	int			size;   // Number of elements in the stack
}	t_stack;

t_stack	*stack_init(void);
bool	stack_push(t_stack *s, int value);
bool	stack_pop(t_stack *s, int *value);
void	stack_clear(t_stack *s);
bool	stack_is_empty(const t_stack *s);
int		stack_size(const t_stack *s);
bool	is_sorted(const t_stack *s);
bool	check_duplicate(const t_stack *s);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

void	print_stack(const t_stack *s, const char *name);

#endif
