/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_the_image_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:19:26 by atucci            #+#    #+#             */
/*   Updated: 2023/07/27 18:05:57 by atucci           ###   ########.fr       */
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

// Initialize the Bresenham parameters for the current line
void bresenham_init(t_bres *params, t_map *start, t_map *end)
{
	params->x0 = start->x_display;
	params->y0 = start->y_display;
	params->delta_x = abs(end->x_display - params->x0);
	params->delta_y = abs(end->y_display - params->y0);
	params->slope = params->delta_y - params->delta_x;
	params->x = params->x0;
	params->y = params->y0;
}

// Calculate the next point on the line using the Bresenham algorithm
// Return 1 if there are more points to draw, 0 if we reached the end point
int bresenham_next(t_bres *params)
{
	// Check if we reached the end point
	if (params->x != params->x0)
	{
		if (params->slope > 0)
		{
			// Slope is greater than 1
			if (params->y > params->y0)
				params->y += 1;
			else
				params->y -= 1;
			params->slope -= params->delta_x;
		}
		else
		{
			// Slope is less than or equal to 1
			params->slope += params->delta_y;
		}

		// Move to the next pixel
		if (params->x > params->x0)
			params->x += 1;
		else
			params->x -= 1;

		// Return 1 to indicate there are more points to draw
		return (1);
	}

	// Return 0 to indicate we reached the end point
	return (0);
}

// Color the point of the maps in the image
static void draw_pixel(t_data *info, t_bres *param)
{
	if (info == NULL || param == NULL)
	{
		return; // Do nothing if the parameters are NULL
	}

	int pixel_x = param->x;
	int pixel_y = param->y;
	int index = (size_t)info->lsize * pixel_y + pixel_x * ((size_t)info->bits / 8);
	info->img_data[index] = 255; // Set the pixel to red
}


// Draw a line between two points on the map using the Bresenham algorithm
void draw_line(t_data *info, t_map *start, t_map *end)
{
	t_bres param;
	bresenham_init(&param, start, end);
	while (bresenham_next(&param))
	{
		// Draw the current point on the line
		draw_pixel(info, &param);
	}
}


// Function to draw lines between all points on the map
int draw_lines(t_data *info, t_map ***map)
{
	if (info == NULL || map == NULL)
	{
		return (ft_printf("Some parameter is NULL.\n"));
	}

	// Loop through all the points in the map and draw lines
	int y = 0;
	while (y <= info->max_y)
	{
		int x = 0;
		while (x <= info->max_x)
		{
			// Draw a line from the current point to the next point
			if (x < info->max_x)
			{
				draw_line(info, &(*map)[y][x], &(*map)[y][x + 1]);
			}
			if (y < info->max_y)
			{
				draw_line(info, &(*map)[y][x], &(*map)[y + 1][x]);
			}

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
