/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 22:44:01 by taredfor          #+#    #+#             */
/*   Updated: 2021/09/16 22:57:23 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_width_map(char *str, t_struct *map)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		ft_error("nothing read");
	i = 1;
	while (i == 1)
	{
		i = get_next_line(fd, &line);
		free(line);
		map->width += 1;
	}
	if (i == -1)
		ft_error("wasn't nothing read");
	close(fd);
}

void	ft_map_parser(char *str, t_struct *map)
{
	int		fd;
	int		i;
	int		it;
	char	*line;

	it = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		ft_error("nothing read");
	i = 1;
	map->str = ft_calloc(map->width + 1, sizeof(char *));
	while (i == 1)
	{
		i = get_next_line(fd, &line);
		map->str[it] = ft_strdup(line);
		free(line);
		it++;
	}
	if (i == -1)
		ft_error("GNL error");
	close(fd);
}

void	structure_of_map(char *str, t_struct *map)
{
	int	i;
	int	ln;

	i = 0;
	ln = (int)ft_strlen(str);
	if (ln != map->len)
		ft_error("Error: shape of the map");
	if (str[0] != '1' || str[ln - 1] != '1')
		ft_error("Error: Map extreme values error");
	while (str[i])
	{
		if (str[i] == 'C')
			map->collect += 1;
		else if (str[i] == 'E')
			map->exit += 1;
		else if (str[i] == 'P')
			map->position += 1;
		else if (str[i] == '1' || str[i] == '0' \
			|| str[i] == 'D')
			;
		else
			ft_error("Error: incorrect symbols of the map");
		i++;
	}
}

void	first_and_last_str_of_map(t_struct *map)
{
	int	i;
	int	ln;

	ln = (int)ft_strlen(map->str[map->width - 1]);
	if (ln != map->len)
		ft_error("Error: shape of the map");
	i = 0;
	while (map->str[0][i])
	{
		if (map->str[0][i] != '1')
			ft_error("Error: incorrect symbols of the map");
		i++;
	}
	i = 0;
	while (map->str[map->width - 1][i])
	{
		if (map->str[map->width - 1][i] != '1')
			ft_error("Error: incorrect symbols last str of the map");
		i++;
	}
}

void	map_validate(t_struct *map)
{
	int	i;

	map->len = (int)ft_strlen(map->str[0]);
	i = 1;
	first_and_last_str_of_map(map);
	while (i <= map->width - 1)
	{
		structure_of_map(map->str[i], map);
		i++;
	}
	if (map->position != 1 || map->collect == 0 || map->exit == 0)
		ft_error("Error: incorrect meaning Position or Collect or Exit");
	if (map->width > 17 || map->len > 39)
		ft_error("Error: reduce map parameters");
}
