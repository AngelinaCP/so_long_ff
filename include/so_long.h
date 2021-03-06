/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelena <ddelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:54:06 by ddelena           #+#    #+#             */
/*   Updated: 2021/11/05 22:30:01 by ddelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include <time.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>

typedef struct s_struct
{
	char	**str;
	int		len;
	int		width;
	int		position;
	int		wall;
	int		goal;
	int		collect;
	int		exit;
	int		pos_x;
	int		pos_y;
	void	*img_enem;
	void	*img_wall;
	void	*img_grass;
	void	*img_earth;
	void	*img_collect;
	void	*img_exitt;
	void	*img_exitt2;
	void	*img_enemy;
	void	*img_enemy_2;
	void	*victim;
	int		img_height;
	int		img_width;
	int		time;
	int		steps;
	int		frame;
	void	*mlx;
	void	*new_window;
	int		x;
	int		y;
	void	*img;

}	t_struct;

int		main(int argc, char **argv);
void	so_long(char *str);
void	ft_width_map(char *str, t_struct *map);
void	ft_init_map(t_struct *map);
void	ft_map_parser(char *str, t_struct *map);
void	map_validate(t_struct *map);
void	first_and_last_str_of_map(t_struct *map);
void	structure_of_map(char *str, t_struct *map);
int		key_h(int key_code, t_struct *map);
void	ft_init_game(t_struct *map);
char	*check_for_image(char *str);
void	ft_map_filling(t_struct *map);
void	ft_put_image(char symbol, t_struct *map, int x, int y);
void	put_simple_images(char symbol, t_struct *map);
void	put_animation(char symbol, t_struct *map);
void	ft_exit(t_struct *map);
void	ft_step_printer(t_struct *map);
int		ft_close(t_struct *map, char mes_code);
void	ft_moving(t_struct *map, int x, int y);
void	ft_lets_moving(t_struct *map, int x, int y);
int		ft_patrol_animation(t_struct *map);
int		ft_close_x(t_struct *map);
void	ft_error(char *str);

#endif
