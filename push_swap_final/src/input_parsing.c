/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles <bfebles-student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:34:50 by bfebles-          #+#    #+#             */
/*   Updated: 2025/05/23 11:30:00 by Jules             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h" // For t_stack, INT_MAX, INT_MIN, ft_isspace, ft_isdigit, ft_split, ft_strtrim, push_to_stack etc.
#include <stdlib.h> // For free, NULL
#include <stdbool.h> // For bool

// Assuming ft_atol from the original file:
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

// Assuming is_valid_number from the original file:
int	is_valid_number(char *str)
{
	int		i;
	long	num;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[1] == '\0')
			return (0);
		i++;
	}

	if (str[i] == '\0' && i > 0)
		return (0);

	if (str[i] == '\0' && i == 0)
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

// Assuming has_duplicates from the original file
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

// Assuming free_split_array from the original file:
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

// Modified parse_args function:
int	parse_args(int argc, char **argv, t_stack *stack_a)
{
	char	**numbers_to_parse;
	char	*trimmed_arg;
	int		i;
	bool	is_split_needed;
	int		count;

	is_split_needed = false;

	if (argc == 2)
	{
		char *temp_check_empty = ft_strtrim(argv[1], " \t\n\v\f\r");
		if (!temp_check_empty) {
		    return (-1);
		}
		if (temp_check_empty[0] == '\0') {
		    free(temp_check_empty);
		    return (-1);
		}
		free(temp_check_empty);

		numbers_to_parse = ft_split(argv[1], ' ');
		is_split_needed = true;
		if (!numbers_to_parse)
			return (-1);

		if (numbers_to_parse[0] == NULL) {
		    free_split_array(numbers_to_parse);
		    return (-1);
		}
	}
	else
	{
		numbers_to_parse = argv + 1;
	}

	count = 0;
	if (is_split_needed)
	{
		while (numbers_to_parse[count])
			count++;
	}
	else
	{
		count = argc - 1;
	}

	if (count == 0)
	{
		if (is_split_needed)
			free_split_array(numbers_to_parse);
		return (-1);
	}

	i = count - 1;
	while (i >= 0)
	{
		trimmed_arg = ft_strtrim(numbers_to_parse[i], " \t\n\v\f\r");
		if (!trimmed_arg)
		{
			if (is_split_needed)
				free_split_array(numbers_to_parse);
			return (-1);
		}

		if (trimmed_arg[0] == '\0')
		{
			free(trimmed_arg);
			if (is_split_needed)
				free_split_array(numbers_to_parse);
			return (-1);
		}

		if (!is_valid_number(trimmed_arg))
		{
			free(trimmed_arg);
			if (is_split_needed)
				free_split_array(numbers_to_parse);
			return (-1);
		}

		push_to_stack(stack_a, ft_atol(trimmed_arg));
		free(trimmed_arg);

		i--;
	}

	if (is_split_needed)
		free_split_array(numbers_to_parse);

	return (0);
}
