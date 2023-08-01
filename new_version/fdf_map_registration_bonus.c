/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_registration_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:59:31 by fporciel          #+#    #+#             */
/*   Updated: 2023/08/01 17:20:15 by atucci           ###   ########.fr       */
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
if ((map == NULL) && (param == 3))
	{
		if ((info->max_x < info->width) && (info->max_y < info->height))
			info->spacing = fmin((double)(info->width) / info->max_x,
					(double)(info->height) / info->max_y);
		else
			info->spacing = 50.0;
		return ;
	}
	(map[info->x_count]).x_orthogonal = (info->x_count * info->spacing);
	(map[info->x_count]).x_display = (info->x_count * info->spacing);
	(map[info->x_count]).y_orthogonal = (info->y_count * info->spacing);
	(map[info->x_count]).y_display = (info->y_count * info->spacing);
	(map[info->x_count]).z_orthogonal = info->z_count;
	(map[info->x_count]).z_display = info->z_count;
	(map[info->x_count]).right_point = NULL;
	(map[info->x_count]).down_point = NULL;
	if (param == 0)
		(map[info->x_count]).stop_param = 0;
	if (param == 1)
		(map[info->x_count]).stop_param = 1;
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
	
	map = (t_map **)malloc(sizeof(t_map *) * (info->max_y + 2));
	if (map == NULL)
		return (0);
	while (info->y_count <= info->max_y)
	{
		line = NULL;
		line = get_next_line(info->fd);
		ft_printf("\033[1;41mthis is the first check:MAP REGISTRATION\033[0m\n");
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
	info->map = &map; // I am a dumb fuck
	info->garbage = points_conjunction(info, &map);
	return (cleaner(&map, info, NULL));
}
