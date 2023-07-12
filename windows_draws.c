/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_draws.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:19:48 by atucci            #+#    #+#             */
/*   Updated: 2023/07/12 17:19:32 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void draw_a_line(void *ptr_need, void *windows_ptr, t_line point, int color)
{
	t_line	*current;
	int	x;
	int	y;
	
	current = &point;
	while (current != NULL)
	{
		x = (current->x * 640) / 3;
		y = (current->y * 480) / 3;
		mlx_pixel_put(ptr_need, windows_ptr,  x, y, color);
		current = current->next;
	}
}

void draw_a_point(void *ptr_need, void *windows_ptr, int x, int y, int color)
{
	mlx_pixel_put(ptr_need, windows_ptr,  x, y, color);
 	return ;
}

void	line_between_points(t_line **mappa, void *ptr_need, void *windows_ptr)
{
	t_line	*current;
	t_line	*start;
	t_line	*end;
	t_line	*line;
	t_line	*tmp;

	current = *mappa;
	while (current != NULL && current->next != NULL)
	{
		start = current;
		end = current->next;
		line = dham(*start, *end);
		ft_printf("\033[1;35mcreating a line between [%c] and [%c]\n\033[0m\n", start->name, end->name);
		print_list(&line);
	  //  ft_printf("\033[1;41mthis is the lenght [%d]\n\033[0m\n", get_lenght(line));
		tmp = line; //this is a weird stuff;
	   	while (tmp != NULL)
        {
            // Do something with the point (tmp->x, tmp->y, tmp->z)
			draw_a_line(ptr_need, windows_ptr, *line, 0xFF);
            // For example, you can print the coordinates:
          //  ft_printf("x: %d, y: %d, z: %d\n", tmp->x, tmp->y, tmp->z);
			tmp = tmp->next;
        }
		current = current->next;
	}
}


void    open_windows(int wid, int hei, t_line **mappa)
{
	void	*windows_pointer;
 	void	*pointer_needed;
	t_line	*tmp;
	int		pixel_x;
	int		pixel_y;

	tmp = *mappa;
 	pointer_needed = mlx_init();
 	// adding this check
	 if (!pointer_needed)
 		exit(1);
 	windows_pointer = mlx_new_window(pointer_needed, wid, hei, "this is a try");
	// I need to extract this while loops to create an other function to draw lines
	while (tmp != NULL)
 	{
	line_between_points(mappa, pointer_needed, windows_pointer);	
	pixel_x = (tmp->x * 640) / 3;// this is a small add, the number 3 is bc the map I am testing is a 3X3
	pixel_y = (tmp->y * 480) / 3;// in other case it should be the widht and height of the map, leave it like this for now
	draw_a_point(pointer_needed, windows_pointer, pixel_x, pixel_y, 0xFFFFFF);
	tmp = tmp->next;
	}
	mlx_loop(pointer_needed);
}
