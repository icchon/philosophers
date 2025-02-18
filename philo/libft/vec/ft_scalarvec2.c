/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scalarvec2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 09:47:25 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/31 18:53:54 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vec.h"

t_vector2	ft_scalar_vec2(t_vector2 v, double a)
{
	return (ft_new_vec2(v.x * a, v.y * a));
}
