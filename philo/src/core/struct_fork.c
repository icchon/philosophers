/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:57:46 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/17 22:31:36 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_fork	*new_fork(int id)
{
	t_fork	*fork;

	fork = (t_fork *)malloc(sizeof(t_fork));
	if (!fork)
		return (NULL);
	fork->id = id;
	pthread_mutex_init(&fork->mutex, NULL);
	return (fork);
}

void	free_fork(t_fork *fork)
{
	pthread_mutex_destroy(&fork->mutex);
	free(fork);
	return ;
}
