/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:00:41 by atucci            #+#    #+#             */
/*   Updated: 2023/01/28 17:31:19 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *dest, int v, size_t count)
{
	char	*char_dest;
	size_t	c;

	char_dest = (char *) dest;
	c = 0;
	while (c < count)
	{
	char_dest[c] = v;
	c++;
	}
	return (char_dest);
}
