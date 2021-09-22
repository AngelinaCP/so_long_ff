/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 23:02:00 by taredfor          #+#    #+#             */
/*   Updated: 2021/09/16 23:04:30 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_exit(t_struct *map)
{
	int	w;
	int	l;

	w = 0;
	while (map->str[w])
	{
		l = 0;
		while (map->str[w][l])
		{
			if (map->str[w][l] == 'E')
				ft_put_image('E', map, w, l);
			l++;
		}
		w++;
	}
}

void	ft_put_passive_images(char symbol, t_struct *map)
{
	if (symbol == '1')
		map->img = mlx_xpm_file_to_image(map->mlx, map->img_wall, \
			&map->img_height, &map->img_width);
	if (symbol == '0')
		map->img = mlx_xpm_file_to_image(map->mlx, map->img_earth, \
			&map->img_height, &map->img_width);
	if (symbol == 'C')
		map->img = mlx_xpm_file_to_image(map->mlx, map->img_collect, \
			&map->img_height, &map->img_width);
	if (symbol == 'E')
	{
		if (map->collect != 0)
			map->img = mlx_xpm_file_to_image(map->mlx, map->img_helic_c, \
				&map->img_height, &map->img_width);
		else
			map->img = mlx_xpm_file_to_image(map->mlx, map->img_helic_o, \
				&map->img_height, &map->img_width);
	}
}

void	ft_putactive_images(char symbol, t_struct *map)
{
	if (symbol == 'P')
		map->img = mlx_xpm_file_to_image(map->mlx, map->img_solders, \
			&map->img_height, &map->img_width);
	if (symbol == 'X')
		map->img = mlx_xpm_file_to_image(map->mlx, map->img_enemy, \
			&map->img_height, &map->img_width);
	if (symbol == 'D')
		map->img = mlx_xpm_file_to_image(map->mlx, map->img_enemy_2, \
			&map->img_height, &map->img_width);
}

void	ft_put_image(char symbol, t_struct *map, int y, int x)
{
	if (symbol == '1' || symbol == '0' || symbol == 'C' || symbol == 'E')
		ft_put_passive_images(symbol, map);
	if (symbol == 'P' || symbol == 'X' || symbol == 'D' )
	{
		if (symbol == 'P')
		{
			map->pos_x = x;
			map->pos_y = y;
		}
		ft_putactive_images(symbol, map);
	}
	mlx_put_image_to_window(map->mlx, map->new_window, map->img, \
		x * map->img_height, y * map->img_width);
}

void	ft_map_filling(t_struct *map)
{
	int	w;
	int	l;

	w = 0;
	while (map->str[w])
	{
		l = 0;
		while (map->str[w][l])
		{
			ft_put_image(map->str[w][l], map, w, l);
			l++;
		}
		w++;
	}
}
