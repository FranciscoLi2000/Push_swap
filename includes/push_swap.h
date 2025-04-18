#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>


# define MAXSTACK 1024

typedef struct s_stack
{
	int	data[MAXSTACK];
	int	top;
}	t_stack;

void	stack_init(t_stack *s);
void	push(t_stack *s, int value);
void	push_a(t_stack *s1, t_stack *s2);
void	push_b(t_stack *s1, t_stack *s2);
void	reverse_rotate_a(t_stack *s);
void	reverse_rotate_b(t_stack *s);
void	reverse_rotate_a_b(t_stack *s1, t_stack *s2);
void	rotate_a(t_stack *s);
void	rotate_b(t_stack *s);
void	rotate_a_b(t_stack *s1, t_stack *s2);
void	swap_a(t_stack *s);
void	swap_b(t_stack *s);
void	swap_a_b(t_stack *s1, t_stack *s2);
void	print_stack(const t_stack *s, const char *name);
int		is_empty(const t_stack *s);
int		pop(t_stack *s);
int		peek(t_stack *s);

#endif
