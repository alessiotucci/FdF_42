/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:51:56 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/07 10:59:40 by fporciel         ###   ########.fr       */
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

int	ft_putnbr(int ap)
{
	int	ap1;
	int	result;

	if (ap == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	ap1 = ap;
	if (ap < 0)
	{
		ap1 = -ap1;
		result = 1;
	}
	else if (ap == 0)
		result = 1;
	else
		result = 0;
	while (ap1 > 0)
	{
		result++;
		ap1 = ap1 / 10;
	}
	ft_putnbr_fd(ap, 1);
	return (result);
}
