/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:30:57 by atucci            #+#    #+#             */
/*   Updated: 2023/07/10 17:09:58 by atucci           ###   ########.fr       */
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

t_line	*create_list_from_map(t_map *map)
{
	t_line	*head = NULL;
	t_line	*current = NULL;
	int		x;
	int		y;
	int		z;

	x = 0;
	y = 0;
	while (y < map->width)
	{
		x = 0;
		while (x < map->height)
		{
			z = map->matrix[y][x] - 48;
			t_line *new_node = from_ints_to_nodes(x, y, z);
			if (head == NULL)
			{
				head = new_node;
				current = head;
			}
			else
			{
				current->next = new_node;
				current = current->next;
			}
		x++;
		}
	y++;
	}
return (head);
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



