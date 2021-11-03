

#include "../include/so_long.h"

void	ft_init_game(t_struct *map)
{
	map->mlx = mlx_init();
	map->new_window = mlx_new_window(map->mlx, map->len * 64, \
		map->width * 64, "so_long");
	ft_map_filling(map);
	mlx_hook(map->new_window, 2, 0, ft_lets_push, map);
	mlx_hook(map->new_window, 17, 1L << 2, ft_close_x, map);
	mlx_loop_hook(map->mlx, ft_patrol_animation, map);
	mlx_loop(map->mlx);
}

void	so_long(char *str)
{
	t_struct	map;

	ft_init_map(&map);
	ft_width_map(str, &map);
	ft_map_parser(str, &map);
	map_validate(&map);
	ft_init_game(&map);
}
