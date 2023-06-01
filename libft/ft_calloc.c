/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:06:32 by atucci            #+#    #+#             */
/*   Updated: 2023/02/01 11:18:39 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*ptr;

	if (nmemb == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (ptr == 0)
	{
		return (0);
	}
	ft_memset(ptr, 0, total_size);
	return (ptr);
}
