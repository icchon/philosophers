/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 06:51:56 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/19 07:06:33 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <limits.h>
# include <stdlib.h>

int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
int		ft_isint(const char *nptr);
int		ft_issign(int c);
int		ft_isspace(int c);
size_t	ft_strlen(const char *s);

#endif