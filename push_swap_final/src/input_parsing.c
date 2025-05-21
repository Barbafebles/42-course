/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/05/02 12:37:31 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * Converts a string to a long integer
 * Handles negative numbers and overflow/underflow
 */
long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/*
 * Checks if a string represents a valid integer
 * Returns 1 if valid, 0 if invalid
 */
int	is_valid_number(char *str)
{
	int		i;
	long	num;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

/**
 * Checks if stack contains duplicate values
 * Returns 1 if duplicates found, 0 otherwise
 */
int	has_duplicates(t_stack *stack)
{
	t_node	*current;
	t_node	*check;

	current = stack->top;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}

/*
 * Parse command line arguments and populate stack_a
 * Returns 0 on success, -1 on error
 */
 int	parse_args(int argc, char **argv, t_stack *stack_a)
 {
	 int		i;
	 long	num;
 
	 i = argc - 1;
	 while (i > 0)
	 {
		 if (!is_valid_number(argv[i]))
			 return (-1);
		 num = ft_atol(argv[i]);
		 push_to_stack(stack_a, (int)num);
		 i--;
	 }
	 return (0);
 }
 