/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:01:03 by fporciel          #+#    #+#             */
/*   Updated: 2023/02/09 15:21:33 by fporciel         ###   ########.fr       */
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

static int	ft_power(int base, int exp)
{
	int	power;

	power = base;
	if ((base == 0) && (exp != 0))
		return (0);
	if (exp == 0)
		return (1);
	if (exp == 1)
		return (base);
	if (exp == 2)
		return (base * base);
	while (exp > 1)
	{
		power = power * base;
		exp--;
	}
	return (power);
}

static int	ft_chkatoi(char *nptr)
{
	int	i;

	i = 0;
	while (!ft_isdigit((char)nptr[i]) && (nptr[i] != 0))
	{
		if (!(((char)nptr[i] == 43) || ((char)nptr[i] == 45))
			&& !(((char)nptr[i] == 32)
				|| (((char)nptr[i] >= 9) && ((char)nptr[i] <= 13))))
			return (0);
		if (((char)nptr[i] == 45) && (ft_isdigit((char)nptr[i + 1])))
			return (-1);
		if ((((char)nptr[i] == 43) || ((char)nptr[i] == 45))
			&& (!ft_isdigit((char)nptr[i + 1])))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	j;
	int	num;
	int	exp;

	i = 0;
	num = 0;
	j = 0;
	while (!ft_isdigit((char)nptr[i]) && (nptr[i] != 0))
		i++;
	j = i;
	while (ft_isdigit((char)nptr[i]))
		i++;
	exp = ((i - j) - 1);
	while (j < i)
	{
		num = num + (((char)nptr[j] - 48) * ft_power(10, exp));
		exp--;
		j++;
	}
	return (num * ft_chkatoi((char *)nptr));
}
