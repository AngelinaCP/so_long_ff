/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelena <ddelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:54:35 by ddelena           #+#    #+#             */
/*   Updated: 2021/11/04 20:52:31 by ddelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_exit(t_map *map)
{
	int	i;
	int	k;

	i = 0;
	while (map->str[i])
	{
		k = 0;
		while (map->str[i][k])
		{
			if (map->str[i][k] == 'E')
				ft_put_image('E', map, i, k);
			i++;
		}
		k++;
	}
}

void	put_simple_images(char symbol, t_map *map)
{
	if (symbol == '1')
		map->img = mlx_xpm_file_to_image(map->mlx, map->img_wall, \
			&map->img_height, &map->img_width);
	if (symbol == '0')
		map->img = mlx_xpm_file_to_image(map->mlx, map->img_earth, \
			&map->img_height, &map->img_width);
	if (symbol == 'C')
	{
		map->img = mlx_xpm_file_to_image(map->mlx, map->img_collect, \
			&map->img_height, &map->img_width);
	}
	if (symbol == 'E')
	{
		if (map->collect != 0)
			map->img = mlx_xpm_file_to_image(map->mlx, map->img_exitt, \
				&map->img_height, &map->img_width);
		else
		{
			map->img = mlx_xpm_file_to_image(map->mlx, map->img_exitt2, \
				&map->img_height, &map->img_width);
		}
	}
}

void	put_animation(char symbol, t_map *map)
{
	if (symbol == 'P')
	{
		map->img = mlx_xpm_file_to_image(map->mlx, map->img_enem, \
			&map->img_height, &map->img_width);
	}
	if (symbol == 'X')
	{
		map->img = mlx_xpm_file_to_image(map->mlx, map->img_enemy, \
			&map->img_height, &map->img_width);
	}
	if (symbol == 'D')
	{
		map->img = mlx_xpm_file_to_image(map->mlx, map->img_enemy_2, \
			&map->img_height, &map->img_width);
	}
}

void	ft_put_image(char symbol, t_map *map, int y, int x)
{
	if (symbol == '1' || symbol == '0' || symbol == 'C' || symbol == 'E')
		put_simple_images(symbol, map);
	if (symbol == 'P' || symbol == 'X' || symbol == 'D' )
	{
		if (symbol == 'P')
		{
			map->pos_x = x;
			map->pos_y = y;
		}
		put_animation(symbol, map);
	}
	mlx_put_image_to_window(map->mlx, map->new_window, map->img, \
		x * map->img_height, y * map->img_width);
}

void	ft_map_filling(t_map *map)
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
