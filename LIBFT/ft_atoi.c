/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:25:53 by lrichard          #+#    #+#             */
/*   Updated: 2021/02/02 16:37:53 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	pos;
	int	nb;

	i = 0;
	nb = 0;
	pos = 1;
	while (nptr[i] == 32 || (nptr[i] > 8 && nptr[i] < 14))
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			pos *= -1;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		nb = nb * 10 + nptr[i] - 48;
		i++;
	}
	return (nb * pos);
}
