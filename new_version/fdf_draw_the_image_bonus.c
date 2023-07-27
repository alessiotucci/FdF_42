/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_the_image_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:19:26 by atucci            #+#    #+#             */
/*   Updated: 2023/07/27 11:54:35 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
// for testing purpose
void printMap(t_map *map)
{
    ft_printf("\033[1;36mx_orthogonal: %d\033[0m\n",	map->x_orthogonal);
    ft_printf("\033[1;36my_orthogonal: %d\033[0m\n",	map->y_orthogonal);
    ft_printf("\033[1;36mz_orthogonal: %d\033[0m\n",	map->z_orthogonal);
    ft_printf("\033[1;32mx_display: %d\033[0m\n",	map->x_display);
    ft_printf("\033[1;32my_display: %d\033[0m\n",	map->y_display);
    ft_printf("\033[1;32mz_display: %d\033[0m\n",	map->z_display);
    ft_printf("\033[1;30mcolor: %d\033[0m\n",		map->color);
    ft_printf("\033[1;31mstop_param: %d\033[0m\n",	map->stop_param);
    // Print pointer members with a different background color
    ft_printf("\033[1;47mright_point: %p\033[0m\n",	(void*)map->right_point);
    ft_printf("\033[1;47mdown_point: %p\033[0m\n",	(void*)map->down_point);
}

void	bresenham_init(t_bres *params, t_map *start, t_map end)
{
	params->x0 = start->x_display;
	params->y0 = start->y_display;
	params->x1 = end->x_display;
	params->y1 = end->y_display;
	params->delta_x = abs(params->x1 - params->x0);
	params->delta_y = abs(params->y1 - params->y0);
	params->slope = params->delta_y -  params->delta_x;
	params->x = params->x0;
	params->y = params->y0;
}
int	bresenham_next(t_bres *params)
{
	if (params->x != params->x1)
	{
		if (params->slope > 0)
		{
			if (params->y1 > params->y0)
				params->y += 1;
			else
				params->y -= 1;
			params->slope -= params->delta_x;
		}
		else
			params->slope += params->delta_y;
		// other block of  statements
	if (params->x1 > params->x0)
		params->x += 1;
	else
		params->x -= 1;
	
	return (1);
	}
return (0);
}
// color the point of  the maps in the image
// maybe I should change the prototype to adapt it to bresenham algorithm.
static void draw_pixel(t_data *info, t_map *map)
{
	if (info == NULL || map == NULL)
		return (ft_printf("\teither one of the value is null\n"));
	int	pixel_x;
	int	pixel_y;
	int	index;
	
	pixel_x = map->x_display;
	pixel_y = map->y_display;
// general formula to light up a pixel	
	index = (size_t)info->lsize * pixel_y + pixel_x * ((size_t)info->bits / 8);
	info->img_data[index] = 255; // set the pixel red;
}
// bresenham algorithm function

int	draw_lines(t_data *info, t_map ***map)
{
	if (info == NULL || map == NULL)
		return (ft_printf("some paramater is null :(\n"));
	// I have to set up a while cycle to go throught all the point of the map!
	int	y;
	int	x;

	if (map == NULL)
		ft_printf("stronzo: map == NULL!\n");// delete later on	
	y = 0;
	while (y <= info->max_y)
	{
		x = 0;
		while (x <= info->max_x)
		{
		printf("x[%d] <= info->max_x[%d]\n", x, info->max_x);
		draw_pixel(info, &(*map)[y][x]);	
		//printMap(info->map[y][x]);
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
