/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: placeholder <placeholder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:10:00 by placeholder          #+#    #+#             */
/*   Updated: 2023/10/27 10:10:00 by placeholder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_shared_data(t_shared_data *shared, t_simulation_params *params)
{
	int	i;

	shared->params = *params;
	shared->start_time = 0; // To be set precisely later, e.g., get_current_time_ms()
	shared->simulation_should_end = 0;
	shared->fork_mutexes = malloc(sizeof(pthread_mutex_t) * params->num_philosophers);
	if (!shared->fork_mutexes)
	{
		fprintf(stderr, "Error: Malloc failed for fork_mutexes.\n");
		return (1);
	}
	i = 0;
	while (i < params->num_philosophers)
	{
		if (pthread_mutex_init(&shared->fork_mutexes[i], NULL) != 0)
		{
			fprintf(stderr, "Error: pthread_mutex_init failed for fork %d.\n", i);
			while (--i >= 0)
				pthread_mutex_destroy(&shared->fork_mutexes[i]);
			free(shared->fork_mutexes);
			return (1);
		}
		i++;
	}
	if (pthread_mutex_init(&shared->print_mutex, NULL) != 0)
	{
		fprintf(stderr, "Error: pthread_mutex_init failed for print_mutex.\n");
		i = params->num_philosophers;
		while (--i >= 0)
			pthread_mutex_destroy(&shared->fork_mutexes[i]);
		free(shared->fork_mutexes);
		return (1);
	}
	if (pthread_mutex_init(&shared->death_mutex, NULL) != 0)
	{
		fprintf(stderr, "Error: pthread_mutex_init failed for death_mutex.\n");
		pthread_mutex_destroy(&shared->print_mutex);
		i = params->num_philosophers;
		while (--i >= 0)
			pthread_mutex_destroy(&shared->fork_mutexes[i]);
		free(shared->fork_mutexes);
		return (1);
	}
	return (0);
}

int	init_philosophers(t_philosopher **philos_array, t_shared_data *shared_data)
{
	int	i;
	int	num_philos;

	num_philos = shared_data->params.num_philosophers;
	*philos_array = malloc(sizeof(t_philosopher) * num_philos);
	if (!*philos_array)
	{
		fprintf(stderr, "Error: Malloc failed for philosophers array.\n");
		return (1);
	}
	i = 0;
	while (i < num_philos)
	{
		(*philos_array)[i].id = i + 1;
		(*philos_array)[i].thread_id = 0; // Will be set by pthread_create
		(*philos_array)[i].last_meal_time = shared_data->start_time; // Will be updated
		(*philos_array)[i].meals_eaten = 0;
		(*philos_array)[i].shared_data = shared_data;
		(*philos_array)[i].left_fork = &shared_data->fork_mutexes[i];
		(*philos_array)[i].right_fork = &shared_data->fork_mutexes[(i + 1) % num_philos];
		i++;
	}
	return (0);
}
