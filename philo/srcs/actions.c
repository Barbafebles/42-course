/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: placeholder <placeholder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:20:00 by placeholder          #+#    #+#             */
/*   Updated: 2023/10/27 10:20:00 by placeholder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Assigns forks based on philosopher ID to prevent deadlock.
// The last philosopher (or any one designated philosopher) picks up forks in a different order.
static void	assign_forks(t_philosopher *philo, pthread_mutex_t **first_fork,
		pthread_mutex_t **second_fork)
{
	// Most philosophers pick left then right.
	// The last philosopher picks right then left to break circular dependency.
	if (philo->id == philo->shared_data->params.num_philosophers)
	{
		*first_fork = philo->right_fork; // For last philo: fork_mutexes[0]
		*second_fork = philo->left_fork;  // For last philo: fork_mutexes[num_philosophers - 1]
	}
	else
	{
		*first_fork = philo->left_fork;
		*second_fork = philo->right_fork;
	}
}

void	take_forks(t_philosopher *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
	int				sim_should_end_check;

	assign_forks(philo, &first_fork, &second_fork);

	pthread_mutex_lock(&philo->shared_data->death_mutex);
	sim_should_end_check = philo->shared_data->simulation_should_end;
	pthread_mutex_unlock(&philo->shared_data->death_mutex);
	if (sim_should_end_check)
		return;

	pthread_mutex_lock(first_fork);
	log_status(philo, "has taken a fork");

	// Handle the case of a single philosopher
	if (philo->shared_data->params.num_philosophers == 1)
	{
		ft_usleep(philo->shared_data->params.time_to_die * 2, philo->shared_data); // Wait to die
		pthread_mutex_unlock(first_fork); // Release the only fork
		return;
	}

	pthread_mutex_lock(second_fork);
	log_status(philo, "has taken a fork");
}

void	philosopher_eat(t_philosopher *philo)
{
	int	sim_should_end_check;

	pthread_mutex_lock(&philo->shared_data->death_mutex);
	sim_should_end_check = philo->shared_data->simulation_should_end;
	if (sim_should_end_check)
	{
		pthread_mutex_unlock(&philo->shared_data->death_mutex);
		return;
	}
	// Update last_meal_time and meals_eaten atomically with death_mutex
	philo->last_meal_time = get_current_time_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->shared_data->death_mutex);

    log_status(philo, "is eating");

	ft_usleep(philo->shared_data->params.time_to_eat, philo->shared_data);
}

void	release_forks(t_philosopher *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	// For N=1, take_forks handles its own fork release and returns.
	// The routine should ideally not call release_forks for N=1 if take_forks completed the 'cycle'.
	// However, if it does, assign_forks needs to be consistent.
	// With current assign_forks:
	// If N=1, philo->id = 1. It's not philo->shared_data->params.num_philosophers (unless N=1, then id==N is true).
	// If N=1, id=1. assign_forks:
	//   if (1 == 1) -> last philo case. first=right (fork0), second=left (fork0).
	// This means it will try to unlock fork0, then fork0 again. This is bad.
	// The N=1 case in take_forks should be the sole handler of its fork.
	// The philosopher_routine should reflect this.
	if (philo->shared_data->params.num_philosophers == 1)
	{
		// The single fork is taken and released within take_forks.
		// No action needed here.
		return;
	}

	assign_forks(philo, &first_fork, &second_fork);
	// Unlock in reverse order of locking
	pthread_mutex_unlock(second_fork);
	pthread_mutex_unlock(first_fork);
}

void	philosopher_sleep(t_philosopher *philo)
{
	int	sim_should_end_check;

	pthread_mutex_lock(&philo->shared_data->death_mutex);
	sim_should_end_check = philo->shared_data->simulation_should_end;
	pthread_mutex_unlock(&philo->shared_data->death_mutex);
	if (sim_should_end_check)
		return;

	log_status(philo, "is sleeping");
	ft_usleep(philo->shared_data->params.time_to_sleep, philo->shared_data);
}

void	philosopher_think(t_philosopher *philo)
{
	int	sim_should_end_check;

	pthread_mutex_lock(&philo->shared_data->death_mutex);
	sim_should_end_check = philo->shared_data->simulation_should_end;
	pthread_mutex_unlock(&philo->shared_data->death_mutex);
	if (sim_should_end_check)
		return;

	log_status(philo, "is thinking");
	// Optional small delay for thinking if needed, e.g. usleep(100);
	// Or, make thinking adaptive: if a philo just ate and slept, and other philos are hungry,
	// it might think for a very short time.
	// For now, thinking is just a state.
}
