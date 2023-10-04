/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:23:56 by atucci            #+#    #+#             */
/*   Updated: 2023/01/30 15:24:22 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	num[12];
	int		i;
	long	nb;

	i = 0;
	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb == 0)
		num[i++] = '0';
	while (nb > 0)
	{
		num[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	while (i-- > 0)
		ft_putchar_fd(num[i], fd);
}
