/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:56:30 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/17 23:18:16 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitor_thread(void *arg)
{
	t_philosopher	*philosophers;
	t_philosopher	*philosopher;

	philosophers = (t_philosopher *)arg;
	philosopher = get_philosopher(philosophers, 1);
	while (1)
	{
		if (is_dead(philosopher))
		{
			usleep(1000 * 5);
			print_log(philosopher, "is dead\n");
			return (NULL);
		}
		if (is_full_stomach(philosopher))
		{
			usleep(1000 * 5);
			print_log(philosopher, "all philosophers are satisfied\n");
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
