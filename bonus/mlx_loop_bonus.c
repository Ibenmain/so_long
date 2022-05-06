/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:52:19 by ibenmain          #+#    #+#             */
/*   Updated: 2022/05/05 13:46:11 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_destroy_coin(t_data *data)
{
	mlx_destroy_image(data->mlx, data->coin1);
	mlx_destroy_image(data->mlx, data->coin2);
	mlx_destroy_image(data->mlx, data->coin3);
	mlx_destroy_image(data->mlx, data->coin4);
	mlx_destroy_image(data->mlx, data->coin5);
	mlx_destroy_image(data->mlx, data->coin6);
	mlx_destroy_image(data->mlx, data->coin7);
}

int	handl_keyrelease(t_data *data)
{
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->player);
	mlx_destroy_image(data->mlx, data->player_left);
	mlx_destroy_image(data->mlx, data->ground);
	mlx_destroy_image(data->mlx, data->dor1);
	mlx_destroy_image(data->mlx, data->dor2);
	ft_destroy_coin(data);
	mlx_destroy_window(data->mlx, data->mlx_win);
	free(data->mlx);
	data->mlx_win = NULL;
	exit(0);
}

void	loop_images(t_data *data)
{
	mlx_loop_hook(data->mlx, &add_img_to_window, data);
	mlx_hook(data->mlx_win, 2, 1L, &key_hook, data);
	mlx_hook(data->mlx_win, 17, 1L, &handl_keyrelease, data);
	mlx_loop(data->mlx);
}
