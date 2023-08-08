/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:28:24 by atucci            #+#    #+#             */
/*   Updated: 2023/03/27 11:24:20 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_u(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int	ft_pointer(unsigned long nb)
{
	char	*str;
	char	*hex;
	int		i;
	int		count;

	count = 0;
	count += pt_putstr("0x");
	hex = "0123456789abcdef";
	str = (char *)malloc((ft_len_u(nb) + 1) * sizeof(char));
	if (!str)
		return (0);
	i = ft_len_u(nb);
	str[i] = '\0';
	i--;
	if (nb == 0)
		str[0] = '0';
	while (nb != 0)
	{
		str[i] = hex[nb % 16];
		nb = nb / 16;
		i--;
	}
	count += pt_putstr(str);
	free(str);
	return (count);
}
