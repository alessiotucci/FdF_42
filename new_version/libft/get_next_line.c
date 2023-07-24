/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:27:41 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/28 09:37:27 by fporciel         ###   ########.fr       */
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

static void	*ft_free_null(char **buf, char **ptr, char **other_ptr)
{
	if ((*buf) == NULL)
		(*buf) = NULL;
	else
		free((*buf));
	(*buf) = NULL;
	if (ptr != NULL)
	{
		if ((*ptr) == NULL)
			(*ptr) = NULL;
		else
			free((*ptr));
		(*ptr) = NULL;
	}
	if (other_ptr != NULL)
	{
		if ((*other_ptr) == NULL)
			(*other_ptr) = NULL;
		else
			free((*other_ptr));
		(*other_ptr) = NULL;
	}
	return (NULL);
}

static ssize_t	get_length(char *buf, int kind_of_calculation)
{
	ssize_t	length;

	length = 0;
	if (buf == NULL)
		return (0);
	while ((buf[length]) && (buf[length] != 10))
		length++;
	if ((kind_of_calculation == 1) && (buf[length] == 10))
		return (1);
	if ((kind_of_calculation == 1) && (buf[length] != 10))
		return (0);
	if ((kind_of_calculation == 2) && (buf[length] == 10))
		return (length + 1);
	while ((buf[length]))
		length++;
	return (length);
}

static char	*get_realloc(char **buf, int kind_of_alloc)
{
	char	*new_buf;
	ssize_t	counter;

	counter = 0;
	if (kind_of_alloc == 0)
		new_buf = (char *)malloc(get_length((*buf), 0) + BUFFER_SIZE + 1);
	else if (kind_of_alloc == 3)
	{
		if (((*buf)[0]) != 0)
			return (*buf);
		else
			return (ft_free_null(buf, NULL, NULL));
	}
	else
		new_buf = (char *)malloc(get_length((*buf), 0) + 1);
	if (new_buf == NULL)
		return (ft_free_null(buf, NULL, NULL));
	while (((*buf) != NULL) && ((*buf)[counter]))
	{
		new_buf[counter] = ((*buf)[counter]);
		counter++;
	}
	new_buf[counter] = 0;
	(*buf) = ft_free_null(buf, NULL, NULL);
	return (new_buf);
}

static char	*get_return(char **buf)
{
	char	*line;
	char	*temp;
	ssize_t	counter;
	ssize_t	line_length;

	line_length = get_length((*buf), 2);
	line = (char *)malloc(line_length + 1);
	temp = (char *)malloc(get_length((*buf), 0) - line_length + 1);
	if ((line == NULL) || (temp == NULL) || ((*buf) == NULL))
		return (ft_free_null(buf, &line, &temp));
	counter = 0;
	while (counter < line_length)
	{
		line[counter] = ((*buf)[counter]);
		counter++;
	}
	line[counter] = 0;
	counter = 0;
	while (((*buf)[line_length]) != 0)
		temp[counter++] = ((*buf)[line_length++]);
	temp[counter] = 0;
	(*buf) = ft_free_null(buf, NULL, NULL);
	(*buf) = get_realloc(&temp, 3);
	return (get_realloc(&line, 3));
}

char	*get_next_line(int fd)
{
	static char	*buf;
	ssize_t		size;
	ssize_t		count;

	if ((fd < 0) || (fd > 4096) || (BUFFER_SIZE <= 0))
		return (NULL);
	size = get_length(buf, 0);
	count = 1;
	while ((!(get_length(buf, 1))) && (count > 0))
	{
		buf = get_realloc(&buf, 0);
		if (buf == NULL)
			return (NULL);
		count = read(fd, &(buf[size]), BUFFER_SIZE);
		if (count < 0)
			return (ft_free_null(&buf, NULL, NULL));
		size = (size + count);
		if (count != 0)
			buf[size] = 0;
		if ((count < BUFFER_SIZE) || (count == 0))
			break ;
	}
	if ((count < BUFFER_SIZE) || (count == 0))
		buf = get_realloc(&buf, 1);
	return (get_return(&buf));
}
