/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_manag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:19:48 by atucci            #+#    #+#             */
/*   Updated: 2023/09/25 13:36:35 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	new_image(t_grahics *manager, t_date *inf)
{
	manager->img = mlx_new_image(manager->win, inf->width, inf->height);
	if (manager->img == NULL) // this will be modify later on
		exit(0);
	manager->img_data = mlx_get_data_addr();
	if (manager->img_data == NULL)
		exit(0); // this need to be modify as well
	mlx_put_image_to_window();
}
/* This function perfom a cleana close and then exit*/
void	clean_close(t_graphics *project)
{
	mlx_destroy_window(project->win);
	mlx_terminate(project->win);
	exit(0);
}
void	new_windows(t_graphics *help, t_date *infos)
{
	help->win = mlx_init();
	if (help->win == NULL)
		exit(0);
	mlx_new_window(help->win, infos->width, infos->height, "testing out");
	mlx_loop(help->win);
	return ;
}
