/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/06/05 20:45:59 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack *stack_a, bool print)
{
	t_node	*first;
	t_node	*second;
	int		temp_value;
	int		temp_index;

	if (stack_a->size < 2)
		return ;
	first = stack_a->top;
	second = first->next;
	temp_value = first->value;
	temp_index = first->index;
	first->value = second->value;
	first->index = second->index;
	second->value = temp_value;
	second->index = temp_index;
	if (print)
		ft_putstr_fd("sa\n", 1);
	if (DEBUG)
		display_stacks(stack_a, NULL);
}

void	sb(t_stack *stack_b, bool print)
{
	t_node	*first;
	t_node	*second;
	int		temp_value;
	int		temp_index;

	if (stack_b->size < 2)
		return ;
	first = stack_b->top;
	second = first->next;
	temp_value = first->value;
	temp_index = first->index;
	first->value = second->value;
	first->index = second->index;
	second->value = temp_value;
	second->index = temp_index;
	if (print)
		ft_putstr_fd("sb\n", 1);
	if (DEBUG)
		display_stacks(NULL, stack_b);
}

void	ss(t_stack *stack_a, t_stack *stack_b, bool print)
{
	sa(stack_a, false);
	sb(stack_b, false);
	if (print)
		ft_putstr_fd("ss\n", 1);
	if (DEBUG)
		display_stacks(stack_a, stack_b);
}

void	pa(t_stack *stack_a, t_stack *stack_b, bool print)
{
	t_node	*node;

	if (!stack_a || is_stack_empty(stack_b))
		return ;
	node = stack_b->top;
	stack_b->top = node->next;
	stack_b->size--;
	node->next = stack_a->top;
	stack_a->top = node;
	stack_a->size++;
	if (print)
		ft_putstr_fd("pa\n", 1);
	if (DEBUG)
		display_stacks(stack_a, stack_b);
}

void	pb(t_stack *stack_a, t_stack *stack_b, bool print)
{
	t_node	*node;

	if (!stack_b || is_stack_empty(stack_a))
		return ;
	node = stack_a->top;
	stack_a->top = node->next;
	stack_a->size--;
	node->next = stack_b->top;
	stack_b->top = node;
	stack_b->size++;
	if (print)
		ft_putstr_fd("pb\n", 1);
	if (DEBUG)
		display_stacks(stack_a, stack_b);
}
