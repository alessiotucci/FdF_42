/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:34:25 by atucci            #+#    #+#             */
/*   Updated: 2023/10/02 18:18:47 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	vertical_line(t_date *info, t_point *start, t_point *end)
{
	int	vertical_y;

	vertical_y = start->y_pixel;
	while (vertical_y <= end->y_pixel)
	{
		draw_point(info, start->x_pixel, vertical_y);
		vertical_y++;
	}
}

static void	horizontal_line(t_date *info, t_point *start, t_point *end)
{
	int	horizontal_x;

	horizontal_x = start->x_pixel;
	while (horizontal_x <= end->x_pixel)
	{
		draw_point(info, horizontal_x, start->y_pixel);
		horizontal_x++;
	}
}

static void	low_slop_line(t_date *info, t_point *start, t_point *end)
{
	int	delta_x;
	int	delta_y;
	int	p;
	int	x;
	int	y;

	delta_x = end->x_pixel - start->x_pixel;
	delta_y = end->y_pixel - start->y_pixel;
	x = start->x_pixel;
	y = start->y_pixel;
	p = 2 * delta_y - delta_x;
	while (x <= end->x_pixel)
	{
		draw_point(info, x, y);
		if (p >= 0)
		{
			y++;
			p = p - 2 * delta_x;
		}
		p = p + 2 * delta_y;
		x++;
	}
}

static void	high_slop_line(t_date *info, t_point *start, t_point *end)
{
	int	delta_x;
	int	delta_y;
	int	p;
	int	x;
	int	y;

	delta_x = end->x_pixel - start->x_pixel;
	delta_y = end->y_pixel - start->y_pixel;
	x = start->x_pixel;
	y = start->y_pixel;
	p = 2 * delta_x - delta_y;
	while (y <= end->y_pixel)
	{
		draw_point(info, x, y);
		if (p >= 0)
		{
			x++;
			p = p - 2 * delta_y;
		}
		p = p + 2 * delta_x;
		y++;
	}
}

void	bresenham(t_date *info, t_point *start, t_point *end)
{
	int	delta_x;
	int	delta_y;

	delta_x = end->x_pixel - start->x_pixel;
	delta_y = end->y_pixel - start->y_pixel;
	if (delta_x == 0)
		vertical_line(info, start, end);
	else if (delta_y == 0)
		horizontal_line(info, start, end);
	else if (abs(delta_y) < abs(delta_x))
		low_slop_line(info, start, end);
	else
		high_slop_line(info, start, end);
}
