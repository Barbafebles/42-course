/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: placeholder <placeholder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:30:00 by placeholder          #+#    #+#             */
/*   Updated: 2023/10/27 10:30:00 by placeholder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h> // For usleep

static int	check_philosopher_death(t_philosopher *philo)
{
	long long	current_time;
	long long	time_since_last_meal;
	int			sim_ended_locally; // To hold value after unlock

	pthread_mutex_lock(&philo->shared_data->death_mutex);
	if (philo->shared_data->simulation_should_end) // If already ended, don't re-evaluate
	{
		pthread_mutex_unlock(&philo->shared_data->death_mutex);
		return (0); // Death didn't happen in this check, but sim has ended
	}

	current_time = get_current_time_ms();
	time_since_last_meal = current_time - philo->last_meal_time;

	if (time_since_last_meal > philo->shared_data->params.time_to_die)
	{
		philo->shared_data->simulation_should_end = 1;
		sim_ended_locally = 1; // Mark that this call detected death
		pthread_mutex_unlock(&philo->shared_data->death_mutex);
		log_status(philo, "died"); // Log death after unlocking
		return (sim_ended_locally); // Return 1, philosopher died
	}

	pthread_mutex_unlock(&philo->shared_data->death_mutex);
	return (0); // Philosopher is alive
}

static int	check_all_philos_eaten_enough(t_philosopher *philos,
		t_shared_data *shared_data)
{
	int	i;
	int	all_eaten_count;
	int	num_philos;

	if (shared_data->params.num_meals_limit == -1)
		return (0); // Meal limit not active

	num_philos = shared_data->params.num_philosophers;
	all_eaten_count = 0;
	i = 0;
	while (i < num_philos)
	{
		pthread_mutex_lock(&shared_data->death_mutex);
		// Check if this philo has eaten enough
		if (philos[i].meals_eaten >= shared_data->params.num_meals_limit)
		{
			all_eaten_count++;
		}
		// Also, if simulation ended due to death while checking, stop early
		if (shared_data->simulation_should_end && all_eaten_count < num_philos)
		{
			pthread_mutex_unlock(&shared_data->death_mutex);
			return (0); // Death occurred, meal goal not relevant for ending sim now
		}
		pthread_mutex_unlock(&shared_data->death_mutex);
		i++;
	}

	if (all_eaten_count == num_philos)
	{
		pthread_mutex_lock(&shared_data->death_mutex);
		if (!shared_data->simulation_should_end) // Only set if not already ended by death
		{
			shared_data->simulation_should_end = 1;
		}
		pthread_mutex_unlock(&shared_data->death_mutex);
		return (1); // All philosophers have eaten enough
	}
	return (0); // Not all philosophers have eaten enough
}

void	*monitor_simulation(void *arg)
{
	t_philosopher	*philos;
	t_shared_data	*shared_data;
	int				i;
	int				sim_already_ended_check;

	philos = (t_philosopher *)arg;
	t_philosopher	*philos_array; // Renamed for clarity from philos to philos_array
	t_shared_data	*shared_data_ptr; // Renamed for clarity
	int				i;
	int				keep_monitoring;

	philos_array = (t_philosopher *)arg;
	if (!philos_array || !philos_array[0].shared_data) // Basic validation
		return (NULL);
	shared_data_ptr = philos_array[0].shared_data;
	keep_monitoring = 1;

	while (keep_monitoring)
	{
		pthread_mutex_lock(&shared_data_ptr->death_mutex);
		if (shared_data_ptr->simulation_should_end)
		{
			pthread_mutex_unlock(&shared_data_ptr->death_mutex);
			keep_monitoring = 0; // Simulation ended, exit monitor
			continue;            // Go to while condition check
		}
		pthread_mutex_unlock(&shared_data_ptr->death_mutex);

		i = 0;
		while (i < shared_data_ptr->params.num_philosophers)
		{
			if (check_philosopher_death(&philos_array[i]))
			{
				// This function sets shared_data_ptr->simulation_should_end = 1
				keep_monitoring = 0; // Signal to stop monitoring
				break;               // Exit philosopher checking loop
			}
			i++;
		}
		if (!keep_monitoring) // If a death was found in the loop above
			continue;

		if (shared_data_ptr->params.num_meals_limit != -1)
		{
			if (check_all_philos_eaten_enough(philos_array, shared_data_ptr))
			{
				// This function sets shared_data_ptr->simulation_should_end = 1
				keep_monitoring = 0; // Signal to stop monitoring
			}
		}
		if (!keep_monitoring) // If meal limit was met (or death found earlier)
			continue;

		usleep(1000); // Check roughly every 1ms
	}
	return (NULL);
}
