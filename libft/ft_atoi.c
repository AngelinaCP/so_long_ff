/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelena <ddelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 12:43:43 by ddelena           #+#    #+#             */
/*   Updated: 2021/04/29 21:24:40 by ddelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_space(int c)
{
	return (c == ' ' || c == '\t' || c == '\f'
		|| c == '\r' || c == '\n' || c == '\v');
}

int	ft_atoi(const char *str)
{
	int		i;
	int		j;
	long	k;

	k = 0;
	i = 0;
	j = 1;
	while (ft_space(str[i]))
		i++;
	if (str[i] == '-' )
		j = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (k > 2147483647 && j == 1)
			return (-1);
		if (k < -2147483648)
			return (0);
		k = (k * 10) + (str[i] - '0');
		i++;
	}
	return (k * j);
}
