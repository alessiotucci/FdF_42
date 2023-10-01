/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:34:25 by atucci            #+#    #+#             */
/*   Updated: 2023/10/01 13:59:34 by atucci           ###   ########.fr       */
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
	if (delta_x == 0)
		while (y <= end->y_pixel)
			draw_point(info, x, y++);
	while (x <= end->x_pixel)
	{
		draw_point(info, x, y);
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
void	draw_point(t_date *info, int x, int y)
{
	ft_printf("\t[%d][%d]\t\n", x, y);
	if (x >= 0 && x < DEFAULT_WIDTH && y >= 0 && y < DEFAULT_HEIGHT)
		my_mlx_pixel_put(info, x, y, COLOR_WHITE);
	return ;
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
			ft_printf("%sbres:[%p]going right%s-->\n", BG_CYAN, current, RESET);
			bresenham(info, current, current->go_right);
		}
		if (current->go_down != NULL)
		{
			ft_printf("%sbres:[%p]going down%s--v\n", BG_CYAN, current, RESET);
			bresenham(info, current, current->go_down);
		}
		current = current->next;
	}
}
