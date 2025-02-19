/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:54:47 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/17 20:55:08 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

double	get_passed_time(t_timeval start)
{
	t_timeval	now;
	double		sec;
	double		micro;
	double		passed;

	gettimeofday(&now, NULL);
	sec = (double)(now.tv_sec - start.tv_sec);
	micro = (double)(now.tv_usec - start.tv_usec);
	passed = (sec * 1000) + (micro / 1000);
	return (passed);
}
