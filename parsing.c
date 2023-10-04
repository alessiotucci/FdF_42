/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:30:57 by atucci            #+#    #+#             */
/*   Updated: 2023/10/03 20:13:59 by atucci           ###   ########.fr       */
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
	free(z_string);
}

/* this function frees and return 0 */
int	this_free(char *string)
{
	free(string);
	return (0);
}
/*Function to free the list*/

void	free_list(t_point *list)
{
	t_point	*temp;

	ft_printf("%s%sfreeing the list\n%s", YELLOW, BG_RED, RESET);
	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp);
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
	info_to_list(info_map, &head);
	point_connect(&head);
	space_and_scale(info_map);
	int_to_isometric_pixel(info_map, &head);
	return ;
}

/* here it was int_to_pixel(info_map, &head);*/
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
	inf->center_x = (inf->width - (inf->scaling * (inf->colums - 1))) / 2;
	inf->center_y = (inf->height - (inf->scaling * (inf->rows - 1))) / 2;
}
