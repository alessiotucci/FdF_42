/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection_function_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:31:27 by atucci            #+#    #+#             */
/*   Updated: 2023/07/26 16:32:06 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	orthographic(t_map point)
{
	point.x_display = point.x_orthogonal;
	point.y_display = point.y_orthogonal;
	point.z_display = point.z_orthogonal;
	return (0);
}

static int	isometric(t_map point)
{
	double	x_disp;
	double	y_disp;
	int		x_orth;
	int		y_orth;
	int		z_orth;

	x_orth = point.x_orthogonal;
	y_orth = point.y_orthogonal;
	z_orth = point.z_orthogonal;
	x_disp = (x_orth - y_orth) * cos(0.523599);
	y_disp = -(z_orth) + (x_orth + y_orth) * sin(0.523599);
	point.x_display = floor(x_disp);
	point.y_display = floor(y_disp);
	point.x_precision = (x_disp - floor(x_disp)) * 1000;
	point.y_precision = (y_disp - floor(y_disp)) * 1000;
	return (0);
}

static int	equirectangular(t_map point)
{
	double	latitude;
	double	longitude;
	double	radius;
	double	temp;

	radius = 100.0;
	latitude = (point.y_orthogonal * (PI / 180.0));
	longitude = (point.x_orthogonal * (PI / 180.0));
	temp = (radius * cos(latitude) * cos(longitude));
	point.x_display = (int)temp;
	point.x_precision = (int)((temp - point.x_display) * 1000);
	temp = (radius * cos(latitude) * sin(longitude));
	point.y_display = (int)temp;
	point.y_precision = (int)((temp - point.y_display) * 1000);
	temp = (radius * sin(latitude));
	point.z_display = (int)temp;
	point.z_precision = (int)((temp - point.z_display) * 1000);
	return (0);
}

int	projection_function(t_data *info, t_map ***map)
{
	int	x;
	int	y;

	y = 0;
	while ((*map)[y] != NULL)
	{
		x = 0;
		while (((*map)[y][x]).stop_param != 1)
		{
			if (info->projection_type == 105)
				isometric((*map)[y][x]);
			if (info->projection_type == 112)
				orthographic((*map)[y][x]);
			else if (info->projection_type == 101)
				equirectangular((*map)[y][x]);
			else
				isometric((*map)[y][x]);
			x++;
		}
		y++;
	}
	return (0);
}
