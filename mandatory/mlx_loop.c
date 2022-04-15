/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:52:19 by ibenmain          #+#    #+#             */
/*   Updated: 2022/04/13 07:12:04 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handl_keyrelease(t_data *data)
{
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->player);
	mlx_destroy_image(data->mlx, data->player_left);
	mlx_destroy_image(data->mlx, data->ground);
	mlx_destroy_image(data->mlx, data->dor1);
	mlx_destroy_image(data->mlx, data->coin);
	mlx_destroy_window(data->mlx, data->mlx_win);
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
