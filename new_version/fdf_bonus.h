/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:24:37 by fporciel          #+#    #+#             */
/*   Updated: 2023/08/01 17:16:38 by atucci           ###   ########.fr       */
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


# ifndef PI
#  define PI 3.14159265358979323846
# endif

typedef struct s_map
{
	int					x_orthogonal;
	int					y_orthogonal;
	int					z_orthogonal;
	int					x_display;
	int					y_display;
	int					z_display;
	int					x_precision;
	int					y_precision;
	int					z_precision;
	int					color;
	int					stop_param;
	struct s_map		*right_point;
	struct s_map		*down_point;
}						t_map;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	int			width;
	int			height;
	int			fd;
	int			garbage;
	int			max_x;
	int			max_y;
	int			y_count;
	int			x_count;
	int			z_count;
	int			projection_check;
	int			zoom_plus_check;
	int			zoom_minus_check;
	int			right_trans_check;
	int			left_trans_check;
	int			up_trans_check;
	int			down_trans_check;
	int			right_rot_check;
	int			left_rot_check;
	int			up_rot_check;
	int			down_rot_check;
	int			keyrel;
	int			param;
	int			bits;
	int			lsize;
	int			endian;
	int			first_iteration;
	int			trans_x;
	int			trans_y;
	int			x;
	int			y;
	double		spacing;
	double		scaling;
	double		min_x;
	double		min_y;
	double		maxim_x;
	double		maxim_y;
	double		central_x;
	double		central_y;
	ssize_t		count;
	char		*img_data;
	char		projection_type;
	char		pre_buf;
	char		nex_buf;
	t_map		***map;
}				t_data;

typedef	struct s_bres
{
	int	x;
	int	x0;
	int	y;
	int	y0;
	int	delta_x;
	int	delta_y;
	int	slope;
	int	decision_p;
}	t_bres;

int	main(int argc, char **argv);
int	map_registration(t_data *info);
int	connection_management(t_data *info);
int	projection_function(t_data *info, t_map ***map);
int	transformation_function(t_data *info, t_map ***map, int to, int param);
int	draw_lines(t_data *info, t_map ***map);

// OLD VERSION OF THE HEADER FILE
int	points_conjunction(t_data *info, t_map ***map);
int	connection_management(t_data *info);
//int	isometric(t_data *info);
//int	orthographic(t_data *info);
//int	equirectangular(t_data *info);
int	zoom(t_data *info, t_map ***map, int to);
int	translation(t_data *info, t_map ***map, int to);
int	rotation(t_data *info, t_map ***map, int to);
int	image_sizeing_and_posit(t_data *info, t_map ***map);
int	draw_the_image(t_data *info, t_map ***map);
int	draw_lines(t_data *info, t_map ***map);
// for testing
int	keep_checking(t_data *info, t_map ***map);


#endif
