/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:34:25 by atucci            #+#    #+#             */
/*   Updated: 2023/09/25 18:47:57 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	bresenham(t_date *info, t_point start, t_point end)
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
void draw_point(t_date *info, int x, int y)
{
	int	index;

	if (info == NULL)
		return; // Do nothing if the parameters are NULL
	index = (info->lsize * y) + (x * (info->bits / 8));
	info->img_data[index] = 255; // Set the pixel to red
	return ;
}
