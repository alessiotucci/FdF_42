/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:03:57 by atucci            #+#    #+#             */
/*   Updated: 2023/01/29 15:15:03 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			count;
	unsigned char	*p;

	p = (unsigned char *)str;
	count = 0;
	while (count < n)
	{
		if (*p == (unsigned char)c)
			return ((void *)p);
	count++;
	p++;
	}
	return (0);
}
