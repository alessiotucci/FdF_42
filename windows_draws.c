/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_draws.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:19:48 by atucci            #+#    #+#             */
/*   Updated: 2023/07/12 12:13:37 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void draw_a_point(void *ptr_need, void *windows_ptr, int x, int y, int color)
{
	mlx_pixel_put(ptr_need, windows_ptr,  x, y, color);
 	return ;
}

void    open_windows(int wid, int hei, t_line **linea)
{
	void	*windows_pointer;
 	void	*pointer_needed;
	t_line	*tmp;
	int		pixel_x;
	int		pixel_y;

	tmp = *linea;
 	pointer_needed = mlx_init();
 	// adding this check
	 if (!pointer_needed)
 		exit(1);
 	windows_pointer = mlx_new_window(pointer_needed, wid, hei, "this is a try");
	// I need to extract this while loops to create an other function to draw lines
	while (tmp != NULL)
 	{
	pixel_x = (tmp->x * 640) / 3;// this is a small add, the number 3 is bc the map I am testing is a 3X3
	pixel_y = (tmp->y * 480) / 3;// in other case it should be the widht and height of the map, leave it like this for now
	draw_a_point(pointer_needed, windows_pointer, pixel_x, pixel_y, 0xFFFFFF);
	tmp = tmp->next;
	}
	mlx_loop(pointer_needed);
}
