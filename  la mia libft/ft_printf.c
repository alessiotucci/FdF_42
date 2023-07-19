/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:39:36 by atucci            #+#    #+#             */
/*   Updated: 2023/03/27 11:24:01 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdarg.h>

static int	phold(va_list *arg, char q, int count)
{
	if (q == 'c')
		count += pt_putchar(va_arg(*arg, int));
	else if (q == 's')
		count += pt_putstr(va_arg(*arg, char *));
	else if (q == 'd' || q == 'i')
		count += ft_putnbr(va_arg(*arg, int));
	else if (q == 'p')
		count += ft_pointer(va_arg(*arg, unsigned long));
	else if (q == '%')
		count += pt_putchar('%');
	else if (q == 'u')
		count += ft_putuns(va_arg(*arg, unsigned int));
	else if (q == 'x')
		count += ft_number_base(va_arg(*arg, unsigned int), "0123456789abcdef");
	else if (q == 'X')
		count += ft_number_base(va_arg(*arg, unsigned int), "0123456789ABCDEF");
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	args;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{	
			count = phold(&args, ((char *) format)[i + 1], count);
			i++;
		}
		else
			count += pt_putchar(format[i]);
	i++;
	}
	va_end(args);
	return (count);
}
