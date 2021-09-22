/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 23:05:01 by taredfor          #+#    #+#             */
/*   Updated: 2021/09/16 23:05:09 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_error("not enought arguments");
	if (argc > 2)
		ft_error("a lot of argumnets");
	if (ft_strrchr(argv[1], '.'))
	{
		if (ft_strcmp(ft_strrchr(argv[1], '.'), ".ber") != 0)
			ft_error("inncorrect arguments");
	}
	else
		ft_error("not arguments");
	so_long(argv[1]);
	return (0);
}
