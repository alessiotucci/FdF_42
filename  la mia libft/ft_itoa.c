/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:10:24 by atucci            #+#    #+#             */
/*   Updated: 2023/01/30 16:10:53 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static unsigned int	digits(int n)
{
	unsigned int	count;

	if (n > 0)
		count = 0;
	else
	count = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	long	niu;

	niu = n;
	len = digits(niu);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == 0)
		return (0);
	if (niu < 0)
	{
		res[0] = '-';
		res[len--] = '\0';
		niu = -niu;
	}
	else
		res[len--] = '\0';
	if (niu == 0)
		res[0] = '0';
	while (niu > 0)
	{
	res[len--] = (niu % 10) + '0';
	niu /= 10;
	}
	return (res);
}
