/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 16:13:10 by ibenmain          #+#    #+#             */
/*   Updated: 2022/01/01 16:13:58 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int	ft_putptr(unsigned long nbr)
{
	int	ret;

	ft_putstr("0x");
	ret = ft_puthexa(nbr) + 2;
	return (ret);
}
