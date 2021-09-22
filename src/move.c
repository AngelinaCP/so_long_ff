/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 22:57:42 by taredfor          #+#    #+#             */
/*   Updated: 2021/09/16 23:01:27 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_step_printer(t_struct *map)
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

int	ft_close(t_struct *map, char mes_code)
{
	mlx_destroy_window(map->mlx, map->new_window);
	if (mes_code == 'C')
		ft_putendl_fd("You closed window", 1);
	else if (mes_code == 'W')
		ft_putendl_fd("You win", 1);
	else if (mes_code == 'D')
		ft_putendl_fd("You were killed patrol", 1);
	exit(EXIT_SUCCESS);
}

void	ft_moving(t_struct *map, int x, int y)
{
	map->str[map->pos_y][map->pos_x] = '0';
	ft_put_image('0', map, map->pos_y, map->pos_x);
	map->str[map->pos_y + y][map->pos_x + x] = 'P';
	ft_put_image('P', map, map->pos_y + y, map->pos_x + x);
	map->steps++;
	ft_step_printer(map);
}

void	ft_lets_moving(t_struct *map, int x, int y)
{
	if (map->str[map->pos_y + y][map->pos_x + x] == 'D')
		ft_close(map, 'D');
	else if (map->str[map->pos_y + y][map->pos_x + x] == 'E' \
			&& map->collect == 0)
		ft_close(map, 'W');
	else if (map->str[map->pos_y + y][map->pos_x + x] == 'C')
	{
		ft_moving(map, x, y);
		map->collect = map->collect - 1;
		if (map->collect == 0)
			ft_exit(map);
	}
	else if (map->str[map->pos_y + y][map->pos_x + x] == '0')
		ft_moving(map, x, y);
}

int	ft_lets_push(int key_code, t_struct *map)
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
