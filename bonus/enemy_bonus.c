/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:48:29 by ibenmain          #+#    #+#             */
/*   Updated: 2022/04/13 23:17:52 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_enemy_up(t_data *data)
{
	if (data->map[data->pos_h_i - 1][data->pos_h_i] == '1'
		|| data->map[data->pos_h_i - 1][data->pos_h_i] == 'E'
			|| data->map[data->pos_h_i - 1][data->pos_h_i] == 'C')
		return (0);
	if (data->map[data->pos_h_i - 1][data->pos_h_i] == '0')
	{
		data->map[data->pos_h_i--][data->pos_h_i] = '0';
		data->map[data->pos_h_i][data->pos_h_i] = 'H';
	}
	return (0);
}

int	ft_enemy_down(t_data *data)
{
	if (data->map[data->pos_h_i + 1][data->pos_h_i] == '1'
		|| data->map[data->pos_h_i + 1][data->pos_h_i] == 'E'
			|| data->map[data->pos_h_i + 1][data->pos_h_i] == 'C')
		return (0);
	if (data->map[data->pos_h_i + 1][data->pos_h_i] == '0')
	{
		data->map[data->pos_h_i++][data->pos_h_i] = '0';
		data->map[data->pos_h_i][data->pos_h_i] = 'H';
	}
	return (0);
}

// int	ft_enemy_left(t_data *data)
// {
// 	if (data->map[data->pos_h_i][data->pos_h_i - 1] == '1'
// 		|| data->map[data->pos_h_i][data->pos_h_i - 1] == 'E'
// 			|| data->map[data->pos_h_i][data->pos_h_i - 1] == 'C')
// 		return (0);
// 	if (data->map[data->pos_h_i][data->pos_h_i - 1] == '0')
// 	{
// 		data->map[data->pos_h_i][data->pos_h_i--] = '0';
// 		data->map[data->pos_h_i][data->pos_h_i] = 'H';
// 	}
// 	return (0);
// }

// int	ft_enemy_right(t_data *data)
// {
// 	if (data->map[data->pos_h_i][data->pos_h_i + 1] == '1'
// 		|| data->map[data->pos_h_i][data->pos_h_i + 1] == 'E'
// 			|| data->map[data->pos_h_i][data->pos_h_i + 1] == 'C')
// 		return (0);
// 	if (data->map[data->pos_h_i][data->pos_h_i + 1] == '0')
// 	{
// 		data->map[data->pos_h_i][data->pos_h_i + 1] = '0';
// 		data->map[data->pos_h_i][data->pos_h_i] = 'H';
// 	}
// 	return (0);
// }

void	ft_enemy(t_data *data)
{
	while (1)
	{
		ft_enemy_up(data);
		ft_enemy_down(data);
	}
	// ft_enemy_left(data);
	// ft_enemy_right(data);
}
