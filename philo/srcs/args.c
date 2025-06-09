/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: placeholder <placeholder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:05:00 by placeholder          #+#    #+#             */
/*   Updated: 2023/10/27 10:05:00 by placeholder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <string.h> // For strcmp in error messages, not strictly needed for norm

// Helper to check if string is all digits
static int	is_all_digits(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static long	ft_atol(const char *str)
{
	long	result;
	int		i;

	result = 0;
	i = 0;
	if (!str || !*str) // Handle empty or NULL string
		return (-1); // Indicate error
	if (str[i] == '+')
		i++;
	if (!is_all_digits(str + i)) // Check remaining part
		return (-1); // Indicate error: non-digit found
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > ( __LONG_MAX__ / 10) || \
			(result == ( __LONG_MAX__ / 10) && (str[i] - '0') > ( __LONG_MAX__ % 10)))
			return (-1); // Indicate overflow error
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0') // Check for trailing non-digit characters
		return (-1); // Indicate error
	return (result);
}

int	parse_arguments(int argc, char **argv, t_simulation_params *params)
{
	if (argc < 5 || argc > 6)
	{
		fprintf(stderr, "Error: Invalid number of arguments.\nUsage: %s num_philosophers time_to_die time_to_eat time_to_sleep [num_meals_limit]\n", argv[0]);
		return (1);
	}
	params->num_philosophers = (int)ft_atol(argv[1]);
	params->time_to_die = ft_atol(argv[2]);
	params->time_to_eat = ft_atol(argv[3]);
	params->time_to_sleep = ft_atol(argv[4]);

	if (params->num_philosophers <= 0 || params->time_to_die <= 0 || \
		params->time_to_eat <= 0 || params->time_to_sleep <= 0)
	{
		fprintf(stderr, "Error: All parameters must be positive integers.\n");
		return (1);
	}
	if (argc == 6)
	{
		params->num_meals_limit = (int)ft_atol(argv[5]);
		if (params->num_meals_limit <= 0)
		{
			fprintf(stderr, "Error: Number of meals limit must be a positive integer.\n");
			return (1);
		}
	}
	else
	{
		params->num_meals_limit = -1;
	}
	return (0);
}
