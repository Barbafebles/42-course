/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <jules@example.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:00:00 by original_author   #+#    #+#             */
/*   Updated: 2025/05/25 by Jules                      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>

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

	if (!stack)
		return;
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

	if (!stack || !stack->top)
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
	if (!stack)
		return (1);
	return (stack->size == 0);
}

int	is_stack_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || stack->size <= 1)
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
	int		min_val;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	min_val = current->value;
	current = current->next;
	while (current)
	{
		if (current->value < min_val)
			min_val = current->value;
		current = current->next;
	}
	return (min_val);
}

int	find_max(t_stack *stack)
{
	t_node	*current;
	int		max_val;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	max_val = current->value;
	current = current->next;
	while (current)
	{
		if (current->value > max_val)
			max_val = current->value;
		current = current->next;
	}
	return (max_val);
}

void	display_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*curr_a;
	t_node	*curr_b;

	curr_a = NULL;
	curr_b = NULL;
	if (stack_a != NULL)
		curr_a = stack_a->top;
	if (stack_b != NULL)
		curr_b = stack_b->top;
	ft_putstr_fd("\nStack A:		Stack B:\n", STDOUT_FILENO);
	ft_putstr_fd("--------		--------\n", STDOUT_FILENO);
	while (curr_a || curr_b)
	{
		if (curr_a)
		{
			ft_putstr_fd((char *)BLUE, STDOUT_FILENO);
			ft_putnbr_fd(curr_a->value, STDOUT_FILENO);
			ft_putstr_fd((char *)RESET, STDOUT_FILENO);
			curr_a = curr_a->next;
		}
		else
			ft_putstr_fd("    ", STDOUT_FILENO);
		ft_putstr_fd("		", STDOUT_FILENO);
		if (curr_b)
		{
			ft_putstr_fd((char *)GREEN, STDOUT_FILENO);
			ft_putnbr_fd(curr_b->value, STDOUT_FILENO);
			ft_putstr_fd((char *)RESET, STDOUT_FILENO);
			curr_b = curr_b->next;
		}
		else
			ft_putstr_fd("    ", STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	ft_putstr_fd("\n", STDOUT_FILENO);
}
