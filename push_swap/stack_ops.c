#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	t_node	*first;
	t_node	*second;

	if (!stack_a->top || !stack_a->top->next)
		return ;
	first = stack_a->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack_a->top = second;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;

	if (!stack_b->top || !stack_b->top->next)
		return ;
	first = stack_b->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack_b->top = second;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	value;

	if (!stack_b->top)
		return ;
	value = pop(stack_b);
	push(stack_a, value);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *stack_b, t_stack *stack_a)
{
	int	value;

	if (!stack_a->top)
		return ;
	value = pop(stack_a);
	push(stack_b, value);
	ft_putstr_fd("pb\n", 1);
}
