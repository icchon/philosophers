/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:55:35 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/19 16:45:43 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_info(t_info *info)
{
	printf("number_of_philosophers: %d\n", info->n_philosophers);
	printf("time_to_die: %d\n", info->time_to_die);
	printf("time_to_eat: %d\n", info->time_to_eat);
	printf("time_to_sleep: %d\n", info->time_to_sleep);
	if (info->must_eat_flg)
	{
		printf("philosopher_must_eat: %d\n", info->n_must_eat);
	}
	printf("\n");
	return ;
}

void	print_log(t_philosopher *philosopher, char *msg)
{
	double	passed;

	pthread_mutex_lock(&philosopher->info->print_mutex);
	passed = get_passed_time(philosopher->start_time);
	printf("%d %d %s", (int)passed, philosopher->id, msg);
	pthread_mutex_unlock(&philosopher->info->print_mutex);
	return ;
}

void	print_philosopher(t_philosopher *philosopher)
{
	if (!philosopher)
	{
		printf("philosopher is null\n");
		return ;
	}
	if (philosopher->info->n_philosophers == 1)
	{
		printf("[id: 1] <fork: 1>\n");
		return ;
	}
	printf("[id: %d] <fork: %d> [id: %d] <fork: %d> [id: %d]\n",
		philosopher->left_person->id, philosopher->left_fork->id,
		philosopher->id, philosopher->right_fork->id,
		philosopher->right_person->id);
	if (philosopher->status == EATING)
		printf("eating\n");
	if (philosopher->status == SLEEPING)
		printf("sleeping\n");
	if (philosopher->status == THINKING)
		printf("thinking\n");
	printf("\n");
	return ;
}

void	print_philosophers(t_philosopher *philosophers)
{
	t_philosopher	*philosopher;
	int				id;

	if (!philosophers)
	{
		printf("there is no philosopher\n");
	}
	philosopher = philosophers;
	id = philosopher->id;
	while (1)
	{
		print_philosopher(philosopher);
		philosopher = philosopher->right_person;
		if (id == philosopher->id)
		{
			return ;
		}
	}
}
