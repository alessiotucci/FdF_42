/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:21:47 by atucci            #+#    #+#             */
/*   Updated: 2023/09/21 09:27:07 by atucci           ###   ########.fr       */
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

/*Function to update the pointers of the linked list*/
int	point_connect(t_point **head, t_date *my_info)
{
	t_point *current;
	int	y;
	int	x;

	y = 0;
	current = *head;
	while (y < my_info->colums) // double check this while condititon
	{
		x = 0;
		while (x < my_info->rows)
		{
			if (current->next->x_map == current->x_map)
				update_point_connect(current, current->next, NULL);
		// update the curr = curr->next;
		x++;
		}
		y++;
	}
	ft_printf("this is where the fun start\n");
return (0);
}
