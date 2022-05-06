/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:07:01 by ibenmain          #+#    #+#             */
/*   Updated: 2022/05/05 12:55:35 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_mov_up(t_data *data)
{
	if (data->map[data->pos_i - 1][data->pos_j] == '1'
		|| (data->map[data->pos_i - 1][data->pos_j] == 'E'
			&& data->coll != data->nb_coin))
		return (0);
	data->count_mov++;
	ft_printf("count of movement : %d\n", data->count_mov);
	if (data->map[data->pos_i - 1][data->pos_j] == '0')
	{
		data->map[data->pos_i--][data->pos_j] = '0';
		data->map[data->pos_i][data->pos_j] = 'P';
	}
	else if (data->map[data->pos_i - 1][data->pos_j] == 'C')
	{
		data->map[data->pos_i--][data->pos_j] = '0';
		data->map[data->pos_i][data->pos_j] = 'P';
		data->nb_coin++;
	}
	else if (data->map[data->pos_i - 1][data->pos_j] == 'E')
	{
		if (data->coll == data->nb_coin)
			ft_print_message_error("GAME OVER");
	}
	return (0);
}

int	ft_mov_left(t_data *data)
{
	if (data->map[data->pos_i][data->pos_j - 1] == '1'
		|| (data->map[data->pos_i][data->pos_j - 1] == 'E'
			&& data->coll != data->nb_coin))
		return (0);
	data->count_mov++;
	ft_printf("count of movement : %d\n", data->count_mov);
	if (data->map[data->pos_i][data->pos_j - 1] == '0')
	{
		data->map[data->pos_i][data->pos_j--] = '0';
		data->map[data->pos_i][data->pos_j] = 'P';
	}
	else if (data->map[data->pos_i][data->pos_j - 1] == 'C')
	{
		data->map[data->pos_i][data->pos_j--] = '0';
		data->map[data->pos_i][data->pos_j] = 'P';
		data->nb_coin++;
	}
	else if (data->map[data->pos_i][data->pos_j - 1] == 'E')
	{
		if (data->coll == data->nb_coin)
			ft_print_message_error("GAME OVER");
	}
	return (0);
}

int	ft_mov_down(t_data *data)
{
	if (data->map[data->pos_i + 1][data->pos_j] == '1'
		|| (data->map[data->pos_i + 1][data->pos_j] == 'E'
			&& data->coll != data->nb_coin))
		return (0);
	data->count_mov++;
	ft_printf("count of movement : %d\n", data->count_mov);
	if (data->map[data->pos_i + 1][data->pos_j] == '0')
	{
		data->map[data->pos_i++][data->pos_j] = '0';
		data->map[data->pos_i][data->pos_j] = 'P';
	}
	else if (data->map[data->pos_i + 1][data->pos_j] == 'C')
	{
		data->map[data->pos_i++][data->pos_j] = '0';
		data->map[data->pos_i][data->pos_j] = 'P';
		data->nb_coin++;
	}
	else if (data->map[data->pos_i][data->pos_j - 1] == 'E')
	{
		if (data->coll == data->nb_coin)
			ft_print_message_error("GAME OVER");
	}
	return (0);
}

int	ft_mov_right(t_data *data)
{
	if (data->map[data->pos_i][data->pos_j + 1] == '1'
		|| (data->map[data->pos_i][data->pos_j + 1] == 'E'
		&& data->coll != data->nb_coin))
		return (0);
	data->count_mov++;
	ft_printf("count of movement : %d\n", data->count_mov);
	if (data->map[data->pos_i][data->pos_j + 1] == '0')
	{
		data->map[data->pos_i][data->pos_j++] = '0';
		data->map[data->pos_i][data->pos_j] = 'P';
	}
	else if (data->map[data->pos_i][data->pos_j + 1] == 'C')
	{
		data->map[data->pos_i][data->pos_j++] = '0';
		data->map[data->pos_i][data->pos_j] = 'P';
		data->nb_coin++;
	}
	else if (data->map[data->pos_i][data->pos_j + 1] == 'E')
	{
		if (data->coll == data->nb_coin)
			ft_print_message_error("GAME OVER");
	}
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 13)
		ft_mov_up(data);
	if (keycode == 0)
	{
		data->is_left = 1;
		ft_mov_left(data);
	}
	if (keycode == 1)
		ft_mov_down(data);
	if (keycode == 2)
	{
		data->is_left = 0;
		ft_mov_right(data);
	}
	if (keycode == 53)
		ft_free(data);
	return (0);
}
