/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:33:06 by atucci            #+#    #+#             */
/*   Updated: 2023/10/01 15:38:04 by atucci           ###   ########.fr       */
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

void isometric(t_date *info, t_point **head)
{
	if(info && head)
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
			//if (current->go_right->go_down != NULL)
				//bresenham(info, current, current->go_right->go_down);
		}
		if (current->go_down != NULL)
		{
			ft_printf("%sbres:[%p]going down%s--v\n", BG_CYAN, current, RESET);
			bresenham(info, current, current->go_down);
		}
		current = current->next;
	}
}

