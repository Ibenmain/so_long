/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:14:53 by ibenmain          #+#    #+#             */
/*   Updated: 2022/04/13 22:30:06 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_mlx(char **map, int nb_line, t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (-1);
	data->mlx_win = mlx_new_window(data->mlx, \
		(ft_strlen(map[0]) - 1) * IMG_SIZE, nb_line * IMG_SIZE, "./so_long_b");
	if (!data->mlx_win)
		return (-1);
	return (0);
}

void	ft_mlx_coin(t_data *data)
{
	data->coin1 = mlx_xpm_file_to_image(data->mlx, "../bonus/image/coin1.xpm", \
					&data->width, &data->height);
	data->coin2 = mlx_xpm_file_to_image(data->mlx, "../bonus/image/coin2.xpm", \
					&data->width, &data->height);
	data->coin3 = mlx_xpm_file_to_image(data->mlx, "../bonus/image/coin3.xpm", \
					&data->width, &data->height);
	data->coin4 = mlx_xpm_file_to_image(data->mlx, "../bonus/image/coin4.xpm", \
					&data->width, &data->height);
	data->coin5 = mlx_xpm_file_to_image(data->mlx, "../bonus/image/coin5.xpm", \
					&data->width, &data->height);
	data->coin6 = mlx_xpm_file_to_image(data->mlx, "../bonus/image/coin6.xpm", \
					&data->width, &data->height);
	data->coin7 = mlx_xpm_file_to_image(data->mlx, "../bonus/image/coin7.xpm", \
					&data->width, &data->height);
}

void	add_image_xpm(t_data *data)
{
	data->wall = mlx_xpm_file_to_image(data->mlx, "../bonus/image/wall.xpm", \
					&data->width, &data->height);
	data->ground = mlx_xpm_file_to_image(data->mlx, \
					"../bonus/image/ground.xpm", &data->width, &data->height);
	data->player = mlx_xpm_file_to_image(data->mlx, \
					"../bonus/image/player.xpm", &data->width, &data->height);
	data->dor1 = mlx_xpm_file_to_image(data->mlx, \
					"../bonus/image/dor1.xpm", &data->width, &data->height);
	data->dor2 = mlx_xpm_file_to_image(data->mlx, \
					"../bonus/image/dor2.xpm", &data->width, &data->height);
	data->player_left = mlx_xpm_file_to_image(data->mlx, \
				"../bonus/image/player_left.xpm", &data->width, &data->height);
	data->enemy = mlx_xpm_file_to_image(data->mlx, \
				"../bonus/image/enemy.xpm", &data->width, &data->height);
	ft_mlx_coin(data);
}

void	ft_mlx_put_img_in_wind(t_data *data, int x)
{
	if (data->map[data->i][data->j] == 'C' && x % 7 == 3)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->coin4, \
			data->w, data->i * IMG_SIZE);
	if (data->map[data->i][data->j] == 'C' && x % 7 == 4)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->coin7, \
			data->w, data->i * IMG_SIZE);
	if (data->map[data->i][data->j] == 'C' && x % 7 == 5)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->coin6, \
			data->w, data->i * IMG_SIZE);
	if (data->map[data->i][data->j] == 'C' && x % 7 == 6)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->coin7, \
			data->w, data->i * IMG_SIZE);
}

void	ft_put_img_bonus(t_data *data)
{
	static int	x;

	data->m = 0;
	while (data->m < 30000)
		data->m++;
	if (data->map[data->i][data->j] == 'C' && x % 7 == 0)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->coin1, \
			data->w, data->i * IMG_SIZE);
	if (data->map[data->i][data->j] == 'C' && x % 7 == 1)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->coin2, \
			data->w, data->i * IMG_SIZE);
	if (data->map[data->i][data->j] == 'C' && x % 7 == 2)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->coin3, \
			data->w, data->i * IMG_SIZE);
	data->m = 0;
	while (data->m < 30000)
		data->m++;
	ft_mlx_put_img_in_wind(data, x);
	x++;
}
