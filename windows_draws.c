/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_draws.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:19:48 by atucci            #+#    #+#             */
/*   Updated: 2023/07/10 17:00:12 by atucci           ###   ########.fr       */
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
 
	tmp = *linea;
 	pointer_needed = mlx_init();
 	// adding this check
	 if (!pointer_needed)
 		exit(1);
 	windows_pointer = mlx_new_window(pointer_needed, wid, hei, "this is a try");
	while (tmp != NULL)
 	{
	draw_a_point(pointer_needed, windows_pointer,tmp->x, tmp->y, 0xFFFFFF);
	tmp = tmp->next;
	}
	mlx_loop(pointer_needed);
}
