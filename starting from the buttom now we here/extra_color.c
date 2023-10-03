/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:33:06 by atucci            #+#    #+#             */
/*   Updated: 2023/10/03 13:35:01 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./libft/libft.h"

int	check_commas(char *str, t_point *new_node)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if (str[count] == ',')
			return (color_zed(str, new_node));
		new_node->color = 0;
		count++;
	}
	return (ft_atoi(str));
}
/* Define a custom function to convert a hexadecimal string to an integer */

unsigned long	ft_strtol(const char *str)
{
	const char		*hex;
	unsigned long	result;
	const char		*ptr;

	hex = "0123456789abcdef";
	result = 0;
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		str += 2;
	while (*str != '\0')
	{
		ptr = ft_strchr(hex, *str);
		if (ptr == NULL)
			break ;
		result = result * 16 + (ptr - hex);
		str++;
	}
	return (result);
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
	new_node->color = ft_strtol(&input[i]);
	return (z);
}
/* ************************************************************************** */
