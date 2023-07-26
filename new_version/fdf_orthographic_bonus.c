/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_orthographic_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:56:36 by atucci            #+#    #+#             */
/*   Updated: 2023/07/26 13:56:49 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	orthographic(t_data *info, t_map ***map)
{
	size_t	x;
	size_t	y;

	(void)info;
	y = 0;
	while (((*map)[y]) != NULL)
	{
		x = 0;
		while ((((*map)[y][x]).stop_param) != 1)
		{
			(((*map)[y][x]).x_display) = (((*map)[y][x]).x_orthogonal);
			(((*map)[y][x]).y_display) = (((*map)[y][x]).y_orthogonal);
			(((*map)[y][x]).z_display) = (((*map)[y][x]).z_orthogonal);
			x++;
		}
		y++;
	}
	return (0);
}
