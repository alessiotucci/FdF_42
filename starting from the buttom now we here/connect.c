/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:21:47 by atucci            #+#    #+#             */
/*   Updated: 2023/09/21 10:43:50 by atucci           ###   ########.fr       */
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

/* let's try again with bard */
void	point_bard(t_point **head)
{
	t_point	*current;

	current = *head;
	if (current->next != NULL && current->next->x_map == current->x_map)
		current->go_right = current->next;
	if (current->next != NULL && current->next->y_map == current->y_map)
		current->go_down = current->next;
	current = current->next;
}

/*function to go down*/
void connect_down_nodes(t_point *current)
{
t_point *next_down_node;
t_point *node;

if (current == NULL)
		return;
// Find the next node in the list that has the same y value.
	next_down_node = NULL;
	node = current->next;
	while (node != NULL && node->y_map != current->y_map)
		node = node->next;
// Update the current node's go_down pointer to point to the next node in the list that has the same y value.
	current->go_down = next_down_node;
// Recursively connect the down nodes for the next node in the list.
	connect_down_nodes(current->next);
}

