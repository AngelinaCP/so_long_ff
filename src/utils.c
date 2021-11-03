#include "../include/so_long.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(EXIT_FAILURE);
}

char	*check_for_image(char *str)
{
	if (open(str, O_RDONLY) < 0)
		ft_error("Error: Image not found");
	return (str);
}

void	ft_init_map(t_struct *map)
{
	map->len = 0;
	map->width = 0;
	map->exit = 0;
	map->collect = 0;
	map->position = 0;
	map->img_height = 64;
	map->img_width = 64;
	map->steps = 0;
	map->time = 0;
	map->frame = 0;
	map->img_solders = check_for_image("./images/tiger_right.xpm");
	map->img_wall = check_for_image("./images/border.xpm");
	map->img_grass = check_for_image("./images/grass.xpm");
	map->img_earth = check_for_image("./images/ground.xpm");
	map->img_collect = check_for_image("./images/enemy.xpm");
	map->img_helic_c = check_for_image("./images/helic_c.xpm");
	map->img_helic_o = check_for_image("./images/helic_o.xpm");
	map->img_enemy = check_for_image("./images/enemy_1.xpm");
	map->img_enemy_2 = check_for_image("./images/enemy_2.xpm");
}

int	ft_patrol_animation(t_struct *map)
{
	int	w;
	int	l;

	w = 0;
	if (((double)(clock)()) / CLOCKS_PER_SEC - map->time >= (double)1 / 10)
	{
		map->frame++;
		map->time = (double)(clock()) / CLOCKS_PER_SEC;
	}
	if (map->frame > 49)
		map->frame = 0;
	while (map->str[w])
	{
		l = 0;
		while (map->str[w][l])
		{
			if (map->str[w][l] == 'D' && map->frame > 24)
				ft_put_image('D', map, w, l);
			else if (map->str[w][l] == 'D' && map->frame <= 24)
				ft_put_image('X', map, w, l);
			l++;
		}
		w++;
	}
	return (0);
}

int	ft_close_x(t_struct *map)
{
	mlx_destroy_window(map->mlx, map->new_window);
	ft_putendl_fd("You closed window", 1);
	exit(EXIT_SUCCESS);
}
