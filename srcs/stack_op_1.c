/* 
 * STACK OPERATIONS IMPLEMENTATION
 * 
 * This file implements the basic stack operations needed for the push_swap project.
 */

#include "push_swap.h"

/*
 * Creates a new stack node with the given value
 * Returns NULL if memory allocation fails
 */
t_stack	*stack_new_node(int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

/*
 * Adds a node to the top of the stack
 * This is a basic push operation
 */
void	stack_push(t_stack **stack, t_stack *new_node)
{
	if (!stack || !new_node)
		return ;
	new_node->next = *stack;
	*stack = new_node;
}

/*
 * Removes and returns the top node from the stack
 * Returns NULL if the stack is empty
 */
t_stack	*stack_pop(t_stack **stack)
{
	t_stack	*top;

	if (!stack || !*stack)
		return (NULL);
	top = *stack;
	*stack = (*stack)->next;
	top->next = NULL;
	return (top);
}

/*
 * Gets the value at the specified position in the stack
 * Position 0 is the top of the stack
 * Returns INT_MIN if the position is invalid
 */
int	stack_get(t_stack *stack, int position)
{
	int	i;

	i = 0;
	while (stack && i < position)
	{
		stack = stack->next;
		i++;
	}
	if (stack)
		return (INT_MIN);
	return (stack->value);
}
