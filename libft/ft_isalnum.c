/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:48:03 by taredfor          #+#    #+#             */
/*   Updated: 2021/08/26 16:48:04 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	ch;

	ch = 1;
	if ((47 < c && c < 58) || (64 < c && c < 91) || (96 < c && c < 123))
		return (ch);
	return (0);
}