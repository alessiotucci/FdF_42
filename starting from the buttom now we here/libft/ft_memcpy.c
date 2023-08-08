/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:01:12 by atucci            #+#    #+#             */
/*   Updated: 2023/01/30 14:01:41 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *sour, size_t n)
{
	char	*char_dest;
	char	*char_sour;
	size_t	count;

	if (dest == 0 && sour == 0)
		return (0);
	count = 0;
	char_dest = (char *) dest;
	char_sour = (char *) sour;
	while (count < n)
	{
		char_dest[count] = char_sour[count];
		count++;
	}
	return (char_dest);
}
