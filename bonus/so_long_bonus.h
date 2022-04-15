/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:25:28 by ibenmain          #+#    #+#             */
/*   Updated: 2022/04/13 23:49:01 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# define BUFFER_SIZE 1024
# define IMG_SIZE 50

typedef struct s_data{
	int		i;
	int		j;
	int		w;
	int		x;
	void	*img;
	int		width;
	int		height;
	void	*wall;
	void	*ground;
	void	*player;
	void	*player_left;
	void	*coin1;
	void	*coin2;
	void	*coin3;
	void	*coin4;
	void	*coin5;
	void	*coin6;
	void	*coin7;
	void	*dor1;
	void	*dor2;
	void	*exit;
	void	*enemy;
	int		m;
	void	*mlx;
	void	*mlx_win;
	int		count_line;
	char	**map;
	int		pos_i;
	int		pos_j;
	int		pos_h_i;
	int		pos_h_j;
	int		nb_coin;
	int		coll;
	int		count_mov;
	char	*str;
	char	*nb_mov;
	short	is_left;
}	t_data;

int		ft_check_error(char *str);
char	*get_next_line(int fd);
int		find_new_line(char *string);
char	*get_line(char *str);
char	*get_rest(char *str);
char	*ft_substr(char *s, int start, int len);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
int		ft_map_size(char *file_name);
void	ft_print_message_error(char *str);
char	**ft_creat_map(char *map_name, int nb_line);
void	ft_check_wall_map(char **map, int nb_line);
void	ft_check_rl_map(char **map, int nb_line);
void	ft_check_rectangle(char	**map, int count_line);
void	ft_check_error_inside_map(char	**map, int count_line);
void	ft_check_player(char	**map, int count_line, t_data *data);
void	ft_check_collectible(char	**map, int count_line, t_data *data);
void	ft_check_exit(char	**map, int count_line);
int		ft_mlx(char **map, int nb_line, t_data *data);
void	ft_mlx_image(char **map, int nb_line);
void	add_image_xpm(t_data *data);
int		render(t_data *data);
int		add_img_to_window(t_data *data);
void	ft_put_image_to_window(t_data *data);
int		key_hook(int keycode, t_data *data);
int		ft_mov_up(t_data *data);
void	loop_images(t_data *data);
int		destory_win(t_data *data);
void	ft_destroy_coin(t_data *data);
char	*ft_itoa(int n);
void	ft_free(t_data *data);
int		handl_keyrelease(t_data *data);
char	*ft_join(char *s1, char *s2);
void	ft_mlx_coin(t_data *data);
void	ft_put_img_bonus(t_data *data);
void	ft_print_movement(t_data *data);
void	ft_mlx_put_img_in_wind(t_data *data, int x);
void	ft_enemy(t_data *data);
int		ft_enemy_up(t_data *data);
int		ft_enemy_down(t_data *data);
int		ft_enemy_left(t_data *data);
int		ft_enemy_right(t_data *data);
void	ft_check_enemy(char	**map, int count_line, t_data *data);
void	ft_free(t_data *data);
#endif