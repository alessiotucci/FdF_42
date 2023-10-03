/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:08:20 by atucci            #+#    #+#             */
/*   Updated: 2023/10/03 10:42:58 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>

/* Define keyboard code */
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126
# define MINUS 27
# define PLUS 24
# define SPACE 49
# define KEY_R 15
# define ESCAPE 53
/* color for printing on the screen*/
# define COLOR_WHITE 0xFFFFFF
# define COLOR_BLACK 0x000000
# define COLOR_RED 0xFF0000
# define COLOR_GREEN 0x00FF00
# define COLOR_BLUE 0x0000FF
# define COLOR_YELLOW 0xFFFF00
# define COLOR_MAGENTA 0xFF00FF
# define COLOR_CYAN 0x00FFFF
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



/* Define the struct used for graphis and other stuff
typedef struct s_graphics {
	void	*mlx;
	void	*win;
	void	*img;
	int	bits;
	int	lsize;
	int	endian;
	char	*img_data;
}		t_graphics;
*/

/* Define the struct to use for managing windows, image a other stuff */
typedef struct s_date
{
	char		*map_name;
	int		rows;
	int		map_width;
	int		colums;
	int		map_height;
	int		total_points;
	int		width;
	int		height;
	double	max_x;
	double	max_y;
	double	min_x;
	double	min_y;
	double	scaling;
	double	center_x;
	double	center_y;
	void	*mlx;
	void	*window;
	void	*img_pointer;
	int		bits;
	int		lsize;
	int		endian;
	char	*img_string;
}		t_date;

/* Define the struct to hold the value of the map */
typedef struct s_point
{
	t_date			*infa;
	int				x_map;
	int				y_map;
	int				z_map;
	int				x_pixel;
	int				y_pixel;
	int				z_pixel;
	int				color;
	struct s_point	*go_right;
	struct s_point	*go_down;
	struct s_point	*next;
}		t_point;

void	create_list(t_point **head, int x, int y, char *z_string);
void	print_colored_list(t_point **head);
int		free_split(char **tab);
void	free_list(t_point *list);
void	check_and_count(t_point *head, t_date *info_map);
int		point_connect(t_point **head);
/* bard */
void	connect_down_nodes(t_point *current);
void	new_windows(t_date *mac, t_point **head);
void	new_image(t_date *inf);
void	clean_close(t_date *project);
void	space_and_scale(t_date *info);
void	print_infos(t_date *info);
void	int_to_pixel(t_date *info, t_point **head);
void	int_to_isometric_pixel(t_date *info, t_point **head);
/*Adding the function to draw in the image*/
void	bresenham(t_date *info, t_point *start, t_point *end);
void	old_bresenham(t_date *info, t_point *start, t_point *end);
void	draw_point(t_date *info, int x, int y);
void	draw_lines(t_date *info, t_point **head);
/* using other function too*/
void	ft_draw_instructions(t_date *env);
int		key_pressed(int keycode, void *param);
void	test_function(t_date *env);
/* thanks to 42 Docs*/
void	my_mlx_pixel_put(t_date *date, int x, int y, int color);
void	isometric(t_date *info, t_point **head);
/* check for the commas*/
int		check_commas(char *str, t_point *new_node);
int		color_zed(char *input, t_point *new_node);
#endif
