/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: placeholder <placeholder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:25:00 by placeholder          #+#    #+#             */
/*   Updated: 2023/10/27 10:25:00 by placeholder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_simulation_end_conditions(t_philosopher *philo)
{
	int	sim_should_end;
	int	meals_limit_reached;

	pthread_mutex_lock(&philo->shared_data->death_mutex);
	sim_should_end = philo->shared_data->simulation_should_end;
	if (sim_should_end)
	{
		pthread_mutex_unlock(&philo->shared_data->death_mutex);
		return (1); // Simulation ended due to death or external signal
	}
	if (philo->shared_data->params.num_meals_limit != -1 && \
		philo->meals_eaten >= philo->shared_data->params.num_meals_limit)
	{
		// This philosopher has eaten enough.
		// The main monitor loop will eventually detect if all have eaten enough.
		// This philosopher can stop.
		// We don't set simulation_should_end here, monitor does.
		meals_limit_reached = 1;
	}
	else
	{
		meals_limit_reached = 0;
	}
	pthread_mutex_unlock(&philo->shared_data->death_mutex);
	return (sim_should_end || meals_limit_reached);
}

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;

	// Stagger start times for even-numbered philosophers
	if (philo->id % 2 == 0)
	{
		ft_usleep(philo->shared_data->params.time_to_eat / 2, philo->shared_data);
	}
    // For a single philosopher, they take a fork, wait to die (logged), and then stop.
    // The take_forks function handles this: it locks, logs, ft_usleeps for time_to_die*2, unlocks.
    // So, if N=1, take_forks will block until death or sim_end.
    if (philo->shared_data->params.num_philosophers == 1)
    {
        take_forks(philo); // This will log "has taken a fork"
                           // then ft_usleep for time_to_die * 2 (or until sim_end)
                           // then unlock the fork.
                           // The monitor will detect death.
        return (NULL); // Routine ends for the single philosopher.
    }

	while (1)
	{
		if (check_simulation_end_conditions(philo))
			break ;
		take_forks(philo);
		if (check_simulation_end_conditions(philo)) // Check after taking forks, esp. if N=1 was not handled earlier
		{
			release_forks(philo); // Release if acquired before breaking
			break;
		}
		philosopher_eat(philo); // Eat and update meal times
		release_forks(philo);

		if (check_simulation_end_conditions(philo))
			break ;
		philosopher_sleep(philo);

		if (check_simulation_end_conditions(philo))
			break ;
		philosopher_think(philo);
	}
	return (NULL);
}
