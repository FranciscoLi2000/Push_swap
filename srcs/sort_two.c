#include "push_swap.h"

/*
** Sorts a stack with 2 elements
*/
void	sort_two(t_stack *a)
{
	if (!a || a->size != 2)
		return ;
	if (a->top->data > a->top->next->data)
		sa(a);
}
