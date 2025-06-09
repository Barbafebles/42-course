/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: placeholder <placeholder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:35:00 by placeholder          #+#    #+#             */
/*   Updated: 2023/10/27 10:35:00 by placeholder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h> // For free
#include <stdio.h>  // For printf (error messages)

int	main(int argc, char **argv)
{
	t_simulation_params	params;
	t_shared_data		shared_data;
	t_philosopher		*philos;
	pthread_t			monitor_thread_id;
	int					i;

	philos = NULL; // Important for cleanup checks
	shared_data.fork_mutexes = NULL; // Important for cleanup checks

	if (parse_arguments(argc, argv, &params) != 0)
		return (1);
	if (init_shared_data(&shared_data, &params) != 0)
		return (1); // init_shared_data handles its own partial cleanup

	shared_data.start_time = get_current_time_ms();

	if (init_philosophers(&philos, &shared_data) != 0)
	{
		// shared_data was successfully initialized if we are here.
		// philos might be NULL or partially allocated if init_philosophers is complex,
		// but current init_philosophers only fails on philos array malloc.
		destroy_all_mutexes(&shared_data);
		free_allocated_memory(philos, &shared_data); // philos is likely NULL
		return (1);
	}

	// Create philosopher threads
	i = 0;
	while (i < params.num_philosophers)
	{
		if (pthread_create(&philos[i].thread_id, NULL, philosopher_routine, &philos[i]) != 0)
		{
			fprintf(stderr, "Error: Failed to create philosopher thread %d.\n", i + 1);
			pthread_mutex_lock(&shared_data.death_mutex);
			shared_data.simulation_should_end = 1;
			pthread_mutex_unlock(&shared_data.death_mutex);
			while (--i >= 0) // Join successfully created threads before this one
				pthread_join(philos[i].thread_id, NULL);
			destroy_all_mutexes(&shared_data);
			free_allocated_memory(philos, &shared_data);
			return (1);
		}
		i++;
	}

	// Create monitor thread
	if (pthread_create(&monitor_thread_id, NULL, monitor_simulation, philos) != 0)
	{
		fprintf(stderr, "Error: Failed to create monitor thread.\n");
		pthread_mutex_lock(&shared_data.death_mutex);
		shared_data.simulation_should_end = 1;
		pthread_mutex_unlock(&shared_data.death_mutex);
		i = 0; // Join all philosopher threads
		while (i < params.num_philosophers)
		{
			pthread_join(philos[i].thread_id, NULL);
			i++;
		}
		destroy_all_mutexes(&shared_data);
		free_allocated_memory(philos, &shared_data);
		return (1);
	}

	// Join philosopher threads
	i = 0;
	while (i < params.num_philosophers)
	{
		pthread_join(philos[i].thread_id, NULL);
		// Add error handling for join if needed, though often ignored for philo
		i++;
	}

	// Join monitor thread
	pthread_join(monitor_thread_id, NULL);
	// Add error handling for join if needed

	destroy_all_mutexes(&shared_data);
	free_allocated_memory(philos, &shared_data);
	return (0);
}
