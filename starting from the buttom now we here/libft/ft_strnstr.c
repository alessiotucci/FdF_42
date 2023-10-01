/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:30:59 by atucci            #+#    #+#             */
/*   Updated: 2023/10/01 11:02:56 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *nedle, size_t len)
{
	size_t	i;
	size_t	j;

	if (nedle[0] == '\0' || nedle == haystack)
		return ((char *)haystack);
	if (!len)
		return (0);
	i = 0;
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		while (i + j < len && haystack[i + j] == nedle[j] && nedle[j] != '\0')
		{
			j++;
		}
		if (ft_strlen(nedle) == j)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
