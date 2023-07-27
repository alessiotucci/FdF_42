/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:33:30 by atucci            #+#    #+#             */
/*   Updated: 2023/07/27 11:31:15 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H

# include "./mlx_linux/mlx.h"
# include "./mlx_linux/mlx_int.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/stat.h>

# ifndef DEFAULT_WIDTH
# define DEFAULT_WIDTH 1280
# endif 

# ifndef DEFAULT_HEIGHT
# define DEFAULT_HEIGHT 720
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
	struct s__map		*right_point;
	struct s_map		*down_point;
}						t_map;

typedef struct s_bres
{
	int	x;
	int	y;
	int	delta_x;
	int	delta_y;
	int	slope;
	int	decison_p;
}		t_bres; 

int	main(int ac, char *av[]);
int	map_registration(t_data *info);
int	points_conjunction(t_data *info, t_map ***map);
int	connection_management(t_data *info, t_map ***map);
int	isometric(t_data *info, t_map ***map);
int	image_management(t_data *info, t_map ***map);
int	set_pixel_values(t_data *info, t_map ***map);
int	display_image(t_data *info, t_map ***map);
// to test 
void printMap( t_map *map);
#endif
