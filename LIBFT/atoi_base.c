/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:30:03 by lrichard          #+#    #+#             */
/*   Updated: 2021/04/18 18:30:31 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	base_index(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
		if (base[i] == c)
			return (i);
	return (-1);
}

int	atoi_base(char *str, char *base)
{
	int				i;
	int				nb;
	int				pos;
	int				blen;

	i = 0;
	nb = 0;
	pos = 1;
	blen = ft_strlen(base);
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	while (str[i] == 43 || str[i] == 45)
		if (str[i++] == 45)
			pos *= -1;
	while (base_index(str[i], base) != -1)
	{
		nb *= blen;
		nb += base_index(str[i], base);
		i++;
	}
	return (nb * pos);
}
