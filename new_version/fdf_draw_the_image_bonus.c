/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_the_image_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:19:26 by atucci            #+#    #+#             */
/*   Updated: 2023/08/02 13:50:31 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
//* for testing purpose
void	printMap(t_map *map)
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
/* Color the point of the maps in the image*/
static void draw_point(t_data *info, int x, int y)
{
	int	index;

	ft_printf("\033[1;45mbits lsize are wrong\033[0m\n");
	if (info == NULL)
		return; // Do nothing if the parameters are NULL
//PRINT STATEMENT  TO DEBUG
	ft_printf("\033[1;36minfo->lsize[%d]\033[0m\n", info->lsize);
	ft_printf("\033[1;36minfo->bits[%d]\033[0m\n", (info->bits));
	ft_printf("\033[1;36mpixel_y: %d, pixel_x: %d\033[0m\n", x, y);
	index = (info->lsize * y) + (x * (info->bits / 8));
	ft_printf("\033[1;46mthe value of index [%d]\033[0m\n", index);
	ft_printf("this is the len of img_data: %d\n", ft_strlen(info->img_data));
	ft_printf("\033[1;45mThe img_data pointer is %s \033[0m\n", info->img_data);
	info->img_data[index] = 255; // Set the pixel to red
		//this is for testing 
	return ;
}

static void	bresenham(t_data *info, t_map *s, t_map *e)
{
	ft_printf("Inside the bresenham function :)\n");
	int	delta_x;
	int	delta_y;
	int	p;
	int	x;
	int	y;

	delta_x = e->x_display - s->x_display;
	delta_y = e->y_display - s->y_display;
	x = s->x_display;
	y = s->y_display;
	p = 2 * delta_y - delta_x;
	ft_printf("line 64) while x:[%d] < e->x_display[%d]\n", x , e->x_display);
	while (x < e->x_display)
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


/* Draw a line between two points on the map using the Bresenham algorithm*/
static void drawing(t_data *info, t_map *str, t_map *end)
{
//	int count = 0;
	ft_printf("inside the drawing\tfunction\n");
	printMap(str);
// let rewrite the bresenham algorithm;
	bresenham(info, str, end);
}

/*Function to draw lines between all points on the map
// this need to be rewritten since we dont need to iterate throught the 
list of points since each points has pointers to down and right
*/
int	draw_lines(t_data *info, t_map ***map)
{
	int	count_x;
	int	count_y;
	// Loop through all the points in the map and draw lines
	count_y = 0;
	while (y <= info->max_y)
	{
		count_x = 0;
		while (x <= info->max_x)
		{
			// Draw a line but how?
			if (x < info->max_x)
				drawing();
			if (y < info->max_y)
				drawing();
			x++;
		}
		y++;
	}
	return (0);
}

/*GENERAL FORMULA TO FIND THE INDEX 
in the char * (a string)

index = lsize * y + x * (bits / 8)
	int	i;
	i = info->lsize * y + x * (info->bits / 8);

THIS IS THE STRUCT TO IMPLEMENT INSIDE THE HEADER:
typedef	struct s_bres
{
	int	x;
	int	x0;
	int	y;
	int	y0;
	int	delta_x;
	int	delta_y;
	int	slope;
	int	decision_p;
}	t_bres;
*/
