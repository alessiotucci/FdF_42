/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:30:57 by atucci            #+#    #+#             */
/*   Updated: 2023/10/02 20:09:55 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	create_list(t_point **head, int x, int y, char *z_string)
{
	t_point	*new_node;
	t_point	*current;

	new_node = (t_point *)malloc(sizeof(t_point));
	if (new_node == NULL)
		exit(1);
	new_node->x_map = x;
	new_node->y_map = y;
	new_node->z_map = check_commas(z_string, new_node);
	new_node->x_pixel = 0;
	new_node->y_pixel = 0;
	new_node->go_right = NULL;
	new_node->go_down = NULL;
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}

/*Function to free the list*/

void	free_list(t_point *list)
{
	t_point	*tempy;

	while (list != NULL)
	{
		tempy = list;
		list = list->next;
		free(tempy);
	}
}
/*This function check the size of the map,
 and update the info map struct accordingly*/

void	check_and_count(t_point *head, t_date *info_map)
{
	t_point	*goofy;
	int		count;

	count = 0;
	goofy = head;
	while (goofy != NULL)
	{
		if (goofy->next == NULL)
		{
			info_map->colums = goofy->x_map + 1;
			info_map->rows = goofy->y_map + 1;
		}
		goofy = goofy->next;
		count++;
	}
	info_map->total_points = count;
	point_connect(&head);
	space_and_scale(info_map);
	//int_to_pixel(info_map, &head);
	int_to_isometric_pixel(info_map, &head);
	return ;
}
/*create a function to link the points (go_down & go_right)*/

void	space_and_scale(t_date *inf)
{
	double	may;
	double	might;
	double	ipo;

	ipo = sqrt((pow(inf->colums - 1, 2) + pow(inf->rows - 1, 2)));
	may = inf->width / ipo;
	might = inf->height / ipo;
	inf->scaling = fmin(may, might);
	printf("the starting scaling is %lf\n", inf->scaling);
	inf->center_x = (inf->width - (inf->scaling * (inf->colums - 1))) / 2;
	ft_printf("\n--SPACE--AND--SCALE--\nscaling the map as orthogonal :(\n");
	printf("\nipo is %lf\n", ipo);
	printf("\nold center x[%lf]\n=(%d-(%d*%lf))/2\n", inf->center_x, inf->width,
		inf->colums - 1, inf->scaling);
	inf->center_y = (inf->height - (inf->scaling * (inf->rows - 1))) / 2;
	printf("\nold center y[%lf]\n=(%d-(%d*%lf))/2\n\n", inf->center_y,
		inf->height, inf->rows - 1, inf->scaling);
}

int	check_commas(char *str, t_point *new_node)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if (str[count] == ',')
			return (color_zed(str, new_node));
		count++;
	}
	return (atoi(str));
}

int	color_zed(char *input, t_point *new_node)
{
	int	i;
	int	z;
	int	color;

	i = 0;
	z = 0;
	color = 0;
	if (new_node)
		ft_printf("weird map but ok %p\n", new_node);
	while (input[i] != ',' && input[i] != '\0')
	{
		z = (z * 10) + (input[i] - '0');
		i++;
	}
	if (input[i] == ',')
		i++;
	while (input[i] != '\0')
	{
		color = (color * 10) + (input[i] - '0');
		i++;
	}
return (z);
}
/* ************************************************************************** */
