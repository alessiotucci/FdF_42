/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:33:30 by atucci            #+#    #+#             */
/*   Updated: 2023/07/18 14:49:37 by atucci           ###   ########.fr       */
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
	void	*mlx;
	void	*win;
	void	*img;
	int	win_widht;
	int	win_height;
	char	project_type;
	int	fd;
	int	garbage;
	int	change_projection;
}		t_data;

typedef struct s_map
{
	int	x_orthogonal;
	int	y_orthogonal;
	int	z_orthogonal;
	int	x_display;
	int	y_display;
	int	color;
//	s_map	*right_point;
//	s_map	*down_point;

}		t_map;

int	main(int ac, char *av[]);
int	map_registration(t_data *info);
int	points_conjuction(t_data *info, t_map ***map);
int	connection_management(t_data *info, t_map ***map);
int	isometric(t_data *info, t_map ***map);
int	image_management(t_data *info, t_map ***map);
int	set_pixel_values(t_data *info, t_map ***map);
int	display_image(t_data *info, t_map ***map);

#endif
