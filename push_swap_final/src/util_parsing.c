/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:41:49 by bfebles-          #+#    #+#             */
/*   Updated: 2025/06/06 15:14:22 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	is_valid_number(char *str)
{
	long	value;
	long	limit;
	int		i;
	int		digit;

	if (!str || !str[0])
		return (0);
	i = 0;
	limit = INT_MAX;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			limit = (long)INT_MAX + 1;
		i++;
	}
	if (!str[i])
		return (0);
	value = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		digit = str[i++] - '0';
		if (value > (limit - digit) / 10)
			return (0);
		value = value * 10 + digit;
	}
	return (1);
}

void	free_split_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	has_duplicates(t_stack *stack)
{
	t_node	*current;
	t_node	*runner;

	current = stack->top;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->value == runner->value)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}
