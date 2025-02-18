/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:54:02 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/17 21:06:13 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	do_sleep(t_philosopher *philosopher)
{
	philosopher->status = SLEEPING;
	print_log(philosopher, "is sleeping\n");
	usleep(philosopher->info.time_to_sleep * 1000);
	philosopher->status = THINKING;
	if (philosopher->info.n_philosophers % 2 == 1)
	{
		print_log(philosopher, "is thinking\n");
		usleep(philosopher->info.time_to_eat * 1000
			/ philosopher->info.n_philosophers);
	}
	return ;
}

void	do_eat(t_philosopher *philosopher)
{
	if (philosopher->status != THINKING)
	{
		print_log(philosopher, "is thinking\n");
		philosopher->status = THINKING;
	}
	take_forks(philosopher);
	philosopher->status = EATING;
	print_log(philosopher, "is eating\n");
	gettimeofday(&philosopher->last_meal_time, NULL);
	usleep(philosopher->info.time_to_eat * 1000);
	philosopher->n_meals++;
	release_forks(philosopher);
	return ;
}
