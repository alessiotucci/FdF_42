/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:33:06 by atucci            #+#    #+#             */
/*   Updated: 2023/10/03 12:45:05 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <math.h>

/*this function is taken from the 42 docs*/
void	my_mlx_pixel_put(t_date *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img_string + (y * data->lsize + x * (data->bits / 8));
	*(unsigned int*)dst = color;
}

void	int_to_isometric_pixel(t_date *info, t_point **head)
{
	t_point	*current;

	current = *head;
	while (current != NULL)
	{
		current->x_pixel = (info->center_x) + ((current->x_map - current->y_map)
				* cos(PI / 6) * info->scaling);
		current->y_pixel = (info->center_y) - (current->z_map * sin(PI / 6)
				* info->scaling) + ((current->x_map + current->y_map)
				* sin(PI / 6) * info->scaling);
		current = current->next;
	}
}

/* In this function we will loop throught the list 
	* of points and draw using the bresenham funciton*/
void	draw_lines(t_date *info, t_point **head)
{
	t_point	*current;

	current = *head;
	while (current != NULL)
	{
		if (current->go_right != NULL)
		{
			bresenham(info, current, current->go_right);
		}
		if (current->go_down != NULL)
		{
			bresenham(info, current, current->go_down);
		}
		current = current->next;
	}
}
/*
static int calculate_step(int start, int end)
{
  if (start < end)
    return 1;
  else
    return -1;
  
}

void	old_bresenham(t_date *info, t_point *start, t_point *end)
{
	int	delta_x;
	int	delta_y;
	int	step_x;
	int	step_y;
	int	p;
	int	x;
	int	y;

	delta_x = abs(end->x_pixel - start->x_pixel);
	delta_y = abs(end->y_pixel - start->y_pixel);
	step_x = calculate_step(start->x_pixel, end->x_pixel);
	step_y = calculate_step(start->y_pixel, end->y_pixel);
	x = start->x_pixel;
	y = start->y_pixel;
	if (delta_x >= delta_y)
	{
		p = 2 * delta_y - delta_x;
		while (x != end->x_pixel)
		{
			draw_point(info, x, y);
			x += step_x;
			if (p >= 0)
			{
				y += step_y;
				p -= 2 * delta_x;
			}
			p += 2 * delta_y;
		}
	}
	else
	{
		p = 2 * delta_x - delta_y;
		while (y != end->y_pixel)
		{
			draw_point(info, x, y);
			y += step_y;
			if (p >= 0)
			{
				x += step_x;
				p -= 2 * delta_y;
			}
			p += 2 * delta_x;
		}
	}
	draw_point(info, end->x_pixel, end->y_pixel);
}
*/
