/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:33:30 by atucci            #+#    #+#             */
/*   Updated: 2023/07/10 16:28:56 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H
// define the standard windows size
# ifndef STANDARD_WINDOWS_WIDTH
#  define STANDARD_WINDOWS_WIDTH 640
# endif

# ifndef STANDARD_WINDOWS_HEIGTH
#  define STANDARD_WINDOWS_HEIGHT 480
# endif

typedef struct s_map
{
	int		height;
	int		width;
	char	**matrix;
}	t_map;

typedef struct s_line
{
	int x;
	int y;
	int	z;
	struct s_line *next;
}	t_line;

// includes
# include "libft/libft.h"
// including minilibx library
# include "minilibx_macos/mlx.h"
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stddef.h>
void	draw_a_point(void *ptr_need, void *windows_ptr, int x, int y, int color);
void    open_windows(int wid, int hei, t_line **linea);
t_line *drawline_breseham(t_line a, t_line b);
t_line *dham(t_line a, t_line b);
t_line *from_ints_to_nodes(int x, int y, int z);
int		read_map(char *av, t_map *map);
void	print_matrix(t_map *map);
void	height_width(t_map *map);
t_line  *create_list_from_map(t_map *map);
#endif
