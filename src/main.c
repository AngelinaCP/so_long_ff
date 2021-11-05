/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelena <ddelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 22:26:13 by ddelena           #+#    #+#             */
/*   Updated: 2021/11/05 22:26:14 by ddelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_arg(int argc, char **argv)
{
	if (argc != 2)
		ft_error("Wrong number of arguments\n");
	if (ft_strrchr(argv[1], '.'))
	{
		if (ft_strcmp(ft_strrchr(argv[1], '.'), ".ber") != 0)
			ft_error("Wrong map extension\n");
	}
	else
		ft_error("Wrong argument\n");
}

void	ft_init_game(t_struct *map)
{
	map->mlx = mlx_init();
	map->new_window = mlx_new_window(map->mlx, map->len * 64, \
	map->width * 64, "so_long");
	ft_map_filling(map);
	mlx_hook(map->new_window, 2, 0, key_h, map);
	mlx_hook(map->new_window, 17, 1L << 2, ft_close_x, map);
	mlx_loop_hook(map->mlx, ft_patrol_animation, map);
	mlx_loop(map->mlx);
}

int	main(int argc, char **argv)
{
	t_struct	map;

	ft_init_map(&map);
	check_arg(argc, argv);
	ft_map_parser(argv[1], &map);
	map_validate(&map);
	ft_init_game(&map);
	return (0);
}
