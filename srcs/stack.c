#include "stack.h"

/*
** Initializes an empty stack
** Returns a pointer to the new stack, or NULL if allocation fails
*/
t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

/*
** Pushes a new value onto the stack
** Returns true if successful, false if allocation fails
*/
bool	stack_push(t_stack *s, int value)
{
	t_stack_node	*new_node;

	if (!s)
		return (false);
	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		return (false);
	new_node->data = value;
	new_node->index = 0;
	new_node->next = s->top;
	s->top = new_node;
	s->size++;
	return (true);
}

/*
** Pops the top value from the stack and stores it in the provided pointer
** Returns true if successful, false if the stack is empty
*/
bool    stack_pop(t_stack *s, int *value)
{
	t_stack_node	*temp;

	if (!s || !s->top)
		return (false);
	*value = s->top->data;
	temp = s->top;
	s->top = s->top->next;
	free(temp);
	s->size--;
	return (true);
}

/*
** Frees all nodes in the stack
** The stack structure itself must be freed separately
*/
void	stack_clear(t_stack *s)
{
	t_stack_node	*current;
	t_stack_node	*next;

	if (!s)
		return ;
	current = s->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	s->top = NULL;
	s->size = 0;
}
