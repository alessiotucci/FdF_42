/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:21:47 by atucci            #+#    #+#             */
/*   Updated: 2023/09/30 21:03:19 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	update_point_connect(t_point *curr, t_point *rght, t_point *dwn)
{
	if (rght != NULL)
		curr->go_right = rght;
	if (dwn != NULL)
		curr->go_down = dwn;
}

/*static function to return the wanted address with two coordinates passed*/
static t_point	*address_finder(int coor_x, int coor_y, t_point **head)
{
	t_point	*current;

	current = *head;
	while (current != NULL)
	{
		if (current->x_map == coor_x && current->y_map == coor_y)
			return (current);
		current = current->next;
	}
	return (NULL);
}

/*Function to update the pointers of the linked list
	*let's try to rewrite this function entirely
	* */
int	point_connect(t_point **head)
{
	t_point	*current;
	t_point	*helper;

	current = *head;
	while (current != NULL)
	{
		helper = address_finder(current->x_map + 1, current->y_map, head);
		update_point_connect(current, helper, NULL);
		helper = address_finder(current->x_map, current->y_map + 1, head);
		update_point_connect(current, NULL, helper);
		current = current->next;
	}
	return (0);
}
/* THIS function will set the pixel values accordingly*/

void	int_to_pixel(t_date *info, t_point **head)
{
	t_point	*current;

	current = *head;
	while (current != NULL)
	{
		current->x_pixel = info->center_x + (current->x_map * info->scaling_x);
		current->y_pixel = info->center_y + (current->y_map * info->scaling_y);
		current = current->next;
	}
}
/*THIS WILL BE DELETED AFTERWARDS*/

void	print_infos(t_date *date)
{
	ft_printf("------------------------------------\n");
	ft_printf("|       info about the map         |\n");
	ft_printf("------------------------------------\n");
	ft_printf("rows: %d\n", date->rows);
	ft_printf("columns: %d\n", date->colums);
	ft_printf("total_points: %d\n", date->total_points);
	ft_printf("width: %d\n", date->width);
	ft_printf("height: %d\n", date->height);
	printf("scaling_x: %f\n", date->scaling_x);
	printf("scaling_y: %f\n", date->scaling_y);
	printf("center_x: %f\n", date->center_x);
	printf("center_y: %f\n", date->center_y);
	ft_printf("------------------------------------\n");
}
