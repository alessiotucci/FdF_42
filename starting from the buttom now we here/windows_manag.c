/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_manag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:19:48 by atucci            #+#    #+#             */
/*   Updated: 2023/09/25 21:56:10 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	new_image(t_graphics *manager, t_date *inf)
{
	manager->img = mlx_new_image(manager->win, inf->width, inf->height);
	if (manager->img == NULL) // this will be modify later on
		exit(0);// use the clean_close?
	manager->img_data = mlx_get_data_addr(manager->img, &(manager->bits), &(inf->rows), &(manager->endian));
	if (manager->img_data == NULL)
		exit(0); // use the clean close?
	mlx_put_image_to_window(manager->win, manager->mlx, manager->img, 0, 0);
}
/* This function perfom a cleana close and then exit*/
void	clean_close(t_graphics *project)
{
	mlx_destroy_window(project->mlx, project->win);
	//mlx_terminate(project->win);
	exit(0);
}

/* This function handle the ESC key press*/
int	esc_pressed(int keycode, void *param)
{
	t_graphics *project;

	project = (t_graphics *)param;
	if (keycode == ESCAPE)
	{
	clean_close(project);
	return (0);
	}
	return (0);
}

void	new_windows(t_graphics *help, t_date *infos)
{
	help->win = mlx_init();
	if (help->win == NULL)
		exit(0);
	mlx_new_window(help->win, infos->width, infos->height, "testing out");
//	mlx_hook(help->win, KeyPress, KeyPressMask, esc_pressed); // to be tested
	mlx_loop(help->win);
	return ;
}
