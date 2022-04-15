/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:20:16 by ibenmain          #+#    #+#             */
/*   Updated: 2022/04/13 22:46:10 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_map_size(char *file_name)
{
	char	*line;
	int		fd;
	int		count_line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_print_message_error("can't open file\n");
	line = get_next_line(fd);
	if (!line)
		ft_print_message_error("Empty map\n");
	free(line);
	count_line = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		count_line++;
	}
	close(fd);
	return (count_line);
}

char	**ft_creat_map(char *map_name, int nb_line)
{
	char	**map;
	int		fd;
	int		i;

	map = (char **)malloc(sizeof(char *) * (nb_line + 1));
	if (!map)
		return (NULL);
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	i = -1;
	while (++i < nb_line)
		map[i] = get_next_line(fd);
	close(fd);
	return (map);
}

void	ft_free(t_data *data)
{
	free(data->map);
	free(data);
	exit(0);
}
