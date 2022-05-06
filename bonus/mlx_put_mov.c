/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_mov.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:52:10 by ibenmain          #+#    #+#             */
/*   Updated: 2022/05/06 11:48:20 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_print_movement(t_data *data)
{
	data->nb_mov = ft_itoa(data->count_mov);
	data->str = ft_join("Move: ", data->nb_mov);
	free(data->nb_mov);
	mlx_string_put(data->mlx, data->mlx_win, 20, 20, 0xFFFFFF, data->str);
	free(data->str);
}

int	add_img_to_window(t_data *data)
{
	data->width = IMG_SIZE;
	data->height = IMG_SIZE;
	data->i = 0;
	while (data->i < data->count_line)
	{
		data->j = 0;
		data->w = 0;
		while (data->j < ft_strlen(data->map[0]) - 1)
		{
			ft_put_image_to_window(data);
			data->j++;
			data->w += IMG_SIZE;
		}
		data->i++;
		ft_print_movement(data);
		ft_enemy(data);
	}
	return (0);
}

void	ft_p_e(t_data *data)
{
	if (data->map[data->i][data->j] == 'P')
	{
		if (data->is_left)
			mlx_put_image_to_window(data->mlx, data->mlx_win, \
				data->player_left, data->w, IMG_SIZE * data->i);
		else
			mlx_put_image_to_window(data->mlx, data->mlx_win, \
				data->player, data->w, IMG_SIZE * data->i);
	}
	if (data->map[data->i][data->j] == 'E')
	{
		if (data->coll == data->nb_coin)
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->dor2, \
				data->w, IMG_SIZE * data->i);
		else
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->dor1, \
				data->w, IMG_SIZE * data->i);
	}
}

void	ft_put_image_to_window(t_data *data)
{
	if (data->map[data->i][data->j] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall, \
			data->w, IMG_SIZE * data->i);
	if (data->map[data->i][data->j] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground, \
			data->w, IMG_SIZE * data->i);
	ft_p_e(data);
	if (data->map[data->i][data->j] == 'H')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->enemy, \
			data->w, IMG_SIZE * data->i);
	ft_put_img_bonus(data);
}
