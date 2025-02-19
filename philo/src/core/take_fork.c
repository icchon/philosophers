/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:07:46 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/19 16:39:22 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	take_left_fork(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->left_fork->mutex);
	if (is_exit_flg(philosopher) || is_dead(philosopher))
		return (0);
	print_log(philosopher, "has taken a fork\n");
	return (1);
}

static int	take_right_fork(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->right_fork->mutex);
	if (is_exit_flg(philosopher) || is_dead(philosopher))
		return (0);
	print_log(philosopher, "has taken a fork\n");
	return (1);
}

int	take_forks(t_philosopher *philosopher)
{
	int	res;

	res = 0;
	if (philosopher->id % 2 == 1)
	{
		res = take_right_fork(philosopher);
		res &= take_left_fork(philosopher);
	}
	else
	{
		res = take_left_fork(philosopher);
		res &= take_right_fork(philosopher);
	}
	return (res);
}
