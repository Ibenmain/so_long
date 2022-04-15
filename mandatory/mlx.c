/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:14:53 by ibenmain          #+#    #+#             */
/*   Updated: 2022/04/13 22:20:07 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_mlx(char **map, int nb_line, t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (-1);
	data->mlx_win = mlx_new_window(data->mlx, \
		(ft_strlen(map[0]) - 1) * IMG_SIZE, nb_line * IMG_SIZE, "./so_long");
	if (!data->mlx_win)
		return (-1);
	return (0);
}

void	add_image_xpm(t_data *data)
{
	data->wall = mlx_xpm_file_to_image(data->mlx, "img/wall.xpm", \
					&data->width, &data->height);
	data->ground = mlx_xpm_file_to_image(data->mlx, "img/ground.xpm", \
					&data->width, &data->height);
	data->player = mlx_xpm_file_to_image(data->mlx, "img/player.xpm", \
					&data->width, &data->height);
	data->coin = mlx_xpm_file_to_image(data->mlx, "img/coin.xpm", \
					&data->width, &data->height);
	data->dor1 = mlx_xpm_file_to_image(data->mlx, "img/dor1.xpm", \
					&data->width, &data->height);
	data->player_left = mlx_xpm_file_to_image(data->mlx, "img/player_left.xpm", \
					&data->width, &data->height);
}

void	ft_put_image_to_window(t_data *data)
{
	if (data->map[data->i][data->j] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall, \
			data->w, IMG_SIZE * data->i);
	if (data->map[data->i][data->j] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground, \
			data->w, IMG_SIZE * data->i);
	if (data->map[data->i][data->j] == 'P')
	{
		if (data->is_left)
			mlx_put_image_to_window(data->mlx, data->mlx_win, \
				data->player_left, data->w, IMG_SIZE * data->i);
		else
			mlx_put_image_to_window(data->mlx, data->mlx_win, \
				data->player, data->w, IMG_SIZE * data->i);
	}
	if (data->map[data->i][data->j] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->coin, \
			data->w, IMG_SIZE * data->i);
	if (data->map[data->i][data->j] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->dor1, \
			data->w, IMG_SIZE * data->i);
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
	}
	return (0);
}
