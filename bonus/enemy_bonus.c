/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:48:29 by ibenmain          #+#    #+#             */
/*   Updated: 2022/05/06 14:11:30 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_enemy_right(t_data *data, int i, int j)
{
	if (data->map[i][j + 1] == 'P')
		ft_print_message_error("You are die!\n");
	if (data->map[i][j + 1] == '0')
	{
		data->map[i][j++] = '0';
		data->map[i][j] = 'H';
	}
	return (0);
}

void	ft_move_enemy(int i, int j, t_data *data)
{
	int	x;

	x = rand() % 4;
	if (x == 0)
		ft_enemy_up(data, i, j);
	if (x == 1)
		ft_enemy_down(data, i, j);
	if (x == 2)
		ft_enemy_left(data, i, j);
	if (x == 3)
		ft_enemy_right(data, i, j);
}

void	ft_enemy(t_data *data)
{
	int			i;
	int			j;
	static int	v;

	i = 0;
	v++;
	if (v == 100)
	{
		while (i < data->count_line)
		{
			j = 0;
			while (j < ft_strlen(data->map[0]) - 1)
			{
				if (data->map[i][j] == 'H')
					ft_move_enemy(i, j, data);
				j++;
			}
		i++;
		}
		v = 0;
	}
}
