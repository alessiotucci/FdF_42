/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:33:06 by atucci            #+#    #+#             */
/*   Updated: 2023/06/28 11:32:12 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
 void draw_a_point(void *ptr_need, void *windows_ptr, int x, int y, int color)
{

mlx_pixel_put(ptr_need, windows_ptr,  x, y, color);
return ;
}
static	void	open_windows(int wid, int hei)
{
	void	*windows_pointer;
	void	*pointer_needed;
	
	pointer_needed = mlx_init();
	// adding this check
	if (!pointer_needed)
		exit(1);
	
	windows_pointer = mlx_new_window(pointer_needed, wid, hei, "this is a try");

	draw_a_point(pointer_needed, windows_pointer, 250, 250, 0xFFFFFF);

	mlx_loop(pointer_needed);
}

int	main(int ac, char *av[])
{
	int width;
	int	height;
	
	width = STANDARD_WINDOWS_WIDTH;
	height = STANDARD_WINDOWS_HEIGHT;
	if (ac != 2 && av)
	{
		ft_printf("exit\n");
		exit(0);
	}
	else
		open_windows(width, height);
}