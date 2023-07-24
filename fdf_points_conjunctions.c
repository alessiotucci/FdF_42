/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_points_conjuctions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:03:26 by atucci            #+#    #+#             */
/*   Updated: 2023/07/24 09:44:27 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


 void printMap( t_map *map)

{
    ft_printf("\033[1;36mx_orthogonal: %d\033[0m\n", map->x_orthogonal);
    ft_printf("\033[1;36my_orthogonal: %d\033[0m\n", map->y_orthogonal);
    ft_printf("\033[1;36mz_orthogonal: %d\033[0m\n", map->z_orthogonal);
    ft_printf("\033[1;32mx_display: %d\033[0m\n", map->x_display);
   // ft_printf("\033[1;32my_display: %d\033[0m\n", map->y_display);
   // ft_printf("\033[1;32mz_display: %d\033[0m\n", map->z_display);
    ft_printf("\033[1;30mcolor: %d\033[0m\n", map->color);
   // ft_printf("\033[1;31mstop_param: %d\033[0m\n", map->stop_param);
    
    // Print pointer members with a different background color
    ft_printf("\033[1;47mright_point: %p\033[0m\n", (void*)map->right_point);
    ft_printf("\033[1;47mdown_point: %p\033[0m\n", (void*)map->down_point);
}

static int	update_point_connect(t_map *curr, t_map *rig, t_map *dwn)
{
	if (rig)
		curr->right_point = rig;
	if (dwn)
		curr->down_point = dwn;
	return (0);
}

static int	connect_points_in_map(t_data *info, t_map ***map)
{
	int	x;
	int	y;

	y = 0;
	while (y < (*info).max_y)
	{
		x = 0;
		while (x < (*info).max_x)
		{
			if (x + 1 < (*info).max_x)
				update_point_connect(&(*map)[y][x], &(*map)[y][x + 1], NULL);
			if (y + 1 < (*info).max_y)
				update_point_connect(&(*map)[y][x], NULL, &(*map)[y + 1][x]);
			x++;
		}
		y++;
	}
	return (0);
}

int	points_conjuctions(t_data *info, t_map ***map)
{
	if (!info || !map || !*map)
		return (-1);
	connect_points_in_map(info, map);
	if ((*info).projection_type == 'i')
		ft_printf("i\n");
	if ((*info).projection_type == 'p')
		ft_printf("p\n");
	if ((*info).projection_type == 'e')
		ft_printf("e\n");
	return (0);
}
