/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:01:53 by atucci            #+#    #+#             */
/*   Updated: 2023/01/29 15:41:40 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *sour, size_t size)
{
	size_t	src_len;

	src_len = 0;
	if (size == 0)
		return (ft_strlen(sour));
	while (sour[src_len] && src_len < size - 1)
	{
		dest[src_len] = sour[src_len];
		src_len++;
	}
	if (src_len < size)
		dest[src_len] = '\0';
	while (sour[src_len])
		src_len++;
	return (src_len);
}
