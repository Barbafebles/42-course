/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/06/06 15:42:51 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	bubble_sort(int *arr, int size);
static int	*create_and_fill_array(t_stack *stack_a, int size);
static void	assign_idx_to_stack_nodes(t_stack *stack_a, int *sorted_arr,
				int size);

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

static void	assign_idx_to_stack_nodes(t_stack *stack_a, int *sorted_arr,
		int size)
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
				current->index = i;
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
