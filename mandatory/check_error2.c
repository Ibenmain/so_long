/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:46:42 by ibenmain          #+#    #+#             */
/*   Updated: 2022/04/03 16:48:06 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_player(char	**map, int count_line, t_data *data)
{
	int		i;
	int		j;
	int		player;

	i = 0;
	player = 0;
	while (i < count_line -1)
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (map[i][j] == 'P')
			{
				player++;
				data->pos_i = i;
				data->pos_j = j;
			}
			j++;
		}
		i++;
	}
	if (player != 1)
		ft_print_message_error("you must have one player\n");
}

void	ft_check_collectible(char	**map, int count_line, t_data *data)
{
	int		i;
	int		j;

	i = 0;
	data->coll = 0;
	while (i < count_line - 1)
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (map[i][j] == 'C')
				data->coll++;
			j++;
		}
		i++;
	}
	if (data->coll == 0)
		ft_print_message_error("collectable doesn't exist\n");
}

void	ft_check_exit(char	**map, int count_line)
{
	int		i;
	int		j;
	int		exit;

	i = 0;
	exit = 0;
	while (i < count_line - 1)
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (exit == 0)
		ft_print_message_error("exit doesn't exist\n");
}
