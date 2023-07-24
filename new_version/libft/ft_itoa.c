/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:01:27 by fporciel          #+#    #+#             */
/*   Updated: 2023/02/06 16:46:01 by fporciel         ###   ########.fr       */
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

static int	ft_isnegative(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

static int	ft_howdigit(int n)
{
	int	i;
	int	j;

	i = 0;
	j = n;
	while (j > 9)
	{
		j = (j / 10);
		i++;
	}
	i++;
	return (i);
}

static char	*ft_trueitoa(char *itoa, int n2, int k, int n)
{
	int	n1;

	n1 = 0;
	if (ft_isnegative(n2) == 1)
		k = (k + 1);
	itoa[k] = 0;
	k--;
	while (k > 0)
	{
		n1 = (n % 10);
		itoa[k] = (n1 + 48);
		n = (n / 10);
		k--;
	}
	if (ft_isnegative(n2) == 1)
		itoa[k] = 45;
	else
		itoa[k] = ((n % 10) + 48);
	return (itoa);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	int		k;
	int		n2;

	n2 = n;
	if (ft_isnegative(n) == 1)
		n = -n;
	k = ft_howdigit(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (ft_isnegative(n2) == 1)
		itoa = (char *)malloc(sizeof(char) * (k + 2));
	else
		itoa = (char *)malloc(sizeof(char) * (k + 1));
	if (itoa == NULL)
		return (NULL);
	ft_trueitoa(itoa, n2, k, n);
	return (itoa);
}
