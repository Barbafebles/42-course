/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 20:48:31 by bfebles-          #+#    #+#             */
/*   Updated: 2025/06/06 15:48:32 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_chunk_to_b(t_stack *a, t_stack *b, int chunk_limit_val,
		int chunk_mid_val)
{
	int	scanned_this_pass;
	int	initial_a_size_this_call;

	scanned_this_pass = 0;
	initial_a_size_this_call = a->size;
	while (scanned_this_pass < initial_a_size_this_call && a->size > 0)
	{
		if (a->top->index < chunk_limit_val)
		{
			pb(a, b, true);
			if (b->top->index < chunk_mid_val && b->size > 1)
				rb(b, true);
		}
		else
			ra(a, true);
		scanned_this_pass++;
	}
}

static void	move_max_from_b_to_a(t_stack *a, t_stack *b)
{
	int		max_val;
	int		pos;
	t_node	*tmp;

	if (is_stack_empty(b))
		return ;
	max_val = find_max(b);
	pos = 0;
	tmp = b->top;
	while (tmp && tmp->value != max_val)
	{
		tmp = tmp->next;
		pos++;
	}
	while (b->top->value != max_val)
	{
		if (pos <= b->size / 2)
			rb(b, true);
		else
			rrb(b, true);
	}
	pa(a, b, true);
}

static int	get_chunk_size(t_stack *a)
{
	if (a->size <= 100)
		return (20);
	else
		return ((a->size / 11) + 5);
}

static void	push_chunks_to_b(t_stack *a, t_stack *b, int chunk_s,
		int num_chunks)
{
	int	c_processed;
	int	target_idx_upper_bound;
	int	target_idx_mid_point;

	c_processed = 0;
	while (c_processed < num_chunks)
	{
		target_idx_upper_bound = (c_processed + 1) * chunk_s;
		target_idx_mid_point = c_processed * chunk_s + (chunk_s / 2);
		push_chunk_to_b(a, b, target_idx_upper_bound, target_idx_mid_point);
		c_processed++;
	}
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	int	chunk_s;
	int	num_chunks;

	if (a->size <= 1 || is_stack_sorted(a))
		return ;
	assign_indices(a);
	chunk_s = get_chunk_size(a);
	if (chunk_s <= 0)
		chunk_s = 1;
	num_chunks = (a->size + chunk_s - 1) / chunk_s;
	push_chunks_to_b(a, b, chunk_s, num_chunks);
	while (!is_stack_empty(b))
		move_max_from_b_to_a(a, b);
}
