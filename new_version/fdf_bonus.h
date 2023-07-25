/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:24:37 by fporciel          #+#    #+#             */
/*   Updated: 2023/07/25 11:03:09 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* 
* This software is made available to anyone who wants to retrace the 
* author's learning path through the projects of school 42.
* Copyright (C) 2023  fporciel
* 
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
*
* You can contact the author at: 
*- fporciel@student.42roma.it
*/

#ifndef FDF_BONUS_H
# define FDF_BONUS_H
# include "./mlx_linux/mlx.h"
# include "./mlx_linux/mlx_int.h"
# include "./libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

# ifndef DEFAULT_WIDTH
#  define DEFAULT_WIDTH 1280
# endif

# ifndef DEFAULT_HEIGHT
#  define DEFAULT_HEIGHT 720
# endif

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	int			win_width;
	int			win_height;
	int			img_width;
	int			img_height;
	int			fd;
	int			garbage;
	int			chg_projection;
	int			max_x;
	int			max_y;
	int			y_count;
	int			x_count;
	int			z_count;
	ssize_t		count;
	char		projection_type;
	char		pre_buf;
	char		nex_buf;
}				t_data;

typedef struct s_map
{
	int					x_orthogonal;
	int					y_orthogonal;
	int					z_orthogonal;
	int					x_display;
	int					y_display;
	int					z_display;
	int					color;
	int					stop_param;
	struct s_map		*right_point;
	struct s_map		*down_point;
}						t_map;

int	main(int argc, char **argv);
int	map_registration(t_data *info);
int	points_conjunction(t_data *info, t_map ***map);
int	connection_management(t_data *info, t_map ***map);
int	isometric(t_data *info, t_map ***map);
int	parallel_ortographic(t_data *info, t_map ***map);
int	equirectangular(t_data *info, t_map ***map);
int	zoom(t_data *info, t_map ***map);
int	translation(t_data *info, t_map ***map);
int	rotation(t_data *info, t_map ***map);
int	image_management(t_data *info, t_map ***map);
int	set_pixel_values(t_data *info, t_map ***map);
int	display_image(t_data *info, t_map ***map);
// for testing
void	printMap(t_map *map);
int	keep_checking(t_data *info, t_map ***map);


#endif