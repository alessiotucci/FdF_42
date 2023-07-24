/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:54:54 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/04 10:55:26 by fporciel         ###   ########.fr       */
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

static size_t	ft_slen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static size_t	ft_l(char const *s, unsigned int start, size_t len)
{
	size_t	j;

	j = 0;
	if (start >= ft_slen(s))
		return (0);
	while ((s[j]) && (j < len) && (s[start] != 0))
	{
		j++;
		start++;
	}
	return (j);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sstr;
	size_t	slen;
	size_t	i;
	size_t	j;

	if ((s == NULL) || (*s == 0))
		return (ft_strdup(""));
	slen = ft_slen(s);
	i = start;
	j = ft_l(s, start, len);
	sstr = (char *)malloc(sizeof(char) * (j + 1));
	if (sstr == NULL)
		return (NULL);
	j = 0;
	while ((start < slen) && (s[i]) && (j < len))
	{
		sstr[j] = s[i];
		i++;
		j++;
	}
	sstr[j] = 0;
	return (sstr);
}
