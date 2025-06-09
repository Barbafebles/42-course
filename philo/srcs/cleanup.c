/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: placeholder <placeholder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:40:00 by placeholder          #+#    #+#             */
/*   Updated: 2023/10/27 10:40:00 by placeholder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h> // For free

void	destroy_all_mutexes(t_shared_data *shared_data)
{
	int	i;

	if (!shared_data)
		return;
	// Fork mutexes are initialized in init_shared_data.
	// If init_shared_data failed during fork mutex init, it cleans them up.
	// So, if fork_mutexes is not NULL here, they should all be valid for destroy.
	if (shared_data->fork_mutexes != NULL)
	{
		i = 0;
		while (i < shared_data->params.num_philosophers)
		{
			pthread_mutex_destroy(&shared_data->fork_mutexes[i]);
			i++;
		}
	}
	// print_mutex and death_mutex are assumed initialized if init_shared_data succeeded.
	// init_shared_data also cleans these up if it fails after their init.
	pthread_mutex_destroy(&shared_data->print_mutex);
	pthread_mutex_destroy(&shared_data->death_mutex);
}

void	free_allocated_memory(t_philosopher *philos, t_shared_data *shared_data)
{
	if (shared_data && shared_data->fork_mutexes != NULL)
	{
		free(shared_data->fork_mutexes);
		shared_data->fork_mutexes = NULL;
	}
	if (philos != NULL)
	{
		free(philos);
		// philos = NULL; // This would only set the local copy of the pointer to NULL
	}
}
