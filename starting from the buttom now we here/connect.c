/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:21:47 by atucci            #+#    #+#             */
/*   Updated: 2023/09/21 14:48:15 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void update_point_connect(t_point *curr, t_point *right, t_point *down)
{
	if (right != NULL)
		curr->go_right = right;
	if (down != NULL)
		curr->go_down = down;
}

/*static function to return the wanted address with two coordinates passed*/
static t_point *address_finder(int coor_x, int coor_y, t_point **head)
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


