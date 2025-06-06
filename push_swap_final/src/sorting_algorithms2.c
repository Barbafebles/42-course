/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 20:47:24 by bfebles-          #+#    #+#             */
/*   Updated: 2025/06/06 15:41:54 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	move_smallest_to_b(t_stack *a, t_stack *b)
{
	int		min_val;
	int		pos;
	t_node	*curr;

	min_val = find_min(a);
	pos = 0;
	curr = a->top;
	while (curr && curr->value != min_val)
	{
		curr = curr->next;
		pos++;
	}
	while (a->top->value != min_val)
	{
		if (pos <= a->size / 2)
			ra(a, true);
		else
			rra(a, true);
	}
	pb(a, b, true);
}

static void	sort_four(t_stack *a, t_stack *b)
{
	if (is_stack_sorted(a))
		return ;
	move_smallest_to_b(a, b);
	sort_three(a);
	pa(a, b, true);
}

void	sort_five(t_stack *a, t_stack *b)
{
	if (is_stack_sorted(a))
		return ;
	move_smallest_to_b(a, b);
	move_smallest_to_b(a, b);
	sort_three(a);
	pa(a, b, true);
	pa(a, b, true);
}

void	sort_small(t_stack *stack_a, t_stack *stack_b, int size)
{
	if (size <= 1 || is_stack_sorted(stack_a))
		return ;
	if (size == 2)
	{
		if (stack_a->top->value > stack_a->top->next->value)
			sa(stack_a, true);
	}
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
}
