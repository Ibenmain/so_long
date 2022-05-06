/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:10:55 by ibenmain          #+#    #+#             */
/*   Updated: 2022/05/06 14:11:20 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_enemy_up(t_data *data, int i, int j)
{
	if (data->map[i - 1][j] == 'P')
		ft_print_message_error("You are die!\n");
	if (data->map[i - 1][j] == '0')
	{
		data->map[i--][j] = '0';
		data->map[i][j] = 'H';
	}
	return (0);
}

int	ft_enemy_down(t_data *data, int i, int j)
{
	if (data->map[i + 1][j] == 'P')
		ft_print_message_error("You are die!\n");
	if (data->map[i + 1][j] == '0')
	{
		data->map[i++][j] = '0';
		data->map[i][j] = 'H';
	}
	return (0);
}

int	ft_enemy_left(t_data *data, int i, int j)
{
	if (data->map[i][j - 1] == 'P')
		ft_print_message_error("You are die!\n");
	if (data->map[i][j - 1] == '0')
	{
		data->map[i][j--] = '0';
		data->map[i][j] = 'H';
	}
	return (0);
}
