/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/05/22 17:34:01 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*init_stack(char name)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	stack->name = name;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(stack);
}

void	push_to_stack(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->index = -1;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

int	pop_from_stack(t_stack *stack)
{
	t_node	*temp;
	int		value;

	if (!stack->top)
		return (0);
	temp = stack->top;
	value = temp->value;
	stack->top = temp->next;
	free(temp);
	stack->size--;
	return (value);
}

int	is_stack_empty(t_stack *stack)
{
	return (stack->size == 0);
}

int	is_stack_sorted(t_stack *stack)
{
	t_node	*current;

	if (stack->size <= 1)
		return (1);
	current = stack->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	find_min(t_stack *stack)
{
	t_node	*current;
	int		min;

	if (!stack->top)
		return (0);
	current = stack->top;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	t_node	*current;
	int		max;

	if (!stack->top)
		return (0);
	current = stack->top;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

void	display_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_a;
	t_node	*current_b;

	current_a = stack_a ? stack_a->top : NULL;
	current_b = stack_b ? stack_b->top : NULL;
	write(1, "\n", 1);
	write(1, "Stack A:\t\tStack B:\n", 20); // Corrected size from 21 to 20
	write(1, "--------\t\t--------\n", 19);
	while (current_a || current_b)
	{
		if (current_a)
		{
			ft_putstr_fd(BLUE, 1);
			write(1, "  ", 2);
			write(1, &"0123456789"[current_a->value % 10], 1);
			write(1, &"0123456789"[current_a->value / 10 % 10], 1);
			write(1, "  ", 2);
			ft_putstr_fd(RESET, 1);
			current_a = current_a->next;
		}
		else
			write(1, "     ", 5);
		write(1, "\t\t", 2);
		if (current_b)
		{
			ft_putstr_fd(GREEN, 1);
			write(1, "  ", 2);
			write(1, &"0123456789"[current_b->value % 10], 1);
			write(1, &"0123456789"[current_b->value / 10 % 10], 1);
			write(1, "  ", 2);
			ft_putstr_fd(RESET, 1);
			current_b = current_b->next;
		}
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
}
