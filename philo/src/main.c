/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 06:29:40 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/19 06:44:51 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_info			*info;
	t_philosopher	*philosophers;

	if (!is_valid_arg(argc, argv))
	{
		write(STDERR_FILENO, "invalid arg\n", ft_strlen("invalid arg\n"));
		return (EXIT_FAILURE);
	}
	info = new_info(argc, argv);
	if (!info)
		return (EXIT_FAILURE);
	philosophers = new_philosophers(*info);
	simulate(philosophers);
	free_philosophers(philosophers);
	free_info(info);
	return (0);
}
