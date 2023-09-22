/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_manag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:19:48 by atucci            #+#    #+#             */
/*   Updated: 2023/09/22 07:07:27 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./mlx/mlx.h"
# include "./mlx/mlx_int.h"
#include "fdf.h"
#include "./libft/libft.h"

void	new_windows(t_date *info_map)
{
	info_map->win = mlx_init();
	if (info_map->win == NULL)
		exit(0);
	mlx_new_window(info_map->win, info_map->width, info_map->height, "testing out");
	return ;
}
