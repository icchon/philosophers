/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:54:02 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/19 18:43:19 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	do_sleep(t_philosopher *philosopher)
{
	if (philosopher->info->n_philosophers == 1)
		return (0);
	philosopher->status = SLEEPING;
	print_log(philosopher, "is sleeping\n");
	usleep(philosopher->info->time_to_sleep * 1000);
	philosopher->status = THINKING;
	return (1);
}

int	do_eat(t_philosopher *philosopher)
{
	if (philosopher->info->n_philosophers == 1)
		return (0);
	if (philosopher->status != THINKING)
	{
		print_log(philosopher, "is thinking\n");
		philosopher->status = THINKING;
	}
	if (!take_forks(philosopher))
	{
		if (is_exit_flg(philosopher) || is_dead(philosopher))
			return (release_forks(philosopher), 0);
	}
	philosopher->status = EATING;
	print_log(philosopher, "is eating\n");
	pthread_mutex_lock(&philosopher->last_meal_time_mutex);
	gettimeofday(&philosopher->last_meal_time, NULL);
	pthread_mutex_unlock(&philosopher->last_meal_time_mutex);
	usleep(philosopher->info->time_to_eat * 1000);
	pthread_mutex_lock(&philosopher->n_meals_mutex);
	philosopher->n_meals++;
	pthread_mutex_unlock(&philosopher->n_meals_mutex);
	release_forks(philosopher);
	return (1);
}
