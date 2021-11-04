/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelena <ddelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:54:09 by ddelena           #+#    #+#             */
/*   Updated: 2021/11/04 20:52:31 by ddelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_step_printer(t_map *map)
{
	char	*str;

	str = ft_itoa(map->steps);
	ft_put_image('1', map, 0, 1);
	ft_put_image('1', map, 0, 0);
	mlx_string_put(map->mlx, map->new_window, 10, 20, 0xadff2f, "Steps: ");
	mlx_string_put(map->mlx, map->new_window, 80, 20, 0x9acd32, str);
	ft_putstr_fd("Steps: ", 1);
	ft_putendl_fd(str, 1);
	free(str);
}

int	ft_close(t_map *map, char mes_code)
{
	int	res;

	mlx_destroy_window(map->mlx, map->new_window);
	if (mes_code == 'C')
		ft_putendl_fd("You closed the window", 1);
	else if (mes_code == 'W')
	{
		res = fork();
		if (res == 0)
		{
			system(" kill $(ps | grep tea | head -n 1 | awk '{print $1}')");
			system("afplay sounds/kotik.mp3");
			exit(0);
		}
		ft_putendl_fd("You win", 1);
	}
	else if (mes_code == 'D')
		ft_putendl_fd("You were eaten", 1);
	exit(EXIT_SUCCESS);
}

void	ft_moving(t_map *map, int x, int y)
{
	map->str[map->pos_y][map->pos_x] = '0';
	ft_put_image('0', map, map->pos_y, map->pos_x);
	map->str[map->pos_y + y][map->pos_x + x] = 'P';
	ft_put_image('P', map, map->pos_y + y, map->pos_x + x);
	map->steps++;
	ft_step_printer(map);
}

void	ft_lets_moving(t_map *map, int x, int y)
{
	int	res;

	if (map->str[map->pos_y + y][map->pos_x + x] == 'D')
		ft_close(map, 'D');
	else if (map->str[map->pos_y + y][map->pos_x + x] == 'E' \
			&& map->collect == 0)
		ft_close(map, 'W');
	else if (map->str[map->pos_y + y][map->pos_x + x] == 'C')
	{
		res = fork();
		if (res == 0)
		{
			system(" kill $(ps | grep tea | head -n 1 | awk '{print $1}')");
			system("afplay sounds/tea.mp3");
			exit(0);
		}
		ft_moving(map, x, y);
		map->collect = map->collect - 1;
		if (map->collect == 0)
			ft_exit(map);
	}
	else if (map->str[map->pos_y + y][map->pos_x + x] == '0')
		ft_moving(map, x, y);
}

int	key_h(int key_code, t_map *map)
{
	if (key_code == 13)
		ft_lets_moving(map, 0, -1);
	else if (key_code == 1)
		ft_lets_moving(map, 0, 1);
	else if (key_code == 0)
		ft_lets_moving(map, -1, 0);
	else if (key_code == 2)
		ft_lets_moving(map, 1, 0);
	else if (key_code == 53)
		ft_close(map, 'C');
	return (0);
}
