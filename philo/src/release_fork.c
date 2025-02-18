/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:08:38 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/17 22:38:14 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:04:35 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/17 21:08:13 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	release_left_fork(t_philosopher *philosopher)
{
	philosopher->status = WAITING;
	pthread_mutex_unlock(&philosopher->left_fork->mutex);
	return ;
}
// print_log(philosopher, "release a left fork\n");

static void	release_right_fork(t_philosopher *philosopher)
{
	philosopher->status = WAITING;
	pthread_mutex_unlock(&philosopher->right_fork->mutex);
	return ;
}
// print_log(philosopher, "release a right fork\n");

void	release_forks(t_philosopher *philosopher)
{
	if (philosopher->id % 2 == 1)
	{
		release_right_fork(philosopher);
		release_left_fork(philosopher);
	}
	else
	{
		release_left_fork(philosopher);
		release_right_fork(philosopher);
	}
	return ;
}
