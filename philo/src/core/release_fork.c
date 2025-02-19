/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:08:38 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/19 18:50:18 by kaisobe          ###   ########.fr       */
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

static int	release_left_fork(t_philosopher *philosopher)
{
	pthread_mutex_unlock(&philosopher->left_fork->mutex);
	return (1);
}

static int	release_right_fork(t_philosopher *philosopher)
{
	pthread_mutex_unlock(&philosopher->right_fork->mutex);
	return (1);
}

int	release_forks(t_philosopher *philosopher)
{
	int	res;

	res = 0;
	if (philosopher->id % 2 == 1)
	{
		res = release_right_fork(philosopher);
		res &= release_left_fork(philosopher);
	}
	else
	{
		res = release_left_fork(philosopher);
		res &= release_right_fork(philosopher);
	}
	return (res);
}
