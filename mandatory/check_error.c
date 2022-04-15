/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:02:18 by ibenmain          #+#    #+#             */
/*   Updated: 2022/03/23 19:16:29 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_error(char *file_name)
{
	int		len;

	len = ft_strlen(file_name);
	if (file_name[len - 4] == '.' && file_name[len - 3] == 'b'
		&& file_name[len - 2] == 'e' && file_name[len - 1] == 'r')
		return (0);
	return (1);
}

void	ft_check_wall_map(char **map, int nb_line)
{
	int		j;

	j = 0;
	while (map[0][j] != '\n')
	{
		if (map[0][j] != '1')
			ft_print_message_error("map must be surrunder by walls\n");
		j++;
	}
	j = 0;
	while (map[nb_line - 1][j])
	{
		if (map[nb_line - 1][j] != '1')
			ft_print_message_error("map must be surrunder by walls\n");
		j++;
	}
}

void	ft_check_rl_map(char **map, int nb_line)
{
	int		i;

	i = 0;
	while (i < nb_line)
	{
		if (map[i][0] != '1')
			ft_print_message_error("map must be surrunder by walls\n");
		i++;
	}
	i = 0;
	while (i < nb_line)
	{
		if (map[i][ft_strlen(map[i]) - 2] != '1')
			ft_print_message_error("map must be surrunder by walls\n");
		i++;
	}
}

void	ft_check_rectangle(char	**map, int count_line)
{
	int		i;
	int		size_line;

	i = 0;
	size_line = ft_strlen(map[i]);
	while (i < count_line - 1)
	{
		if (size_line != ft_strlen(map[i]))
			ft_print_message_error("map isn't rectangular\n");
		i++;
	}
	if (size_line - 1 != ft_strlen(map[i]))
		ft_print_message_error("map isn't rectangular\n");
}

void	ft_check_error_inside_map(char	**map, int count_line)
{
	int		i;
	int		j;

	i = 0;
	while (i < count_line)
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != '\n')
				ft_print_message_error("Invalid character\n");
			j++;
		}
		i++;
	}
}
