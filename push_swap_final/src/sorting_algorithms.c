/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles <bfebles-student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/05/24 by Jules                      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h> // For malloc, free

static void	bubble_sort(int *arr, int size);
static int	*create_and_fill_array(t_stack *stack_a, int size);
static void	assign_idx_to_stack_nodes(t_stack *stack_a, 									int *sorted_arr, int size);
static void	move_smallest_to_b(t_stack *a, t_stack *b);
static void	sort_four(t_stack *a, t_stack *b);
static void	push_chunk_to_b(t_stack *a, t_stack *b, 							int chunk_limit_val, int chunk_mid_val);
static void	move_max_from_b_to_a(t_stack *a, t_stack *b);

static void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	*create_and_fill_array(t_stack *stack_a, int size)
{
	int		*arr;
	t_node	*current;
	int		i;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		error_exit(stack_a, NULL);
	current = stack_a->top;
	i = 0;
	while (current)
	{
		arr[i++] = current->value;
		current = current->next;
	}
	bubble_sort(arr, size);
	return (arr);
}

static void	assign_idx_to_stack_nodes(t_stack *stack_a, 									int *sorted_arr, int size)
{
	t_node	*current;
	int		i;

	current = stack_a->top;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (current->value == sorted_arr[i])
			{
				current->index = i; // Assign index based on sorted position
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

void	assign_indices(t_stack *stack_a)
{
	int	size;
	int	*arr;

	if (!stack_a || !stack_a->top || stack_a->size <= 1)
		return ;
	size = stack_a->size;
	arr = create_and_fill_array(stack_a, size);
	assign_idx_to_stack_nodes(stack_a, arr, size);
	free(arr);
}

void	sort_three(t_stack *s_a)
{
	int	v_top;
	int	v_mid;
	int	v_bot;

	if (is_stack_sorted(s_a))
		return ;
	v_top = s_a->top->value;
	v_mid = s_a->top->next->value;
	v_bot = s_a->top->next->next->value;
	if (v_top > v_mid && v_mid > v_bot)
	{
		sa(s_a, true);
		rra(s_a, true);
	}
	else if (v_top > v_mid && v_mid < v_bot && v_top > v_bot)
		ra(s_a, true);
	else if (v_top < v_mid && v_mid > v_bot && v_top > v_bot)
		rra(s_a, true);
	else if (v_top > v_mid && v_mid < v_bot && v_top < v_bot)
		sa(s_a, true);
	else if (v_top < v_mid && v_mid > v_bot && v_top < v_bot)
	{
		sa(s_a, true);
		ra(s_a, true);
	}
}

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

static void	push_chunk_to_b(t_stack *a, t_stack *b, 							int chunk_limit_val, int chunk_mid_val)
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
			if (b->top->index < chunk_mid_val)
			{
				if (b->size > 1)
					rb(b, true);
			}
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

void	chunk_sort(t_stack *a, t_stack *b)
{
	int	chunk_s;
	int	num_chunks;
	int	c_processed;
	int	target_idx_upper_bound;
	int	target_idx_mid_point;

	if (a->size <= 1 || is_stack_sorted(a))
		return ;
	assign_indices(a);
	if (a->size <= 100)
		chunk_s = 20;
	else
		chunk_s = (a->size / 11) + 5;
	if (chunk_s <= 0) chunk_s = 1;
	num_chunks = (a->size + chunk_s - 1) / chunk_s;
	c_processed = 0;
	while (c_processed < num_chunks)
	{
		target_idx_upper_bound = (c_processed + 1) * chunk_s;
		target_idx_mid_point = c_processed * chunk_s + (chunk_s / 2);
		push_chunk_to_b(a, b, target_idx_upper_bound, target_idx_mid_point);
		c_processed++;
	}
	while (!is_stack_empty(b))
		move_max_from_b_to_a(a, b);
}
