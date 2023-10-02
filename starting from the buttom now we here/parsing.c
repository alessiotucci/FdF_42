/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:30:57 by atucci            #+#    #+#             */
/*   Updated: 2023/10/02 12:51:50 by atucci           ###   ########.fr       */
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
	new_node->z_map = atoi(z_string);
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
	return;
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
	inf->center_x = (inf->width - (inf->scaling * (inf->colums - 1))) / 2;	//I have swapped the rows and colum
	printf("\n--SPACE--AND--SCALE--\nscaling the map as orthogonal :(\n");
	printf("\nipo is %lf\n", ipo);
	printf("\nold center x[%lf]\n=(%d-(%d*%lf))/2\n",inf->center_x, inf->width, inf->colums - 1, inf->scaling);
	inf->center_y = (inf->height - (inf->scaling * (inf->rows - 1))) / 2;
	printf("\nold center y[%lf]\n=(%d-(%d*%lf))/2\n\n\n",inf->center_y, inf->height, inf->rows - 1, inf->scaling);
}
/* ************************************************************************** */
