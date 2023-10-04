/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:02:18 by atucci            #+#    #+#             */
/*   Updated: 2023/01/30 14:04:07 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *sour, size_t destsize)
{
	size_t	cu;
	size_t	di;

	if (dest == NULL && sour == NULL)
		return (0);
	if (destsize == 0)
		return (ft_strlen(sour));
	if (destsize <= ft_strlen(dest))
		return (destsize + ft_strlen(sour));
	cu = ft_strlen(dest);
	di = 0;
	while (sour[di] != '\0' && cu + 1 < destsize)
	{
		dest[cu] = sour[di];
		cu++;
		di++;
	}
	dest[cu] = '\0';
	return (ft_strlen(dest) + ft_strlen(&sour[di]));
}
