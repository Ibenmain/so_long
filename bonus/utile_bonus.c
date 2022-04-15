/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:28:43 by ibenmain          #+#    #+#             */
/*   Updated: 2022/04/13 22:55:22 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_print_message_error(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
	exit(0);
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

char	*ft_join(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	size_s1;
	size_t	size_s2;
	char	*new;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	new = (char *)malloc((size_s1 + size_s2) + 1 * sizeof(char));
	if (!new)
		return (NULL);
	while (i < size_s1)
	{
		new[i] = s1[i];
		i++;
	}
	while (j < size_s2)
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}
