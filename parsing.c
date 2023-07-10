/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:30:57 by atucci            #+#    #+#             */
/*   Updated: 2023/07/10 12:54:02 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"
#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include "fdf.h"

int	read_map(char *av, t_map *map)
{
	char	*str;
	int		fd;
	char	*space_ptr;
	
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return(0);
	str = malloc((sizeof(char)) * 1000);
	read(fd, str, 1000);
		// Remove spaces from the input string
	space_ptr = ft_strchr(str, ' ');
	while (space_ptr != NULL)
	{
		ft_memmove(space_ptr, space_ptr + 1, ft_strlen(space_ptr));
		space_ptr = ft_strchr(str, ' ');
	}
	map->matrix = ft_split(str, '\n');
	if (!map->matrix)
		exit(0);
	height_width(map);
	three_dim_maps(map);
	close(fd);
	free(str);
	return (1);
}

void	print_matrix(t_map *map)
{
	int i;
	int j;

	i = 0;
	 while (map->matrix[i])
    {
        j = 0;
        while (map->matrix[i][j])
        {
            ft_printf("%c ", map->matrix[i][j]);
            j++;
        }
        ft_printf("\n");
        i++;
    }
}

void	height_width(t_map *map)
{
	int	i;
	int	j;
	
	i = 0;
	while (map->matrix[i])
		i++;
	map->height = i;
	if (i > 0)
	{
		j = 0;
		while (map->matrix[0][j])
			j++;
		map->width = j;
	}
}

void	three_dim_maps(t_map *map)
{
	int		y;
	int		x;

	map->coordinax = (int ***)malloc(map->height * sizeof(int **));
	y = 0;
	while (y < map->height)
	{
		map->coordinax[y] = (int **)malloc(map->width * sizeof(int *));
		x = 0;
		while (x < map->width)
		{
			map->coordinax[y][x] = (int *)malloc(sizeof(int));
			map->coordinax[y][x][0] = map->matrix[y][x] - '0';
			x++;
		}
	y++;
	}
}

void print_map(t_map *map)
{
	int y = 0;
	while (y < map->height)
	{
		int x = 0;
		while (x < map->width)
		{
			printf("%c ", map->matrix[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
		printf("\n");

	printf("\033[1;44mheight of the map [%d]\033[0m\n", map->height);
    printf("\033[1;46mwidth of the map [%d]\033[0m\n", map->width);


	printf("Coordinax:\n");
	y = 0;
	while (y < map->height)
	{
		int x = 0;
		while (x < map->width)
		{
			printf("\033[37m([%d], ", map->coordinax[y][x][0]);   // White color for x
			printf("\033[34m[%d], ", map->coordinax[y][x][1]);   // Blue color for y
			printf("\033[32m[%d])\n\033[0m ", map->coordinax[y][x][2]);  // Green color for z
			x++;
		}
		printf("\n");
		y++;
	}
}
