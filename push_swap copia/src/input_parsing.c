/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:34:50 by bfebles-          #+#    #+#             */
/*   Updated: 2025/05/22 17:45:08 by bfebles-         ###   ########.fr       */
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

int	parse_args(int argc, char **argv, t_stack *stack_a)
{
	char	**numbers_to_parse;
	int		i;
	bool	is_split_needed;
	int		count;

	is_split_needed = false;
	if (argc == 2)
	{
		numbers_to_parse = ft_split(argv[1], ' ');
		is_split_needed = true;
	}
	else
	{
		numbers_to_parse = argv + 1;
		// Directamente usar argv a partir del segundo elemento
	}
	if (!numbers_to_parse) // ft_split podría devolver NULL
		return (-1);
	// Contar los elementos primero para saber desde dónde empezar a empujar inversamente
	count = 0;
	if (is_split_needed)
	{
		while (numbers_to_parse[count])
			count++;
	}
	else
	{
		count = argc - 1; // Para argv, ya tenemos el conteo
	}
	i = count - 1; // Empieza desde el último índice válido
	while (i >= 0) // Itera hacia atrás
	{
		if (!is_valid_number(numbers_to_parse[i]))
		{
			if (is_split_needed)
				free_split_array(numbers_to_parse);
			return (-1);
		}
		if (is_split_needed && numbers_to_parse[i][0] == '\0')
		{
			free_split_array(numbers_to_parse);
			return (-1);
		}
		push_to_stack(stack_a, ft_atol(numbers_to_parse[i]));
		i--;
	}
	if (is_split_needed)
		free_split_array(numbers_to_parse);
	return (0);
}
