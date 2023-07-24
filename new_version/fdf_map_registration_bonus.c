/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_registration_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:59:31 by fporciel          #+#    #+#             */
/*   Updated: 2023/07/24 11:48:31 by atucci           ###   ########.fr       */
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

// this is just for testing
void	printMap( t_map *map)
{	
	
	ft_printf("|----SINGLE POINT DATA:------|\n", map->stop_param);
	ft_printf("\033[1;36mx_orthogonal: %d\033[0m\n", map->x_orthogonal);
	ft_printf("\033[1;36my_orthogonal: %d\033[0m\n", map->y_orthogonal);
	ft_printf("\033[1;36mz_orthogonal: %d\033[0m\n", map->z_orthogonal);
	ft_printf("\033[1;32mx_display: %d\033[0m\n", map->x_display);
	ft_printf("\033[1;32my_display: %d\033[0m\n", map->y_display);
	ft_printf("\033[1;32mz_display: %d\033[0m\n", map->z_display);
	ft_printf("\033[1;30mcolor: %d\033[0m\n", map->color);
	ft_printf("\033[1;31mstop_param: %d\033[0m\n", map->stop_param);
	ft_printf("\033[1;47mright_point: %p\033[0m\n", (void*)map->right_point);
	ft_printf("\033[1;47mdown__point: %p\033[0m\n", (void*)map->down_point);
	ft_printf("---------------------------\n\n", map->stop_param);
}


static int	clean_split(t_data *info, char ***split)
{
	info->garbage = 0;
	if (split && (*split))
	{
		while ((*split)[info->garbage] != NULL)
			free((*split)[info->garbage++]);
		free(*split);
		(*split) = NULL;
	}
	return (0);
}

static int	cleaner(t_map ***map, t_data *info, char **line)
{
	if (line && (*line))
	{
		free(*line);
		(*line) = NULL;
	}
	if (map && (*map) && (info->y_count > 0))
	{
		while (info->y_count >= 0)
		{
			free((*map)[info->y_count]);
			((*map)[info->y_count--]) = NULL;
		}
	}
	if (map && (*map))
	{
		free(*map);
		(*map) = NULL;
	}
	return (0);
}

static void	point_generator(t_map *map, t_data *info, int param)
{
	(map[info->x_count]).x_orthogonal = info->x_count;
	(map[info->x_count]).x_display = info->x_count;
	(map[info->x_count]).y_orthogonal = info->y_count;
	(map[info->x_count]).y_display = info->y_count;
	(map[info->x_count]).z_orthogonal = info->z_count;
	(map[info->x_count]).z_display = info->z_count;
	(map[info->x_count]).right_point = NULL;
	(map[info->x_count]).down_point = NULL;
	if (param == 0)
		(map[info->x_count]).stop_param = 0;
	if (param == 1)
		(map[info->x_count]).stop_param = 1;
//	ft_printf("pointers should be null\n");
//	printMap(&map[info->x_count]);
}

static int	map_division(t_data *info, t_map **map, char *line)
{
	char	**splitted_line;

	splitted_line = ft_split(line, 32);
	if (splitted_line == NULL)
		return (0);
	info->count = 0;
	while (splitted_line[info->count] != NULL)
		info->count++;
	map[info->y_count] = (t_map *)malloc(sizeof(t_map) * (info->count + 1));
	if (map == NULL)
		return (clean_split(info, &splitted_line));
	info->x_count = 0;

	ft_printf("\033[1;34m splitted line: %s\033[0m\n", splitted_line[info->x_count]);
	while (splitted_line[info->x_count] != NULL)
	{
		info->z_count = ft_atoi(splitted_line[info->x_count]);
		point_generator(map[info->y_count], info, 0);
		(info->x_count)++;
	}
	point_generator(map[info->y_count], info, 1);
	info->garbage = clean_split(info, &splitted_line);
	return (1);
}

int	map_registration(t_data *info)
{
	static t_map	**map;
	char			*line;
	
	ft_printf("\033[1;31mTroubles with the registration of the map!\033[0m\n");
	map = (t_map **)malloc(sizeof(t_map *) * (info->max_y + 2));
	if (map == NULL)
		return (0);
	while (info->y_count <= info->max_y)
	{
		line = NULL;
		line = get_next_line(info->fd);
		ft_printf("\033[1;41mthis is the line from gnl: -->\t %s\033[0m\n", line);
		if ((line == NULL) && (info->y_count <= info->max_y))
			return (cleaner(&map, info, NULL));
		if (line != NULL)
			info->garbage = map_division(info, map, line);
		if ((line != NULL) && (info->garbage == 0))
			return (cleaner(&map, info, &line));
		(info->y_count)++;
		if (line != NULL)
			free(line);
	}
	map[info->y_count] = NULL;
	info->garbage = points_conjunction(info, &map);
	return (cleaner(&map, info, NULL));
}
