/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:08:37 by fporciel          #+#    #+#             */
/*   Updated: 2023/07/19 17:58:55 by fporciel         ###   ########.fr       */
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

static int	check_projection(t_data *info, int argc, char **argv)
{
	size_t	len;

	len = ft_strlen(argv[2]);
	if (ft_strncmp(argv[2], "i", len) == 0)
		(*info).projection_type = 105;
	else if (ft_strncmp(argv[2], "e", len) == 0)
		(*info).projection_type = 101;
	else if (ft_strncmp(argv[2], "p", len) == 0)
		(*info).projection_type = 112;
	else
		return (0);
	if (argc == 5)
	{
		(*info).win_width = ft_atoi(argv[3]);
		(*info).win_height = ft_atoi(argv[4]);
	}
	return (1);
}

static int	store_map_data(char *name, t_data *info)
{
	char	buf;
	int		x;

	(*info).fd = open(name, O_RDONLY);
	if ((*info).fd < 0)
		return (0);
	(*info).count = -1;
	(*info).max_y = -1;
	x = 0;
	while ((*info).count != 0)
	{
		(*info).count = read((*info).fd, &buf, 1);
		if ((*info).count < 0)
			return (0);
		if (buf == 32)
			x++;
		if (buf == 10)
			x = 0;
		if ((buf == 10) && ((*info).count != 0))
			((*info).max_y)++;
		if (x > (*info).max_x)
			(*info).max_x = x;
	}
	close((*info).fd);
	return (1);
}

static int	check_map(char *name, t_data *info)
{
	(*info).fd = open(name, O_RDONLY);
	if ((*info).fd < 0)
		return (0);
	(*info).count = -1;
	while ((*info).count != 0)
	{
		(*info).count = read((*info).fd, &((*info).pre_buf), 1);
		if ((*info).count < 0)
			return (0);
		if ((*info).pre_buf != 32)
		{
			if ((ft_isdigit((*info).pre_buf) == 0) && ((*info).pre_buf != 10))
				return (0);
		}
		else
		{
			(*info).count = read((*info).fd, &((*info).nex_buf), 1);
			if (((*info).count < 0) || (ft_isdigit((*info).nex_buf) == 0))
				return (0);
		}
	}
	close((*info).fd);
	return (1);
}

static int	check_name_and_dimensions(int argc, char **argv)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(argv[1]);
	if ((argv[1][len - 1] != 102) || (argv[1][len - 2] != 100)
			|| (argv[1][len - 3] != 102) || (argv[1][len - 4] != 46))
		return (0);
	len = 0;
	i = 0;
	while ((argc == 4) && (argv[2][len] && argv[3][i]))
	{
		if ((ft_isdigit(argv[2][len]) == 0) || (ft_isdigit(argv[3][i]) == 0))
			return (0);
		len++;
		i++;
	}
	while ((argc == 5) && (argv[3][len] && argv[4][i]))
	{
		if ((ft_isdigit(argv[3][len]) == 0) || (ft_isdigit(argv[4][i]) == 0))
			return (0);
		len++;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	static t_data	info;

	info.win_width = DEFAULT_WIDTH;
	info.win_height = DEFAULT_HEIGHT;
	info.projection_type = 112;
	if ((argc != 2) && (argc != 3) && (argc != 4) && (argc != 5))
		return (0);
	if (check_name_and_dimensions(argc, argv) == 0)
		return (0);
	if (check_map(argv[1], &info) == 0)
		return (0);
	if (store_map_data(argv[1], &info) == 0)
		return (0);
	info.fd = open(argv[1], O_RDONLY);
	if (((argc == 3) || (argc == 5)) && (info.fd >= 0))
		info.garbage = check_projection(&info, argc, argv);
	if (argc == 4)
	{
		info.win_width = ft_atoi(argv[2]);
		info.win_height = ft_atoi(argv[3]);
	}
	if (info.fd >= 0)
		info.garbage = map_registration(&info);
	close(info.fd);
	return (0);
}
