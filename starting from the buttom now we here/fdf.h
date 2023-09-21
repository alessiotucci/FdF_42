/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:08:20 by atucci            #+#    #+#             */
/*   Updated: 2023/09/21 14:48:02 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

/* Define color macros */
# define GREEN   "\033[1;32m"
# define CYAN    "\033[1;36m"
# define YELLOW  "\033[1;33m"
# define RED     "\033[1;31m"
# define RESET   "\033[0m"

/* Define Background colors macros */
# define BG_RESET        "\033[49m"
# define BG_GREEN        "\033[42m"
# define BG_CYAN         "\033[46m"
# define BG_YELLOW       "\033[43m"
# define BG_RED          "\033[41m"

/* Define default size for the windows */
# define DEFAULT_WIDTH 1280
# define DEFAULT_HEIGHT 720

/* Useful Macros for the angles */
# define PI 3.14159265358979323846

/* Define the struct to hold the value of the map */
typedef struct s_point
{
	int		x_map;
	int		y_map;
	int		z_map;
	int		x_pixel;
	int		y_pixel;
	struct s_point	*go_right;
	struct s_point	*go_down;
	struct s_point	*next;
}		t_point;

/* Define the struct to use for managing windows, image a other stuff */
typedef struct s_date
{
	int	rows;
	int	colums;
	int	total_points;
	int	width;
	int	height;
	void	*mlx;
	void	*win;
	void	*img;
	int	bits;
	int	lsize;
	int	endian;
	char *img_data;
	double	spacing;
	double	scaling;

}		t_date;
void	create_list(t_point **head, int x, int y, char *z_string);
void	print_colored_list(t_point **head);
int	free_split(char **tab);
void	free_list(t_point *list);
int	check_and_count(t_point *head, t_date *info_map);
int	point_connect(t_point **head);
// bard
void	connect_down_nodes(t_point *current);
void	point_bard(t_point **head);
#endif
