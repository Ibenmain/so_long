/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 16:09:22 by ibenmain          #+#    #+#             */
/*   Updated: 2022/01/02 00:55:16 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_putsize(int nbr)
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
		nbr /= 10;
		len++;
	}
	return (len);
}

int	ft_putint(int nbr)
{
	int			rest;
	long int	n;

	n = (long int)nbr;
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	rest = n % 10 + '0';
	n /= 10;
	if (n != 0)
		ft_putint(n);
	ft_putchar(rest);
	return (ft_putsize(nbr));
}
