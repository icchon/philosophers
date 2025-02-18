/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:57:06 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/17 22:37:30 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// pthread_mutex_t	dead_mutex;

int	is_dead(t_philosopher *philosopher)
{
	double	passed;

	passed = get_passed_time(philosopher->last_meal_time);
	if (passed > philosopher->info.time_to_die)
	{
		philosopher->status = DEAD;
		return (1);
	}
	return (0);
}

int	is_full_stomach(t_philosopher *philosopher)
{
	return (philosopher->n_meals >= philosopher->info.n_must_eat);
}

int	is_all_full_stomach(t_philosopher *philosophers)
{
	int				id;
	t_philosopher	*philosopher;

	id = 1;
	while (id <= philosophers->info.n_philosophers)
	{
		philosopher = get_philosopher(philosophers, id);
		if (!is_full_stomach(philosopher))
			return (0);
		id++;
	}
	return (1);
}
