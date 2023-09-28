/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_manag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:19:48 by atucci            #+#    #+#             */
/*   Updated: 2023/09/28 17:53:41 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"


void	new_image(t_date *inf)
{
	ft_printf("\nInside new image function;\ngetting address in img_data\n:::::::::::::::::\n\n");
	inf->img_pointer = mlx_new_image(inf->mlx, inf->width, inf->height);
	inf->img_string = mlx_get_data_addr(inf->img_pointer, &(inf->bits), &(inf->lsize), &(inf->endian));

}
/* This function perfom a cleana close and then exit*/
void	clean_close(t_date *project)
{
	mlx_destroy_window(project->mlx, project->window);
	exit(0);
}

/* This function handle the ESC key press*/
int	key_pressed(int keycode, void *param)
{
	t_date *help = (t_date *) param;
	if (keycode == ESCAPE)
		clean_close(help);
	else if (keycode == PLUS)
		test_function(help);
	else if (keycode == MINUS)
		test_function(help);
	else if (keycode == SPACE)
		test_function(help);
	else if (keycode == MOUSE_WHEEL_UP)
		test_function(help);
	else if (keycode == MOUSE_WHEEL_DOWN)
		test_function(help);
	return (1);
}
/* copied form gpt*/
int	window_close(void *param)
{
	t_date *help = (t_date *)param;
// Your cleanup or exit code here
clean_close(help);
return (0); // Return 0 to indicate that the event has been handled
}


void	new_windows(t_date *help, t_point **head)
{
	help->mlx = mlx_init(); ft_printf("mlx_init has started\t");
	if (help->mlx == NULL)
		exit(0);
	help->window = mlx_new_window(help->mlx, help->width, help->height, "testing out");
	new_image(help);
	mlx_hook(help->window, 2, 1, key_pressed, help); // to be tested
	mlx_hook(help->window, 17, 0L, window_close, help);
	draw_lines(help, head);
/*
	if(head)
		my_mlx_pixel_put(help, 280, 142, 0x00FF0000);
		my_mlx_pixel_put(help, 290, 143, 0x00FF0000);
		my_mlx_pixel_put(help, 300, 141, 0x00FF0000);
		my_mlx_pixel_put(help, 295, 142, 0x00FF0000);
		my_mlx_pixel_put(help, 265, 140, 0x00FF0000);
		my_mlx_pixel_put(help, 349, 141, 0x00FF0000);
		my_mlx_pixel_put(help, 265, 143, 0x00FF0000);
		my_mlx_pixel_put(help, 256, 143, 0x00FF0000);
		my_mlx_pixel_put(help, 280, 144, 0x00FF0000);
*/
	mlx_put_image_to_window(help->mlx, help->window, help->img_pointer, 0, 0);
	ft_draw_instructions(help);

	mlx_loop(help->mlx);
	return ;
}
