/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/06/05 20:44:45 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack *stack_a, bool print)
{
	t_node	*first;
	t_node	*last;

	if (stack_a->size < 2)
		return ;
	first = stack_a->top;
	stack_a->top = first->next;
	last = stack_a->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	if (print)
		ft_putstr_fd("ra\n", 1);
	if (DEBUG)
		display_stacks(stack_a, NULL);
}

void	rb(t_stack *stack_b, bool print)
{
	t_node	*first;
	t_node	*last;

	if (stack_b->size < 2)
		return ;
	first = stack_b->top;
	stack_b->top = first->next;
	last = stack_b->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	if (print)
		ft_putstr_fd("rb\n", 1);
	if (DEBUG)
		display_stacks(NULL, stack_b);
}

void	rr(t_stack *stack_a, t_stack *stack_b, bool print)
{
	ra(stack_a, false);
	rb(stack_b, false);
	if (print)
		ft_putstr_fd("rr\n", 1);
	if (DEBUG)
		display_stacks(stack_a, stack_b);
}

void	rra(t_stack *stack_a, bool print)
{
	t_node	*last;
	t_node	*second_last;

	if (stack_a->size < 2)
		return ;
	last = stack_a->top;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = stack_a->top;
	stack_a->top = last;
	second_last->next = NULL;
	if (print)
		ft_putstr_fd("rra\n", 1);
	if (DEBUG)
		display_stacks(stack_a, NULL);
}

void	rrb(t_stack *stack_b, bool print)
{
	t_node	*last;
	t_node	*second_last;

	if (stack_b->size < 2)
		return ;
	last = stack_b->top;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = stack_b->top;
	stack_b->top = last;
	second_last->next = NULL;
	if (print)
		ft_putstr_fd("rrb\n", 1);
	if (DEBUG)
		display_stacks(NULL, stack_b);
}
