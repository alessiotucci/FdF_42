/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_points_conjunction_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:20:07 by fporciel          #+#    #+#             */
/*   Updated: 2023/07/24 12:43:17 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	update_point_connect(t_map *curr, t_map *rig, t_map *dwn)
{
	if (rig != NULL)
		curr->right_point = rig;
	if (dwn != NULL)
		curr->down_point = dwn;
	return (0);
}

static int	connect_points_in_map(t_data *info, t_map ***map)
{
	int	x;
	int	y;

	y = 0;
	while (y <= (*info).max_y)
	{
		x = 0;
		while (x <= (*info).max_x)
		{
			if (x + 1 <= info->max_x)
				update_point_connect(&(*map)[y][x], &(*map)[y][x + 1], NULL);
			if (y + 1 <= info->max_y)
				update_point_connect(&(*map)[y][x], NULL, &(*map)[y + 1][x]);
			ft_printf("map values[%d,%d]\n", y, x);
			printMap(&(*map)[y][x]);
			x++;
		}
		y++;
	}
	return (0);
}

int	points_conjunction(t_data *info, t_map ***map)
{
	if (!info || !map || !*map)
		return (-1);
	connect_points_in_map(info, map);
	return (0);
}
