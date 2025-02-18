/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:58:55 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/17 21:19:33 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_info(t_info *info, int argc, char *argv[])
{
	info->n_philosophers = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->n_must_eat = INT_MAX;
	if (argc == 6)
	{
		info->must_eat_flg = 1;
		info->n_must_eat = ft_atoi(argv[5]);
	}
	return ;
}

t_info	*new_info(int argc, char *argv[])
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
	{
		return (NULL);
	}
	info->must_eat_flg = 0;
	set_info(info, argc, argv);
	return (info);
}

void	free_info(t_info *info)
{
	free(info);
}
