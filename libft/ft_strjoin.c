/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:09:23 by atucci            #+#    #+#             */
/*   Updated: 2023/01/28 15:49:39 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		lentot;
	size_t	index;
	size_t	i;

	i = 0;
	index = 0;
	if (!s1 || !s2)
		return (0);
	lentot = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(lentot);
	if (str == 0)
		return (0);
	while (s1[index])
	{
		str[index] = s1[index];
		index++;
	}	
	while (s2[i])
	{
		str[index++] = s2[i++];
	}
	str[index] = '\0';
	return (str);
}
