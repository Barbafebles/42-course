/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles <bfebles-student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:34:50 by bfebles-          #+#    #+#             */
/*   Updated: 2025/05/24 11:05:00 by Jules             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h> // For NULL, free
#include <stdbool.h> // For bool

// Forward declarations for static helper functions
static char	**prepare_numbers_array(int argc, char **argv, 										bool *is_split_needed_ptr);
static int	process_individual_arg_content(t_stack *stack_a, char *arg_str);
static int	process_all_arguments(t_stack *stack_a, char **numbers, 									int count, bool is_split_needed);

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
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[1] == '\0') // Handles only sign e.g. "+"
			return (0);
		i++;
	}
	if (str[i] == '\0') // Handles empty string post-sign, or if "" was passed
		return (0);      // (parse_args should catch fully empty first)
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

static char	**prepare_numbers_array(int argc, char **argv, 										bool *is_split_needed_ptr)
{
	char	*temp_check_empty;
	char	**numbers_to_parse;

	if (argc == 2)
	{
		*is_split_needed_ptr = true;
		temp_check_empty = ft_strtrim(argv[1], " \t\n\v\f\r");
		if (!temp_check_empty)
			return (NULL); // Malloc error
		if (temp_check_empty[0] == '\0')
		{
			free(temp_check_empty);
			return (NULL); // Input like "./push_swap \"    \""
		}
		free(temp_check_empty);
		numbers_to_parse = ft_split(argv[1], ' ');
		if (!numbers_to_parse || numbers_to_parse[0] == NULL)
		{
			if (numbers_to_parse) // Case ft_split returns {NULL}
				free_split_array(numbers_to_parse);
			return (NULL);
		}
		return (numbers_to_parse);
	}
	*is_split_needed_ptr = false;
	return (argv + 1);
}

static int	process_individual_arg_content(t_stack *stack_a, char *arg_str)
{
	char	*trimmed_arg;

	trimmed_arg = ft_strtrim(arg_str, " \t\n\v\f\r");
	if (!trimmed_arg)
		return (-1); // Malloc error
	if (trimmed_arg[0] == '\0')
	{
		free(trimmed_arg);
		return (-1); // Invalid: empty number string
	}
	if (!is_valid_number(trimmed_arg))
	{
		free(trimmed_arg);
		return (-1); // Invalid number format or overflow
	}
	push_to_stack(stack_a, ft_atol(trimmed_arg));
	free(trimmed_arg);
	return (0); // Success
}

static int	process_all_arguments(t_stack *stack_a, char **numbers, 									int count, bool is_split_needed)
{
	int	i;
	int	result;

	i = count - 1; // Iterate backwards to push in correct order
	while (i >= 0)
	{
		result = process_individual_arg_content(stack_a, numbers[i]);
		if (result == -1)
		{
			// Error occurred, free the array if it was split
			if (is_split_needed)
				free_split_array(numbers);
			return (-1);
		}
		i--;
	}
	// Success, free the array if it was split
	if (is_split_needed)
		free_split_array(numbers);
	return (0);
}

// Main parsing function, now refactored and shorter.
int	parse_args(int argc, char **argv, t_stack *stack_a)
{
	char	**numbers_to_parse;
	bool	is_split_needed;
	int		count;

	if (argc < 2)
		return (-1);
	// is_split_needed is initialized by prepare_numbers_array via pointer
	numbers_to_parse = prepare_numbers_array(argc, argv, &is_split_needed);
	if (!numbers_to_parse)
		return (-1); // Error in preparation (malloc or empty essential arg)
	count = 0;
	if (is_split_needed)
	{
		while (numbers_to_parse[count])
			count++;
	}
	else
		count = argc - 1; // Number of args (excluding program name)
	if (count == 0) // No numbers to parse
	{
		if (is_split_needed) // Free if ft_split allocated it
			free_split_array(numbers_to_parse);
		return (-1);
	}
	return (process_all_arguments(stack_a, numbers_to_parse, count, 									is_split_needed));
}
