/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printusg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 16:18:06 by ibenmain          #+#    #+#             */
/*   Updated: 2022/01/02 00:59:09 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_putusg_size(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

int	ft_putunsigned(unsigned int nbr)
{
	unsigned int	rest;
	unsigned int	n;

	n = nbr;
	rest = n % 10 + '0';
	n /= 10;
	if (n != 0)
		ft_putunsigned(n);
	ft_putchar(rest);
	return (ft_putusg_size(nbr));
}
