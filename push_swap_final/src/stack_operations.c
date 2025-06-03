/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/05/22 17:32:12 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * sa: Swap the first 2 elements at the top of stack a
 */
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

/*
 * sb: Swap the first 2 elements at the top of stack b
 */
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

/*
 * ss: sa and sb at the same time
 */
void	ss(t_stack *stack_a, t_stack *stack_b, bool print)
{
	sa(stack_a, false);
	sb(stack_b, false);
	if (print)
		ft_putstr_fd("ss\n", 1);
	if (DEBUG)
		display_stacks(stack_a, stack_b);
}

/*
 * pa: Take the first element at the top of b and put it at the top of a
 */
void	pa(t_stack *stack_a, t_stack *stack_b, bool print)
{
	t_node	*temp;
	int		value;
	int		index;

	if (is_stack_empty(stack_b))
		return ;
	temp = stack_b->top;
	value = temp->value;
	index = temp->index;
	stack_b->top = temp->next;
	free(temp);
	stack_b->size--;
	push_to_stack(stack_a, value);
	stack_a->top->index = index;
	if (print)
		ft_putstr_fd("pa\n", 1);
	if (DEBUG)
		display_stacks(stack_a, stack_b);
}

/*
 * pb: Take the first element at the top of a and put it at the top of b
 */
void	pb(t_stack *stack_a, t_stack *stack_b, bool print)
{
	t_node	*temp;
	int		value;
	int		index;

	if (is_stack_empty(stack_a))
		return ;
	temp = stack_a->top;
	value = temp->value;
	index = temp->index;
	stack_a->top = temp->next;
	free(temp);
	stack_a->size--;
	push_to_stack(stack_b, value);
	stack_b->top->index = index;
	if (print)
		ft_putstr_fd("pb\n", 1);
	if (DEBUG)
		display_stacks(stack_a, stack_b);
}
