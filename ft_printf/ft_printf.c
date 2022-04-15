/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 15:43:59 by ibenmain          #+#    #+#             */
/*   Updated: 2022/01/02 15:45:30 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vprintf(char format, va_list count)
{
	int	n;

	n = 0;
	if (format == 'c')
		n += ft_putchar(va_arg(count, int));
	else if (format == 's')
		n += ft_putstr(va_arg(count, char *));
	else if (format == 'd' || format == 'i')
		n += ft_putint(va_arg(count, int));
	else if (format == 'u')
		n += ft_putunsigned(va_arg(count, unsigned int));
	else if (format == 'x')
		n += ft_puthexa(va_arg(count, unsigned int));
	else if (format == 'X')
		n += ft_putupp_hexa(va_arg(count, unsigned int));
	else if (format == 'p')
		n += ft_putptr(va_arg(count, unsigned long));
	else if (format == '%')
		n += ft_putchar('%');
	return (n);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	ptr;

	len = 0;
	va_start(ptr, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c' || *str == 's' || *str == 'p' \
					|| *str == 'd' || *str == 'i' || *str == 'u' \
						|| *str == 'x' || *str == 'X' || *str == '%')
				len += ft_vprintf(*str, ptr);
			else
				len += ft_putchar(*str);
		}
		else
			len += ft_putchar(*str);
		str++;
	}
	va_end(ptr);
	return (len);
}
