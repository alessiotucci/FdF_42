/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:33:06 by atucci            #+#    #+#             */
/*   Updated: 2023/10/03 12:54:40 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_commas(char *str, t_point *new_node)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if (str[count] == ',')
			return (color_zed(str, new_node));
		count++;
	}
	return (atoi(str));
}

int	color_zed(char *input, t_point *new_node)
{
	int	i;
	int	z;
	int	color;

	i = 0;
	z = 0;
	color = 0;
	if (new_node)
		ft_printf("weird map but ok %p\n", new_node);
	while (input[i] != ',' && input[i] != '\0')
	{
		z = (z * 10) + (input[i] - '0');
		i++;
	}
	if (input[i] == ',')
		i++;
	while (input[i] != '\0')
	{
		color = (color * 10) + (input[i] - '0');
		i++;
	}
	return (z);
}
/* ************************************************************************** */
