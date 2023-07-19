/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:47:28 by atucci            #+#    #+#             */
/*   Updated: 2023/03/25 16:06:20 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	pt_putchar(char c)
{
	return (write(1, &c, 1));
}

int	pt_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
	count++;
	return (count);
}

int	pt_putstr(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (pt_putstr("(null)"));
	while (str[count])
	{
		pt_putchar(str[count]);
		count++;
	}
	return (count);
}
