/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_philosopher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:53:10 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/19 16:38:24 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philosopher	*new_philosopher(int id, t_info *info)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)malloc(sizeof(t_philosopher));
	if (!philosopher)
		return (NULL);
	philosopher->id = id;
	philosopher->status = THINKING;
	philosopher->left_fork = NULL;
	philosopher->right_fork = NULL;
	philosopher->left_person = NULL;
	philosopher->right_person = NULL;
	philosopher->info = info;
	philosopher->n_meals = 0;
	philosopher->exit_flg = 0;
	gettimeofday(&philosopher->start_time, NULL);
	gettimeofday(&philosopher->last_meal_time, NULL);
	pthread_mutex_init(&philosopher->last_meal_time_mutex, NULL);
	pthread_mutex_init(&philosopher->n_meals_mutex, NULL);
	pthread_mutex_init(&philosopher->exit_flg_mutex, NULL);
	return (philosopher);
}

t_philosopher	*get_philosopher(t_philosopher *philosophers, int id)
{
	t_philosopher	*philosopher;

	philosopher = philosophers;
	if (!philosophers)
		return (NULL);
	while (1)
	{
		if (philosopher->id == id)
		{
			return (philosopher);
		}
		if (!philosopher->right_person)
			break ;
		philosopher = philosopher->right_person;
	}
	while (1)
	{
		if (philosopher->id == id)
		{
			return (philosopher);
		}
		philosopher = philosopher->left_person;
	}
	return (NULL);
}

static void	set_forks(t_philosopher *philosophers)
{
	int				id;
	t_philosopher	*philosopher;

	id = 1;
	while (id <= philosophers->info->n_philosophers)
	{
		philosopher = get_philosopher(philosophers, id);
		philosopher->right_fork = new_fork(philosopher->id);
		id++;
	}
	if (philosopher->info->n_philosophers == 1)
		return ;
	id = 1;
	while (id <= philosophers->info->n_philosophers)
	{
		philosopher = get_philosopher(philosophers, id);
		philosopher->left_fork = philosopher->left_person->right_fork;
		id++;
	}
	return ;
}

t_philosopher	*new_philosophers(t_info *info)
{
	t_philosopher	*prev;
	int				id;
	t_philosopher	*philosopher;
	t_philosopher	*philosophers;

	id = 1;
	prev = NULL;
	while (id <= info->n_philosophers)
	{
		philosopher = new_philosopher(id, info);
		if (!philosopher)
			return (NULL);
		if (prev)
		{
			philosopher->left_person = prev;
			prev->right_person = philosopher;
		}
		prev = philosopher;
		id++;
	}
	get_philosopher(philosopher, 1)->left_person = philosopher;
	philosophers = get_philosopher(philosopher, 1);
	philosopher->right_person = philosophers;
	set_forks(philosophers);
	return (philosophers);
}

void	free_philosophers(t_philosopher *philosophers)
{
	int				i;
	int				n_philosophers;
	t_philosopher	*philosopher;
	t_philosopher	*right;

	i = 0;
	n_philosophers = philosophers->info->n_philosophers;
	philosopher = philosophers;
	while (i < n_philosophers)
	{
		right = philosopher->right_person;
		free_fork(philosopher->right_fork);
		pthread_mutex_destroy(&philosopher->n_meals_mutex);
		pthread_mutex_destroy(&philosopher->last_meal_time_mutex);
		pthread_mutex_destroy(&philosopher->exit_flg_mutex);
		free(philosopher);
		philosopher = right;
		i++;
	}
	return ;
}
