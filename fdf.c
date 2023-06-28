/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:33:06 by atucci            #+#    #+#             */
/*   Updated: 2023/06/28 13:45:21 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "fdf.h"
#include <mlx.h>
#include <stdio.h>

int	check_the_map(char *file_name)
{
	int len;
	char *last_char;
	char compare[] = ".fdf";
	int result;
	
	len = ft_strlen(file_name);
	last_char = &file_name[len - 4];
	result = ft_strncmp(last_char, compare, len);
	if (result != 0)
    {
	ft_printf("\033[1;37;45mWrong file name\033[0m\n");
	return (1);
	}
	result = open(file_name, O_RDONLY);
	if (result == -1)
		ft_printf("\033[1;31mcan't open the file\033[0m\n");
	return (result);

}

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
	int	fd;
	char *stringa;
	//
	width = STANDARD_WINDOWS_WIDTH;
	height = STANDARD_WINDOWS_HEIGHT;
	fd = ft_printf("\033[1;34mI am reading this file...\033[0m\n");   // Set text color to blue

	// int fuck = open(av[1], O_RDONLY);
	// char *string = get_next_line(fuck);	

	if (ac != 2 && av)
	{
		ft_printf("\033[1;31mexit\n");
		exit(0);
	}
	// I need to perfom the check of the map
	fd = check_the_map(av[1]);
	if (fd != 0)
	{
	ft_printf("\033[1;41mSEgmentation FAULt\033[0m\n");

	stringa = get_next_line(fd);
	open_windows(width, height);
	}
}