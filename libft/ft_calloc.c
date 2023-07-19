/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:21:34 by fporciel          #+#    #+#             */
/*   Updated: 2023/02/07 16:23:19 by fporciel         ###   ########.fr       */
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

static void	*ft_callocmemset(void *cal, int c, size_t countsize)
{
	size_t	i;

	i = 0;
	while (i < countsize)
	{
		*((unsigned char *)cal + i) = (unsigned int)c;
		i++;
	}
	return (cal);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*cal;

	if ((count == SIZE_MAX) || (size == SIZE_MAX))
		return (NULL);
	cal = (void *)malloc(count * size);
	if (cal == NULL)
		return (NULL);
	ft_callocmemset(cal, 0, (count * size));
	return (cal);
}
