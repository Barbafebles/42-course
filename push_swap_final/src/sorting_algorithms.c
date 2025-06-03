/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/05/22 17:31:56 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Helper function for bubble sort (not part of public API)
static void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void	assign_indices(t_stack *stack_a)
{
	int		size;
	int		*arr;
	t_node	*current;
	int		i;

	if (!stack_a || !stack_a->top || stack_a->size <= 1)
		return ;
	size = stack_a->size;
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
	current = stack_a->top;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (current->value == arr[i])
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
	free(arr);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	max_num;
	int	i;
	int	j;
	int	size;

	max_bits = 0;
	max_num = a->size - 1;
	i = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	for (i = 0; i < max_bits; i++)
	{
		j = 0;
		size = a->size;
		while (j++ < size)
		{
			if (((a->top->index >> i) & 1) == 1)
				ra(a, true);
			else
				pb(a, b, true);
		}
		while (b->size > 0)
			pa(a, b, true);
	}
}

void	sort_three(t_stack *stack_a)
{
	int	top;
	int	mid;
	int	bot;

	top = stack_a->top->value;
	mid = stack_a->top->next->value;
	bot = stack_a->top->next->next->value;
	if (is_stack_sorted(stack_a))
		return ;
	// Case: 4 2 1 (top, mid, bot) -> 2 1 4 -> 1 2 4
	if (top > mid && mid > bot)
	{
		ra(stack_a, true);
		sa(stack_a, true);
	}
	// Case: 4 1 2 -> 1 2 4
	else if (top > bot && bot > mid)
	{
		ra(stack_a, true);
	}
	// Case: 2 4 1 -> 4 1 2 -> 1 2 4
	else if (mid > top && top > bot)
	{
		rra(stack_a, true);
	}
	// Case: 1 4 2 -> 4 1 2 -> 1 2 4
	else if (top < mid && mid > bot && top < bot)
	{
		rra(stack_a, true);
		sa(stack_a, true);
	}
	// Case: 2 1 4 -> 1 2 4
	else if (top > mid && mid < bot && top < bot)
	{
		sa(stack_a, true);
	}
}
void	sort_five(t_stack *a, t_stack *b)
{
	int		i;
	int		min;
	int		pos;
	t_node	*cur;

	// Empuja dos mínimos a la pila B
	for (i = 0; i < 2; i++)
	{
		min = find_min(a);
		pos = 0;
		cur = a->top;
		while (cur->value != min)
		{
			cur = cur->next;
			pos++;
		}
		// elegir la rotación más corta
		if (pos <= a->size / 2)
			while (a->top->value != min)
				ra(a, true);
		else
			while (a->top->value != min)
				rra(a, true);
		pb(a, b, true);
	}
	// Ordena los 3 restantes en A
	sort_three(a);
	pa(a, b, true);
	pa(a, b, true);
	if (b->top) // If b was not empty (i.e., we are sorting 5 elements, not 4)
		pa(a, b, true);
}

void	sort_small(t_stack *stack_a, t_stack *stack_b, int size)
{
	int		min_val;
	int		pos;
	t_node	*curr;

	if (size <= 1)
		return ;
	if (size == 2)
	{
		if (stack_a->top->value > stack_a->top->next->value)
			sa(stack_a, true);
		return ;
	}
	if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
	{
		// Push the smallest element to B
		min_val = find_min(stack_a);
		while (stack_a->top->value != min_val)
		{
			// Smart rotate: if val is in bottom half, rra, else ra
			pos = 0;
			curr = stack_a->top;
			while (curr && curr->value != min_val)
			{
				curr = curr->next;
				pos++;
			}
			if (pos <= stack_a->size / 2)
				ra(stack_a, true);
			else
				rra(stack_a, true);
		}
		pb(stack_a, stack_b, true);
		sort_three(stack_a);
		pa(stack_a, stack_b, true);
	}
	else if (size == 5)
		sort_five(stack_a, stack_b); // sort_five as implemented (pushes 2 to B)
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	int		chunk_size;
	int		current_chunk;
	int		i;
	int		total_chunks;
	int		stack_size;
	int		max;
	int		pos;
	t_node	*tmp;

	stack_size = a->size;
	if (stack_size <= 100)
		chunk_size = 20;
	else
		chunk_size = 45;
	total_chunks = (stack_size + chunk_size - 1) / chunk_size;
	current_chunk = 0;
	while (current_chunk < total_chunks)
	{
		i = 0;
		while (i < stack_size && a->size > 0)
		{
			if (a->top->index >= current_chunk * chunk_size
				&& a->top->index < (current_chunk + 1) * chunk_size)
			{
				pb(a, b, true);
				if (b->top->index < current_chunk * chunk_size + chunk_size / 2)
					rb(b, true);
			}
			else
				ra(a, true);
			i++;
		}
		current_chunk++;
	}
	while (!is_stack_empty(b))
	{
		max = find_max(b);
		pos = 0;
		tmp = b->top;
		while (tmp && tmp->value != max)
		{
			tmp = tmp->next;
			pos++;
		}
		if (pos <= b->size / 2)
			while (b->top->value != max)
				rb(b, true);
		else
			while (b->top->value != max)
				rrb(b, true);
		pa(a, b, true);
	}
}
