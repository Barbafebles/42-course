/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:34:50 by bfebles-          #+#    #+#             */
/*   Updated: 2025/06/05 15:18:36 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	**prepare_numbers_array(int argc, char **argv,
				bool *is_split_needed_ptr);
static int	process_individual_arg_content(t_stack *stack_a, char *arg_str);
static int	process_all_arguments(t_stack *stack_a, char **numbers, int count,
				bool is_split_needed);

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

static char	**prepare_numbers_array(int argc, char **argv,
		bool *is_split_needed_ptr)
{
	char	*temp_check_empty;
	char	**numbers_to_parse;

	if (argc == 2)
	{
		*is_split_needed_ptr = true;
		temp_check_empty = ft_strtrim(argv[1], " \t\n\v\f\r");
		if (!temp_check_empty)
			return (NULL);
		if (temp_check_empty[0] == '\0')
		{
			free(temp_check_empty);
			return (NULL);
		}
		free(temp_check_empty);
		numbers_to_parse = ft_split(argv[1], ' ');
		if (!numbers_to_parse || numbers_to_parse[0] == NULL)
		{
			if (numbers_to_parse)
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
		return (-1);
	if (trimmed_arg[0] == '\0')
	{
		free(trimmed_arg);
		return (-1);
	}
	if (!is_valid_number(trimmed_arg))
	{
		free(trimmed_arg);
		return (-1);
	}
	push_to_stack(stack_a, ft_atol(trimmed_arg));
	free(trimmed_arg);
	return (0);
}

static int	process_all_arguments(t_stack *stack_a, char **numbers, int count,
		bool is_split_needed)
{
	int	i;
	int	result;

	i = count - 1;
	while (i >= 0)
	{
		result = process_individual_arg_content(stack_a, numbers[i]);
		if (result == -1)
		{
			if (is_split_needed)
				free_split_array(numbers);
			return (-1);
		}
		i--;
	}
	if (is_split_needed)
		free_split_array(numbers);
	return (0);
}

int	parse_args(int argc, char **argv, t_stack *stack_a)
{
	char	**numbers_to_parse;
	bool	is_split_needed;
	int		count;

	if (argc < 2)
		return (-1);
	numbers_to_parse = prepare_numbers_array(argc, argv, &is_split_needed);
	if (!numbers_to_parse)
		return (-1);
	count = 0;
	if (is_split_needed)
	{
		while (numbers_to_parse[count])
			count++;
	}
	else
		count = argc - 1;
	if (count == 0)
	{
		if (is_split_needed)
			free_split_array(numbers_to_parse);
		return (-1);
	}
	return (process_all_arguments(stack_a, numbers_to_parse, count,
			is_split_needed));
}
