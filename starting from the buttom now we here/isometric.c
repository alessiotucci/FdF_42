/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:33:06 by atucci            #+#    #+#             */
/*   Updated: 2023/10/02 14:24:29 by atucci           ###   ########.fr       */
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

void int_to_isometric_pixel(t_date *info, t_point **head)
{
	t_point *current = *head;
	while (current != NULL)
				{
// Calculate the isometric X-coordinate
        current->x_pixel = (info->center_x) + ((current->x_map - current->y_map) * cos(PI / 6) * info->scaling);
// Calculate the isometric Y-coordinate
        current->y_pixel = (info->center_y) - (current->z_map * sin(PI / 6) * info->scaling) + ((current->x_map + current->y_map) * sin(PI / 6) * info->scaling);
        current = current->next;
    }
}



/* In this function we will loop throught the list 
	* of points and draw using the bresenham funciton*/
void	draw_lines(t_date *info, t_point **head)
{
	t_point	*current;

	// do delete 
	//find_min_max(info, head);
	current = *head;
	while (current != NULL)
	{
		if (current->go_right != NULL)
		{
			//ft_printf("%sbres:[%p]going right%s-->\n", BG_CYAN, current, RESET);
			old_bresenham(info, current, current->go_right);
			//if (current->go_right->go_down != NULL)
				//bresenham(info, current, current->go_right->go_down);
		}
		if (current->go_down != NULL)
		{
			//ft_printf("%sbres:[%p]going down%s--v\n", BG_CYAN, current, RESET);
			old_bresenham(info, current, current->go_down);
		}
		current = current->next;
	}
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
	step_x = (start->x_pixel < end->x_pixel) ? 1 : -1;
	step_y = (start->y_pixel < end->y_pixel) ? 1 : -1;
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


void	new_scaling_system(t_date *info, t_point **head)
{
	t_point *current = *head;
	ft_printf("NEW SCALING\n we apply the formulas\n");
	int	scaling = fmin((info->width / info->map_width), (info->height / info->map_height));
	int	center_x = (info->width - (info->scaling * info->map_width)) / 2;
	int	center_y = (info->height - (info->scaling * info->map_height)) / 2;

	ft_printf("new scaling[%d]\nnew center x [%d]\nnew center y[%d]\n", scaling, center_x, center_y);

while (current != NULL)
	{
// Calculate the isometric X-coordinate
        current->x_pixel = (center_x) + ((current->x_map - current->y_map) * cos(PI / 6) * scaling);
// Calculate the isometric Y-coordinate
        current->y_pixel = (center_y) - (current->z_map * sin(PI / 6) * scaling) + ((current->x_map + current->y_map) * sin(PI / 6) * scaling);
        current = current->next;
	}

}
void find_min_max(t_date *info, t_point **head)
{
    // Calculate map dimensions
    int min_x = INT_MAX;
    int max_x = INT_MIN;
    int min_y = INT_MAX;
    int max_y = INT_MIN;

    t_point *current = *head;
    while (current != NULL)
    {
        if (current->x_pixel < min_x)
									min_x = current->x_pixel;
        if (current->x_pixel > max_x)
									max_x = current->x_pixel;
        if (current->y_pixel < min_y)
									min_y = current->y_pixel;
        if (current->y_pixel > max_y)
									max_y = current->y_pixel;
        current = current->next;
    }
				info->max_x = max_x;
				info->max_y = max_y;
				info->min_x = min_x;
				info->min_y = min_y;
	printf("\n---Finding min pixel and Max pixel:::\n we will need to do more scaling---\n");
	printf("pixel max x: %lf\n", info->max_x);
	printf("pixle max y: %lf\n",info->max_y);
	printf("pixel min x: %lf\n", info->min_x);
	printf("pixel min y: %lf\n", info->min_y);

	// this function to split into more
	info->map_width = max_x - min_x + 1;
	info->map_height = max_y - min_y + 1;
	//new_scaling_system(info, head);
}

