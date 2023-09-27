/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_manag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:19:48 by atucci            #+#    #+#             */
/*   Updated: 2023/09/27 11:44:17 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	new_image(t_date *inf)
{
	ft_printf("\nInside new image function;\ngetting address in img_data\n:::::::::::::::::\n\n");
	inf->image_pointer = mlx_new_image(inf->window, inf->width, inf->height);
	if (inf->image_pointer == NULL) // this will be modify later on
		exit(0);// use the clean_close?
	inf->image_string = mlx_get_data_addr(inf->image_pointer, &(inf->bits), &(inf->rows), &(inf->endian));
	if (inf->image_string == NULL)
		exit(0); // use the clean close?
}
/* This function perfom a cleana close and then exit*/
void	clean_close(t_date *project)
{
	mlx_destroy_window(project->mlx, project->window);
	//mlx_terminate(project->win);
	exit(0);
}

/* This function handle the ESC key press*/
int	esc_pressed(int keycode, void *param)
{
	if (keycode && param)
	return (0);
	else
	return (1);
}

void	new_windows(t_date *help, t_point **head)
{
	help->mlx = mlx_init(); ft_printf("mlx_init has started\t");
	if (help->mlx == NULL)
		exit(0);
	help->window = mlx_new_window(help->mlx, help->width, help->height, "testing out");
	new_image(help);
//	mlx_hook(help->win, KeyPress, KeyPressMask, esc_pressed); // to be tested

	draw_lines(help, head);

	mlx_put_image_to_window(help->mlx, help->window, help->image_pointer, 0, 0);

	mlx_loop(help->mlx);
	return ;
}
