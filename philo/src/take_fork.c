/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:07:46 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/17 21:35:26 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	take_left_fork(t_philosopher *philosopher)
{
	philosopher->status = WAITING;
	pthread_mutex_lock(&philosopher->left_fork->mutex);
	print_log(philosopher, "has taken a fork\n");
	return ;
}

static void	take_right_fork(t_philosopher *philosopher)
{
	philosopher->status = WAITING;
	pthread_mutex_lock(&philosopher->right_fork->mutex);
	print_log(philosopher, "has taken a fork\n");
	return ;
}

void	take_forks(t_philosopher *philosopher)
{
	if (philosopher->id % 2 == 1)
	{
		take_right_fork(philosopher);
		take_left_fork(philosopher);
	}
	else
	{
		take_left_fork(philosopher);
		take_right_fork(philosopher);
	}
	return ;
}
