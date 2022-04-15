/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printupphexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 16:15:52 by ibenmain          #+#    #+#             */
/*   Updated: 2022/01/01 16:32:15 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_putuph_size(unsigned long n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		n *= -1;
		len++;
	}
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_putupp_hexa(unsigned long nbr)
{
	unsigned long	n;

	n = (unsigned long)nbr;
	if (n >= 16)
		ft_putupp_hexa(n / 16);
	ft_putchar(HEXA_U[n % 16]);
	return (ft_putuph_size(nbr));
}
