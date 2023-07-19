/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_registration_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:59:31 by fporciel          #+#    #+#             */
/*   Updated: 2023/07/19 13:02:13 by atucci           ###   ########.fr       */
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

static int	cleaner(t_map ***map, ssize_t count, char **line, char ***split)
{
	int	i;

	i = 0;
	if (split && (*split))
	{
		while ((*split)[i] != NULL)
			free((*split)[i++]);
		free(*split);
	}
	if (line && (*line))
		free(*line);
	if (map && (*map))
	{
		i = 0;
		map -= count;
		while ((*map)[i] != NULL)
			free((*map)[i++]);
		free(*map);
	}
	(*split) = NULL;
	(*map) = NULL;
	(*line) = NULL;
	return (0);
}

static t_map	**memory_management(t_map ***map, char *line)
{
	int	count;
	int	num;

	count = 0;
	while (line[count] != 0)
	{
		if (line[count] == 32)
			num++;
		count++;
	}
	(*map) = (t_map **)malloc((num + 2) * sizeof(t_map *));
	if ((*map) == NULL)
		return (NULL);
	return (*map);
}

static t_map	***point_generation(t_map ***map, t_data *info, int x, int z)
{
	int	y;
	(**map) = (t_map *)malloc(sizeof(t_map));
	if ((**map) == NULL)
		return (NULL);
	(**map)->y_orthogonal = (*info).count;
	(**map)->x_orthogonal = x;
	(**map)->z_orthogonal = y;
	(**map)++;
	return (map);
}

static int	map_division(t_data *info, t_map ***map, char *line)
{
	char	**splitted_line;
	int		count;
	int		z_value;

	count = 0;
	splitted_line = ft_split(line, 32);
	if (splitted_line == NULL)
		return (cleaner(NULL, 0, &line, NULL));
	while (splitted_line[count] != NULL)
	{
		z_value = ft_atoi(splitted_line[count]);
		map = point_generation(map, info, count, z_value);
		if (map == NULL)
			return (cleaner(NULL, 0, &line, NULL));
		count++;
	}
	(**map) = NULL;
	return (cleaner(NULL, 0, &line, &splitted_line));
}

int	map_registration(t_data *info)
{
	static t_map	**map;
	char			*line;

	(*info).count = -1;
	while ((*info).count <= (*info).max_y)
	{
		line = get_next_line((*info).fd);
		if ((line == NULL) && ((*info).count <= (*info).max_y))
			return (cleaner(&map, (*info).count, NULL, NULL));
		((*info).count)++;
		map = memory_management(&map, line);
		if (map == NULL)
			return (cleaner(&map, (*info).count, NULL, NULL));
		if (((*info).count <= (*info).max_y))
		{
			(*info).garbage = map_division(info, &map, line);
			if (map == NULL)
				return (cleaner(&map, (*info).count, NULL, NULL));
			map++;
		}
		else
			map = NULL;
	}
	map -= (*info).count;
	return (points_conjunction(info, &map));
}
