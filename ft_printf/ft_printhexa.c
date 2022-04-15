/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 16:04:47 by ibenmain          #+#    #+#             */
/*   Updated: 2022/01/01 16:31:59 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_puthexa_size(unsigned long nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
	{
		nbr *= -1;
		len++;
	}
	while (nbr != 0)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

int	ft_puthexa(unsigned long nbr)
{
	unsigned long	n;

	n = nbr;
	if (n >= 16)
		ft_puthexa(n / 16);
	ft_putchar(HEXA_L[n % 16]);
	return (ft_puthexa_size(nbr));
}
