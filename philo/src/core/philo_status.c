/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:57:06 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/19 16:26:13 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_exit_flg(t_philosopher *philosopher)
{
	int	res;

	res = 0;
	pthread_mutex_lock(&philosopher->exit_flg_mutex);
	if (philosopher->exit_flg)
		res = 1;
	pthread_mutex_unlock(&philosopher->exit_flg_mutex);
	return (res);
}

int	is_dead(t_philosopher *philosopher)
{
	double	passed;
	int		res;

	res = 0;
	pthread_mutex_lock(&philosopher->last_meal_time_mutex);
	passed = get_passed_time(philosopher->last_meal_time);
	pthread_mutex_unlock(&philosopher->last_meal_time_mutex);
	if (passed > philosopher->info->time_to_die)
		res = 1;
	return (res);
}

int	is_full_stomach(t_philosopher *philosopher)
{
	int	res;

	pthread_mutex_lock(&philosopher->n_meals_mutex);
	res = philosopher->n_meals >= philosopher->info->n_must_eat;
	pthread_mutex_unlock(&philosopher->n_meals_mutex);
	return (res);
}

int	is_any_dead(t_philosopher *philosophers)
{
	int				id;
	t_philosopher	*philosopher;

	id = 1;
	while (id <= philosophers->info->n_philosophers)
	{
		philosopher = get_philosopher(philosophers, id);
		if (is_dead(philosopher))
		{
			return (1);
		}
		id++;
	}
	return (0);
}

int	is_all_full_stomach(t_philosopher *philosophers)
{
	int				id;
	t_philosopher	*philosopher;

	id = 1;
	while (id <= philosophers->info->n_philosophers)
	{
		philosopher = get_philosopher(philosophers, id);
		if (!is_full_stomach(philosopher))
		{
			return (0);
		}
		id++;
	}
	return (1);
}
