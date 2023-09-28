/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:30:57 by atucci            #+#    #+#             */
/*   Updated: 2023/09/28 10:17:06 by atucci           ###   ########.fr       */
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

int	check_and_count(t_point *head, t_date *info_map)
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
	return (count);
}
/*create a function to link the points (go_down & go_right)*/

void	space_and_scale(t_date *inf)
{
	inf->scaling_x = inf->width / inf->colums;
	printf("the inf->scaling_x will be = %d / %d\n", inf->width, inf->colums);
	inf->scaling_y = inf->height / inf->rows;
	printf("the inf->scaling_y will be = %d / %d\n", inf->height, inf->rows);
	inf->center_x = (inf->width - (inf->colums * inf->scaling_x)) / 2;
	printf("ctr_x=(%d-(%d*%lf))/2\n", inf->width, inf->colums, inf->scaling_x);
	inf->center_x = (inf->height - (inf->rows * inf->scaling_y)) / 2;
	printf("ctr_y=(%d-(%d*%lf))/2\n", inf->height, inf->rows, inf->scaling_y);
}
/* ************************************************************************** */
