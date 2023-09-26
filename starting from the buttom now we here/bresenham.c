/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:34:25 by atucci            #+#    #+#             */
/*   Updated: 2023/09/26 11:05:21 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_date *info, t_point *start, t_point *end)
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
		// do some drawing
		draw_point(&info->graphics, x, y);
		if (p >= 0)
		{
			y = y + 1;
			p = p + 2 * delta_y - 2 * delta_x;
		}
		else
			p = p + 2 * delta_y;
		x = x + 1;
	}
}

/* In this function we will try to set pixel in the img of mlx*/
void draw_point(t_graphics *info, int x, int y)
{
	ft_printf("\t[%d][%d]\t", x, y);
	int	index;
// bits and lsize are inside graphics...
	if (info == NULL)
		return; // Do nothing if the parameters are NULL
	index = (info->lsize * y) + (x * (info->bits / 8));
	info->img_data[index] = (unsigned char)255; // Set the pixel to red
	return ;
}

/* In this function we will loop throught the list of points and draw using the bresenham funciton*/
void	draw_lines(t_date *info, t_point **head)
{
	ft_printf("[H]: check draw lines\n");
	t_point	*current;

	current = *head;
	while (current != NULL)
	{
		if (current->go_right != NULL)
			bresenham(info, current, current->go_right);
		if (current->go_down != NULL)
			bresenham(info, current, current->go_down);
		current = current->next;
	}
}