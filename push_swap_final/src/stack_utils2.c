/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 20:42:57 by bfebles-          #+#    #+#             */
/*   Updated: 2025/06/06 15:13:39 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

static void	print_stack_headers(void)
{
	ft_putstr_fd("\nStack A:		Stack B:\n", STDOUT_FILENO);
	ft_putstr_fd("--------		--------\n", STDOUT_FILENO);
}

static void	print_stack_row(t_node **curr_a, t_node **curr_b)
{
	if (*curr_a)
	{
		ft_putstr_fd((char *)BLUE, STDOUT_FILENO);
		ft_putnbr_fd((*curr_a)->value, STDOUT_FILENO);
		ft_putstr_fd((char *)RESET, STDOUT_FILENO);
		*curr_a = (*curr_a)->next;
	}
	else
		ft_putstr_fd("    ", STDOUT_FILENO);
	ft_putstr_fd("		", STDOUT_FILENO);
	if (*curr_b)
	{
		ft_putstr_fd((char *)GREEN, STDOUT_FILENO);
		ft_putnbr_fd((*curr_b)->value, STDOUT_FILENO);
		ft_putstr_fd((char *)RESET, STDOUT_FILENO);
		*curr_b = (*curr_b)->next;
	}
	else
		ft_putstr_fd("    ", STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
}

void	display_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*curr_a;
	t_node	*curr_b;

	if (stack_a != NULL)
		curr_a = stack_a->top;
	else
		curr_a = NULL;
	if (stack_b != NULL)
		curr_b = stack_b->top;
	else
		curr_b = NULL;
	print_stack_headers();
	while (curr_a || curr_b)
		print_stack_row(&curr_a, &curr_b);
	ft_putstr_fd("\n", STDOUT_FILENO);
}
