/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_isometric_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:15:28 by atucci            #+#    #+#             */
/*   Updated: 2023/07/26 12:53:40 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* 
* This software is made available to anyone who wants to retrace the 
* author's learning path through the projects of school 42.
* Copyright (C) 2023  fporciel
* 
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
*
* You can contact the author at: 
*- fporciel@student.42roma.it
*/

#include "fdf_bonus.h"
/* build a macro to work  with radiants */

// this is just for testing
static void	printMap( t_map *map)
{	
	
	ft_printf("|----SINGLE POINT DATA:------|\n");
	ft_printf("\033[1;36mx_orthogonal: %d\033[0m\n",	map->x_orthogonal);
	ft_printf("\033[1;36my_orthogonal: %d\033[0m\n",	map->y_orthogonal);
	ft_printf("\033[1;36mz_orthogonal: %d\033[0m\n",	map->z_orthogonal);
	ft_printf("\033[1;32mx_display: %d\033[0m\n",		map->x_display);
	ft_printf("\033[1;32my_display: %d\033[0m\n",		map->y_display);
	ft_printf("\033[1;32mz_display: %d\033[0m\n",		map->z_display);
	ft_printf("\033[1;30mcolor: %d\033[0m\n",		map->color);
	ft_printf("\033[1;36mprecision x: %d\033[0m\n",		map->x_precision);
	ft_printf("\033[1;36mprecision y: %d\033[0m\n",		map->y_precision);
	ft_printf("\033[1;31mstop_param: %d\033[0m\n", map->stop_param);
	ft_printf("\033[1;47mright_point: %p\033[0m\n", (void*)map->right_point);
	ft_printf("\033[1;47mdown__point: %p\033[0m\n", (void*)map->down_point);
	ft_printf("---------------------------\n\n");
}
static	void	apply_iso_projection(t_map *pnt)
{
	double	x_d;
	double	y_d;
	
	x_d = (pnt->x_orthogonal - pnt->y_orthogonal) * cos(0.523599);
	y_d = -pnt->z_orthogonal + (pnt->x_orthogonal + pnt->y_orthogonal) * sin(0.523599);
	pnt->x_display = floor(x_d);
	pnt->y_display = floor(y_d);
	pnt->x_precision = (x_d - floor(x_d)) * 10000;
	pnt->y_precision = (y_d - floor(y_d)) * 10000;
	printMap(pnt);
}

int	isometric(t_data *info, t_map ***map)
{
	int	y;
	int	x;

	y = 0;
	while (y <= info->max_y)
	{
		x = 0;
		while (x <= info->max_x)
		{
			apply_iso_projection(&((*map)[y][x]));
			x++;
		}
		y++;
	}
	return (0);
}