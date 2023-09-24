/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_manag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:19:48 by atucci            #+#    #+#             */
/*   Updated: 2023/09/24 17:18:43 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	new_windows(t_graphics *help, t_date *infos)
{
	help->win = mlx_init();
	if (help->win == NULL)
		exit(0);
	mlx_new_window(help->win, infos->width, infos->height, "testing out");
	mlx_loop(help->win);
	return ;
}
