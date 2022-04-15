/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 15:59:27 by ibenmain          #+#    #+#             */
/*   Updated: 2022/01/02 15:48:46 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# define HEXA_L "0123456789abcdef"
# define HEXA_U "0123456789ABCDEF"

int	ft_printf(const char *str, ...);
int	ft_vprintf(char format, va_list count);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_strlen(char *s);
int	ft_putint(int nbr);
int	ft_putsize(int nbr);
int	ft_putunsigned(unsigned int nbr);
int	ft_putusg_size(unsigned int nbr);
int	ft_puthexa(unsigned long nbr);
int	ft_puthexa_size(unsigned long nbr);
int	ft_putupp_hexa(unsigned long nbr);
int	ft_putuph_size(unsigned long nbr);
int	ft_putptr(unsigned long nbr);

#endif
