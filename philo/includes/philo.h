/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: placeholder <placeholder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:00:00 by placeholder          #+#    #+#             */
/*   Updated: 2023/10/27 10:00:00 by placeholder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H_
# define PHILO_H_

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

struct s_shared_data; // Forward declaration

typedef struct s_philosopher
{
	int					id;
	pthread_t			thread_id;
	long long			last_meal_time;
	int					meals_eaten;
	struct s_shared_data	*shared_data;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
}	t_philosopher;

typedef struct s_simulation_params
{
	int					num_philosophers;
	long long			time_to_die;
	long long			time_to_eat;
	long long			time_to_sleep;
	int					num_meals_limit;
}	t_simulation_params;

typedef struct s_shared_data
{
	t_simulation_params	params;
	long long			start_time;
	pthread_mutex_t		*fork_mutexes;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		death_mutex;
	int					simulation_should_end;
}	t_shared_data;

// Function prototypes

// args.c
int		parse_arguments(int argc, char **argv, t_simulation_params *params);

// init.c
int		init_shared_data(t_shared_data *shared, t_simulation_params *params);
int		init_philosophers(t_philosopher **philos_array, t_shared_data *shared_data);

// utils.c
long long	get_current_time_ms(void);
long long	get_timestamp_ms(long long start_time);
void		log_status(t_philosopher *philo, const char *status_msg);
void		ft_usleep(long long milliseconds_to_wait, t_shared_data *shared_data);

// actions.c
void		take_forks(t_philosopher *philo);
void		philosopher_eat(t_philosopher *philo);
void		release_forks(t_philosopher *philo);
void		philosopher_sleep(t_philosopher *philo);
void		philosopher_think(t_philosopher *philo);

// routine.c
void		*philosopher_routine(void *arg);

// monitor.c
void		*monitor_simulation(void *arg);

// cleanup.c
void		destroy_all_mutexes(t_shared_data *shared_data);
void		free_allocated_memory(t_philosopher *philos, t_shared_data *shared_data);

#endif // PHILO_H_
