/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:58:23 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/19 16:58:16 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	init_philo_thread(t_philosopher *philosopher)
{
	philosopher->status = THINKING;
	print_log(philosopher, "is thinking\n");
	if (philosopher->info->n_philosophers % 2 == 0)
		if (philosopher->id % 2 == 0)
			usleep((philosopher->info->time_to_eat * 1000) / 2);
	return ;
}

void	*philo_thread(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	if (is_exit_flg(philosopher) || is_dead(philosopher))
		return (NULL);
	init_philo_thread(philosopher);
	while (1)
	{
		if (is_exit_flg(philosopher) || is_dead(philosopher))
			return (NULL);
		do_eat(philosopher);
		if (is_exit_flg(philosopher))
			return (NULL);
		do_sleep(philosopher);
		if (is_exit_flg(philosopher) || is_dead(philosopher))
			return (NULL);
		if (philosopher->info->n_philosophers % 2 == 1
			&& philosopher->info->n_philosophers >= 2)
		{
			print_log(philosopher, "is thinking\n");
			usleep(philosopher->info->time_to_eat * 1000
				/ philosopher->info->n_philosophers);
		}
	}
}

int	simulate(t_philosopher *philosophers)
{
	int				id;
	t_philosopher	*philosopher;
	void			*res;

	res = NULL;
	id = 1;
	if (!philosophers)
		return (EXIT_FAILURE);
	while (id <= philosophers->info->n_philosophers)
	{
		philosopher = get_philosopher(philosophers, id++);
		if (pthread_create(&philosopher->pthread, NULL, philo_thread,
				philosopher) < 0)
			return (EXIT_FAILURE);
	}
	monitor(philosophers);
	id = 1;
	while (id <= philosophers->info->n_philosophers)
	{
		philosopher = get_philosopher(philosophers, id++);
		if (pthread_join(philosopher->pthread, NULL) < 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
