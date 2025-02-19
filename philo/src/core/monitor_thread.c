/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:56:30 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/19 18:46:40 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	stand_all_exit_flg(t_philosopher *philosophers)
{
	int				id;
	t_philosopher	*philosopher;

	id = 1;
	while (id <= philosophers->info->n_philosophers)
	{
		philosopher = get_philosopher(philosophers, id++);
		pthread_mutex_lock(&philosopher->exit_flg_mutex);
		philosopher->exit_flg = 1;
		pthread_mutex_unlock(&philosopher->exit_flg_mutex);
	}
	return ;
}

void	*monitor_thread(void *arg)
{
	t_philosopher	*philosophers;
	t_philosopher	*philosopher;

	philosophers = (t_philosopher *)arg;
	philosopher = get_philosopher(philosophers, 1);
	while (1)
	{
		if (is_all_full_stomach(philosophers))
		{
			stand_all_exit_flg(philosophers);
			// print_log(philosopher, "all philosophers are satisfied\n");
			return (NULL);
		}
		if (is_any_dead(philosopher))
		{
			stand_all_exit_flg(philosophers);
			print_log(philosopher, "died\n");
			return (NULL);
		}
		philosopher = philosopher->right_person;
	}
	return (NULL);
}

void	monitor(t_philosopher *philosophers)
{
	pthread_t	thread;
	void		*res;

	res = NULL;
	pthread_create(&thread, NULL, monitor_thread, philosophers);
	pthread_join(thread, res);
	return ;
}
