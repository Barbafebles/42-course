/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: placeholder <placeholder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:15:00 by placeholder          #+#    #+#             */
/*   Updated: 2023/10/27 10:15:00 by placeholder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h> // For strcmp in log_status

long long	get_current_time_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		// Handle error if necessary, though philo spec often assumes success
		perror("gettimeofday");
		return (-1); // Or some other error indicator
	}
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000LL));
}

long long	get_timestamp_ms(long long start_time)
{
	return (get_current_time_ms() - start_time);
}

void	log_status(t_philosopher *philo, const char *status_msg)
{
	long long	current_ts;
	int			sim_ended_check;

	pthread_mutex_lock(&philo->shared_data->death_mutex);
	sim_ended_check = philo->shared_data->simulation_should_end;
	pthread_mutex_unlock(&philo->shared_data->death_mutex);

	// Do not print messages if simulation has ended, except for "died"
	if (sim_ended_check && strcmp(status_msg, "died") != 0)
	{
		return;
	}

	pthread_mutex_lock(&philo->shared_data->print_mutex);
	// Re-check, in case status changed between first check and acquiring print_mutex
	// This is to ensure that once a philosopher is marked dead, no other philo prints
	// unless it's the death message itself.
	// However, the prompt implies the monitor is the primary controller of "simulation_should_end"
	// and this log function is mainly for atomicity of printing.
	// The first check should be sufficient if monitor sets flag and then logs death.
	if (philo->shared_data->simulation_should_end && strcmp(status_msg, "died") != 0)
	{
		pthread_mutex_unlock(&philo->shared_data->print_mutex);
		return;
	}
	current_ts = get_timestamp_ms(philo->shared_data->start_time);
	printf("%lld %d %s\n", current_ts, philo->id, status_msg);
	pthread_mutex_unlock(&philo->shared_data->print_mutex);
}

void	ft_usleep(long long milliseconds_to_wait, t_shared_data *shared_data)
{
	long long	start_sleep_time;
	int			sim_should_end_check;

	start_sleep_time = get_current_time_ms();
	while ((get_current_time_ms() - start_sleep_time) < milliseconds_to_wait)
	{
		pthread_mutex_lock(&shared_data->death_mutex);
		sim_should_end_check = shared_data->simulation_should_end;
		pthread_mutex_unlock(&shared_data->death_mutex);

		if (sim_should_end_check)
		{
			break;
		}
		usleep(500); // Sleep for 0.5 ms
	}
}
