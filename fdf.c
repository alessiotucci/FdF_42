/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:33:06 by atucci            #+#    #+#             */
/*   Updated: 2023/07/10 16:10:10 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "fdf.h"
#include <mlx.h>
#include <stdio.h>

int	check_the_map(char *file_name)
{
	int len;
	char *last_char;
	char compare[] = ".fdf";
	int result;
	
	len = ft_strlen(file_name);
	last_char = &file_name[len - 4];
	result = ft_strncmp(last_char, compare, len);
	if (result != 0)
    {
	ft_printf("\033[1;37;45mWrong file name\033[0m\n");
	return (1);
	}
	result = open(file_name, O_RDONLY);
	if (result == -1)
		ft_printf("\033[1;31mcan't open the file\033[0m\n");
	return (result);

}


 void draw_a_point(void *ptr_need, void *windows_ptr, int x, int y, int color)
{
	mlx_pixel_put(ptr_need, windows_ptr,  x, y, color);
	return ;
}
 	void	open_windows(int wid, int hei, t_line **linea)
 {
 	void	*windows_pointer;
 	void	*pointer_needed;
	t_line	*tmp;

	tmp = *linea;
 	pointer_needed = mlx_init();
 	// adding this check
 	if (!pointer_needed)
 		exit(1);
	
 	windows_pointer = mlx_new_window(pointer_needed, wid, hei, "this is a try");
	while (tmp != NULL)
 	{
	draw_a_point(pointer_needed, windows_pointer,tmp->x, tmp->y, 0xFFFFFF);
	tmp = tmp->next;
	}
 	mlx_loop(pointer_needed);
 }
int	get_lenght(t_line *head)
{
	int	count;
	t_line *node;
	
	count = 0;
	node = head;
	while (node != NULL)
	{
		node = node->next;
		count++;
	}
	return (count);
}
t_line *from_ints_to_nodes(int x, int y, int z)
{
	t_line	*node;
	
	node = (t_line *)malloc(sizeof(t_line));
	if (node != NULL)
	{
		node->x = x;
		node->y = y;
		node->z = z;
		node->next = NULL;
	}
	return (node);
}
void	print_list(t_line **linea)
{
	t_line *tmp;
	
	tmp = *linea;
	while (tmp != NULL)
	{
		
		ft_printf("\nX[%d]\tY[%d]\tZ[%d]\n", tmp->x, tmp->y, tmp->z);
		tmp = tmp->next;
	}
}

int	main(int ac, char *av[])
{
	int width;
	int	height;
	int	fd;
	// this is for testing
	//
	width = STANDARD_WINDOWS_WIDTH;
	height = STANDARD_WINDOWS_HEIGHT;
	fd = ft_printf("\033[1;34mI am reading this file...\033[0m\n");   // Set text color to blue
	if (ac != 2 && av)
	{
		ft_printf("\033[1;31mexit\n");
		exit(0);
	}
	t_map	*mappetta = malloc(sizeof(t_map));	
	fd = check_the_map(av[1]);
	if (fd != 0)
	{
	// ft_printf("\npoint a [%d][%d]\n", a->x, a->y, a->z );
	// ft_printf("\npoint b [%d][%d]\n", b->x, b->y, b->z);
	//ft_printf("\nlunghezza dario (%d)\n", get_lenght(dario));

	//print_list(&dario);
	read_map(av[1], mappetta);
	print_matrix(mappetta);
//	t_line  *create_list_from_map(t_map *map);
	t_line *dario = create_list_from_map(mappetta);
	print_list(&dario);
	// now that I have a 2d char array I need to make a linked list of point;
	//
	
	//open_windows(width, height, &dario);
	}
}

