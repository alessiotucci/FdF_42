/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:33:06 by atucci            #+#    #+#             */
/*   Updated: 2023/10/01 13:22:19 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <math.h>


void isometric(t_date *info, t_point **head)
{
	t_point *current = *head;
	while (current != NULL)
	{
// Calculate the isometric X-coordinate
		current->x_pixel = info->center_x + ((current->x_map - current->y_map) * cos(PI / 6) * info->scaling_x);
// Calculate the isometric Y-coordinate
		current->y_pixel = info->center_y - (current->z_map * sin(PI / 6) * info->scaling_y) + ((current->x_map + current->y_map) * sin(PI / 6) * info->scaling_y);
	current = current->next;
	}
}

