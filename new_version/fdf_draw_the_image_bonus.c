/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_the_image_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:19:26 by atucci            #+#    #+#             */
/*   Updated: 2023/07/26 18:16:19 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

// color the point of  the maps in the image

// bresenham algorithm function
static  void light_a_pixel(t_map *point)
{
	int	i;

	// i is gonna be the INDEX;
}


int	draw_lines(t_data *info, t_map ***map)
{
// I have to set up a while cycle to go throught all the point of the map!
	int	y;
	int	x;
	
	y = 0;
	while (y <= info->max_y)
	{
		x = 0;
		while (x <= info->max_x)
		{
		light_a_pixel(&(*map)[y][x]);
		x++;
		}
	y++;
	}
	return (0);
}
/* general formula to find the index in the char * (a string)
 index = lsize * y + x * (bits / 8)
	int	i;
	i = info->lsize * y + x * (info->bits / 8);*/ 
