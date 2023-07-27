/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_the_image_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:19:26 by atucci            #+#    #+#             */
/*   Updated: 2023/07/27 09:22:38 by atucci           ###   ########.fr       */
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

/*/ color the point of  the maps in the image
static void actual_draws(t_map *map)
{
	ft_printf("\tI am so dumb\n");
	printMap(map);
}
// bresenham algorithm function
*/
int	draw_lines(t_data *info, t_map ***map)
{
	ft_printf("I am dumb\n");
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
