/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:08:20 by atucci            #+#    #+#             */
/*   Updated: 2023/08/09 14:52:31 by atucci           ###   ########.fr       */
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
#endif

/* Define default size for the windows */
# ifndef DEFAULT_WIDTH
#  define DEFAULT_WIDTH 1280
# endif

# ifndef DEFAULT_HEIGHT
#  define DEFAULT_HEIGHT 720
# endif

/* Useful Macros for the angles */
# ifndef PI
#  define PI 3.14159265358979323846
# endif

/* Define the struct to hold the value of the map */
typedef struct s_point
{
	int	x_map;
	int	y_map;
	int	z_map;
	int	x_pixel;
	int	y_pixel;
	struct	s_point *go_right;
	struct	s_point *go_down;
}		t_point;


void	parsing(void);
