/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:28:43 by ibenmain          #+#    #+#             */
/*   Updated: 2022/04/08 16:27:24 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_message_error(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
	exit(1);
}

static int	ft_nbr(long int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	if (n == 0)
		count++;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static char	*ft_other_itoa(long int k, int size)
{
	char	*chain;

	chain = (char *)malloc(size + 1 * sizeof(char));
	if (!chain)
		return (NULL);
	chain[size--] = '\0';
	if (k < 0)
	{
		k *= -1;
		chain[0] = '-';
		while (size > 0)
		{
			chain[size--] = k % 10 + '0';
			k = k / 10;
		}
	}
	else
	{
		while (size >= 0)
		{
			chain[size--] = k % 10 + '0';
			k = k / 10;
		}
	}
	return (chain);
}

char	*ft_itoa(int n)
{
	char		*chain;
	int			size;
	long int	k;

	k = n;
	size = ft_nbr(k);
	chain = ft_other_itoa(k, size);
	return (chain);
}
