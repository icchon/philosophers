/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addvec3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 09:45:09 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/31 11:11:37 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vec.h"

t_vector3	ft_add_vec3(t_vector3 v1, t_vector3 v2)
{
	return (ft_new_vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}
