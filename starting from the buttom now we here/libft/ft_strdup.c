/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:06:46 by atucci            #+#    #+#             */
/*   Updated: 2023/01/29 11:39:49 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *sour)
{
	char	*dupli;
	int		len;

	len = ft_strlen(sour) + 1;
	dupli = malloc(len * sizeof(char));
	if (dupli == (void *)0)
	{
		return (0);
	}
	return (ft_memcpy(dupli, sour, len));
}
