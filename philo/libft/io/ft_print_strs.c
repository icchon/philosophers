/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:54:16 by kaisobe           #+#    #+#             */
/*   Updated: 2025/01/03 13:54:24 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

void	ft_print_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		ft_printf("%s\n", strs[i]);
		i++;
	}
	return ;
}
