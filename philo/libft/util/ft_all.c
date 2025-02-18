/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:30:44 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/22 14:28:12 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_util.h"

int	ft_all(char *src, int (*f)(int))
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (!(*f)(src[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
