/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:50:36 by atucci            #+#    #+#             */
/*   Updated: 2023/03/27 11:26:15 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -214783648 || n == INT_MIN)
		count += pt_putstr("-2147483648");
	else if (n < 0)
	{
		count += pt_putchar('-');
		n = -n;
		count += ft_putnbr(n);
	}
	else if (n > 9)
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	else
		count += pt_putchar(n + 48);
	return (count);
}

int	ft_number_base(unsigned long long int nbr, char *base)
{
	unsigned long long int	n;
	unsigned long long int	j;
	int						i;
	int						len;

	j = (unsigned long long int)pt_strlen(base);
	len = 1;
	i = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		i += pt_putchar('-');
	}
	n = nbr;
	while ((n / len) >= j)
		len *= j;
	while (len > 0)
	{
		i += pt_putchar(base[(n / len) % j]);
		len /= j;
	}
	return (i);
}

int	ft_putuns(unsigned int nbr)
{
	int	i;

	i = ft_number_base((unsigned long long int) nbr, "0123456789");
	return (i);
}

int	check_sign(int num)
{
	if (num < 0)
		return (-1);
	else if (num > 0)
		return (1);
	else
		return (0);
}
