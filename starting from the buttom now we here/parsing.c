/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:30:57 by atucci            #+#    #+#             */
/*   Updated: 2023/08/09 16:34:20 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	create_list(t_point **head, int x, int y, char *z_string)
{
	int		z;
	t_point	*new_node;
	t_point	*current;

	z = atoi(z_string);
	new_node = (t_point *)malloc(sizeof(t_point));
	if (new_node == NULL)
		exit(1);
	new_node->x_map = x;
	new_node->y_map = y;
	new_node->z_map = z;
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
