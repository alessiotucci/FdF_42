/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_connection_management_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:53:52 by atucci            #+#    #+#             */
/*   Updated: 2023/07/26 18:40:48 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	release_management(int keycode, t_data *info)
{
	if (((keycode == 65362) || (keycode == 65364) || (keycode == 65361)
			|| (keycode == 65363) || (keycode == 119) || (keycode == 97)
			|| (keycode == 115) || (keycode == 100) || (keycode == 65451)
			|| (keycode == 65453))
		&& (info->keyrel == 0))
		info->keyrel = 1;
	return (0);
}

static int	transformation_management(int keycode, t_data *info)
{
	if ((keycode == 65293) && (info->projection_check < 2))
		info->projection_check++;
	else if ((keycode == 65293) && (info->projection_check == 2))
		info->projection_check = 0;
	else if ((keycode > 65360) && (keycode < 65365))
		transformation_function(info, info->map, keycode, 0);
	else if ((keycode == 119) || (keycode == 97) || (keycode == 115)
		|| (keycode == 100))
		transformation_function(info, info->map, keycode, 1);
	else if ((keycode == 65451) || (keycode == 65453))
		transformation_function(info, info->map, keycode, 2);
	if (keycode == 65293)
	{
		if (info->projection_check == 0)
			info->projection_type = 105;
		else if (info->projection_check == 1)
			info->projection_type = 112;
		else
			info->projection_type = 101;
		projection_function(info, info->map);
	}
	return (0);
}

static int	image_management(int keycode, t_data *info)
{
	int	bits;
	int	lsize;
	int	endian;

	if (keycode != 0)
	{
		mlx_destroy_image(info->mlx, info->img);
		mlx_clear_window(info->mlx, info->win);
		transformation_management(keycode, info);
	}
	info->img = mlx_new_image(info->mlx, info->width, info->height);
	info->img_data = mlx_get_data_addr(info->img, &bits, &lsize, &endian);
	info->bits = &bits;
	info->lsize = &lsize;
	info->endian = &endian;
	if (keycode == 0)
	{
		projection_function(info, info->map);
		transformation_function(info, info->map, keycode, 3);
	}
	draw_lines(info, info->map);
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
	return (0);
}

static int	closing_management(int keycode, t_data *info)
{
	if ((keycode == 65362) || (keycode == 65364) || (keycode == 65361)
		|| (keycode == 65363) || (keycode == 119) || (keycode == 97)
		|| (keycode == 115) || (keycode == 100) || (keycode == 65451)
		|| (keycode == 65453))
	{
		info->keyrel = 0;
		image_management(keycode, info);
		while (info->keyrel != 1)
			image_management(keycode, info);
	}
	else if (keycode == 65307 || keycode == 0)
	{
		mlx_destroy_image(info->mlx, info->img);
		mlx_destroy_window(info->mlx, info->win);
		mlx_destroy_display(info->mlx);
		exit(0);
	}
	else
		return (0);
	return (0);
}

int	connection_management(t_data *info)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, info->width, info->height, "FdF");
	mlx_hook(info->win, 2, (1L << 0), closing_management, info);
	mlx_hook(info->win, 17, (1L << 2), closing_management, info);
	image_management(0, info);
	mlx_hook(info->win, 3, (1L << 1), release_management, info);
	mlx_loop(info->mlx);
	return (0);
}
