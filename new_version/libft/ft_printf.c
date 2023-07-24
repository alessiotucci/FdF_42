/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:50:38 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/07 10:55:47 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* 
* This software is made available to anyone who wants to retrace the 
* author's learning path through the projects of school 42.
* Copyright (C) 2023  fporciel
* 
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
*
* You can contact the author at: 
*- fporciel@student.42roma.it
*/

#include "libft.h"

static int	ft_printf2(const char *format, int *i)
{
	int	result;

	result = 0;
	(*i)++;
	if (format[(*i)] == 37)
	{
		write(1, &(format[(*i)]), 1);
		result++;
	}
	(*i)++;
	return (result);
}

static int	ft_printf1(const char *format, va_list ap, int result)
{
	int	i;

	i = 0;
	while (format[i] != 0)
	{
		if (format[i] != 37)
		{
			write(1, &(format[i]), 1);
			result++;
			i++;
		}
		else if (ft_is_format_spec(format, i) == 0)
			i++;
		else if (ft_is_format_spec(format, i) == 1)
			result = result + ft_printf2(format, &i);
		else if (ft_is_format_spec(format, i) == 2)
			result = result + ft_conversion(format, &i, ap);
	}
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		result;

	if ((format == NULL) || (format[0] == 0))
		return (0);
	va_start(ap, format);
	result = 0;
	result = ft_printf1(format, ap, result);
	va_end(ap);
	return (result);
}
