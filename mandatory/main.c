/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:55:46 by ibenmain          #+#    #+#             */
/*   Updated: 2022/04/13 05:28:14 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->is_left = 0;
	if (ac != 2)
		return (0);
	if (ft_check_error(av[1]))
		ft_print_message_error("Wrong name of map\n");
	data->count_mov = 0;
	data->count_line = ft_map_size(av[1]);
	data->map = ft_creat_map(av[1], data->count_line);
	ft_check_wall_map(data->map, data->count_line);
	ft_check_rl_map(data->map, data->count_line);
	ft_check_rectangle(data->map, data->count_line);
	ft_check_error_inside_map(data->map, data->count_line);
	ft_check_player(data->map, data->count_line, data);
	ft_check_collectible(data->map, data->count_line, data);
	ft_check_exit(data->map, data->count_line);
	ft_mlx(data->map, data->count_line, data);
	add_image_xpm(data);
	add_img_to_window(data);
	loop_images(data);
	ft_free(data);
	return (0);
}
