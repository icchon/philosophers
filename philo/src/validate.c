/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:39:14 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/17 22:39:22 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	is_positive(char *s)
{
	int	n;

	if (!ft_isint(s))
	{
		return (0);
	}
	n = ft_atoi(s);
	if (n <= 0)
	{
		return (0);
	}
	return (1);
}

int	is_valid_arg(int argc, char *argv[])
{
	int	i;

	if (!(argc == 5 || argc == 6))
	{
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (!is_positive(argv[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
