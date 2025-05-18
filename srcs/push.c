#include "stack.h"

/*
** Takes the top element from stack b and puts it on top of stack a
** Does nothing if b is empty
** Prints "pa" to stdout
*/
void	pa(t_stack *a, t_stack *b)
{
	t_stack_node	*temp;

	if (!a || !b || !b->top)
		return ;
	
	// Remove the top node from stack b
	temp = b->top;
	b->top = b->top->next;
	b->size--;

	// Add the node to the top of stack a
	temp->next = a->top;
	a->top = temp;
	a->size++;
	write(1, "pa\n", 3);
}

/*
** Takes the top element from stack a and puts it on top of stack b
** Does nothing if a is empty
** Prints "pb" to stdout
*/
void	pb(t_stack *a, t_stack *b)
{
	t_stack_node	*temp;

	if (!a || !b || !a->top)
		return ;

	// Remove the top node from stack a
	temp = a->top;
	a->top = a->top->next;
	a->size--;

	// Add the node to the top of stack b
	temp->next = b->top;
	b->top = temp;
	b->size++;
	write(1, "pb\n", 3);
}
