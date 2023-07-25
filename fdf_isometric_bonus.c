/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_isometric_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:47:06 by atucci            #+#    #+#             */
/*   Updated: 2023/07/25 12:00:33 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/* build a macro to work  with radiants */

static	void	apply_iso_projection(t_map *pnt)
{
	pnt->x_display = (pnt->x_orthogonal - pnt->y_orthogonal) * cos(0.523599);
	pnt->y_display = - pnt->z_orthogonal + (pnt->x_orthogonal + pnt->y_orthogonal)
		* sin(0.523599);
}

int	isometric(t_data *info, t_map ***map)
{
	int	i;
	int	j;

	i = 0;
	while (i <= info->max_y)
	{
		j = 0;
		while (j <= info->max_x)
		{
			apply_iso_projection(map[i][j]);
			j++;
		}
		i++;
	}
return (0);
}

